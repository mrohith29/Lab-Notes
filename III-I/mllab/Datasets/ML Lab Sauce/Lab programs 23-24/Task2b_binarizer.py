# import libraries
from sklearn.preprocessing import Binarizer
import pandas
import numpy
names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pedi', 'age', 'class']
# preparating of dataframe using the data at given link and defined columns list
dataframe = pandas.read_csv('C:\\Users\\HP\Desktop\\ML DATA 2022-23\\Datasets\\diabetes.csv', names = 
names)
array = dataframe.values
# separate array into input and output components
X = array[:, 0:8]
Y = array[:, 8]
binarizer = Binarizer(threshold = 0.0).fit(X)
binaryX = binarizer.transform(X)
# summarize transformed data
numpy.set_printoptions(precision = 3)
print(binaryX[0:5,:])