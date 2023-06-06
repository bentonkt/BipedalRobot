import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_excel("MATLAB\\angles.xlsx")

series = df.HipRollR
series2 = df.HipRollL
time = df.time
plt.plot(series, time, "o")
plt.plot(series2, time, "o")
plt.axhline(5.02)
plt.show()

# Left leg is the most bent at 5.02


