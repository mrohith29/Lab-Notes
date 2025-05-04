from sklearn.preprocessing import StandardScaler
import pandas
import numpy
# data set link
# preparating of dataframe using the data at given link and defined columnslist 
dataframe = pandas.read_csv('C:\\Users\\HP\Desktop\\ML DATA 2022-23\\Datasets\\diabetes.csv', 
names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pedi', 'age', 'class'])
array = dataframe.values
print(array)
# separate array into input and output components
X = array[:, 0:8]
Y = array[:, 8]
scaler = StandardScaler().fit(X)
rescaledX = scaler.transform(X)
# summarize transformed data
numpy.set_printoptions(precision = 3)
print(rescaledX[0:5,:])