from sklearn.preprocessing import StandardScaler
import pandas as pd
import numpy
dataframe = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\diabetes.csv", names=['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pedi', 'age', 'class'])
array = dataframe.values
print(array)

x = array[:, 0:8]
y = array[:, 8]

scaler = StandardScaler().fit(x)

rescaledX = scaler.transform(x)

numpy.set_printoptions(precision=3)
print(rescaledX[0:5, :])