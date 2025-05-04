# importing libraries
import pandas
import scipy
import numpy
from sklearn.preprocessing import MinMaxScaler
names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pedi','age','class']
# preparating of dataframe using the data at given link and defined columns list
dataframe = pandas.read_csv('C:\\Users\\HP\Desktop\\ML DATA 2022-23\\Datasets\\diabetes.csv', 
names = names)
array = dataframe.values
# separate array into input and output components
X = array[:,0:8]
Y = array[:,8]
# initialising the MinMaxScaler
scaler = MinMaxScaler(feature_range=(0, 1))
# learning the statistical parameters for each of the data and transforming
rescaledX = scaler.fit_transform(X)
# summarize transformed data
numpy.set_printoptions(precision=2)
print(rescaledX[0:10,:])