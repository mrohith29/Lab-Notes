from sklearn.preprocessing import MinMaxScaler
import pandas as pd
import numpy as np

data = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\diabetes.csv")

array = data.values

x = array[:, 0:8]
y = array[:, 8]

minmax = MinMaxScaler(feature_range=(0,1))
rescaledx = minmax.fit_transform(x)

np.set_printoptions(precision=3)

print(rescaledx[0:10, :])