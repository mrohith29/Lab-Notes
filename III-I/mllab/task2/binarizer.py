from sklearn.preprocessing import Binarizer
import pandas as pd
import numpy as np

dataframe = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\diabetes.csv")
array = dataframe.values

x = array[:, 0:8]
y = array[:, 8]

bin = Binarizer(threshold=0.0).fit(x)
binX = bin.transform(x)

np.set_printoptions(precision=3)
print(binX[0:5, :])