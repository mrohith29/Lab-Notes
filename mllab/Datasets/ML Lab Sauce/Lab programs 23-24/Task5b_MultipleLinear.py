
# Multiple Linear Regression
# Importing the libraries
import numpy as np
#import matplotlib.pyplot as plt
import pandas as pd
#from sklearn import cross_validation
# Importing the dataset
dataset = pd.read_csv('C:\\Users\\HP\Desktop\\ML DATA 2022-23\\Datasets\\50_Startups.csv')
X = dataset.iloc[:, :-1]
y = dataset.iloc[:, 4]
#Convert the column into categorical columns
states=pd.get_dummies(X['State'])
# Drop the state coulmn
X=X.drop('State',axis=1)
# concat the dummy variables
X=pd.concat([X,states],axis=1)
# Splitting the dataset into the Training set and Test set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state =0)
# Fitting Multiple Linear Regression to the Training set
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
regressor = LinearRegression()
regressor.fit(X_train, y_train)
# Predicting the Test set results
y_pred = regressor.predict(X_test)
from sklearn.metrics import r2_score
score=r2_score(y_test,y_pred)
print(score)
print('mean_sqrd_error is==',mean_squared_error(y_test,y_pred))
print('root_mean_squared error of is==',np.sqrt(mean_squared_error(y_test,y_pred)))