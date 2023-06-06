import os
import pandas as pd
import numpy as np

MULTIPLIER = 100000

#Round all excel values to limit storage usage
import openpyxl as px

workbook = px.load_workbook('MATLAB\\angles.xlsx')
worksheet = workbook.active

for row in worksheet.iter_rows(min_row=2):
    for cell in row:
        if isinstance(cell.value, (int, float)):
            cell.value = round(cell.value, 5)

workbook.save('MATLAB\\RoundedAngles.xlsx')

# Convert excel into text file of arduino array
df = pd.read_excel('MATLAB\\RoundedAngles.xlsx', skiprows=1)
df.drop(df.columns[0], axis=1, inplace=True)
array = df.to_numpy()

# Time between steps is appproximately 1/500 secs

print(array.shape)
print(array[:2])

with open("AnglesMultiplied16ms.txt", "w") as file:
    for row in range(len(array)):
        if row % 8 == 0:
            file.write("{")
            for i in range(len(array[row])):
                if i == 0:
                    file.write(str(int(array[row][i] * MULTIPLIER)))
                else:
                    file.write(", " + str(int(array[row][i] * MULTIPLIER)))
            file.write("},\n")


'''
May have to invert right hip 3 values


'''