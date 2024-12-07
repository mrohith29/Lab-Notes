#importing utility modules 
import pandas as pd
import numpy as np
#from sklearn import cross_validation
from sklearn.metrics import mean_squared_error
# importing machine learning models for prediction
from sklearn.ensemble import GradientBoostingRegressor
col_names = ['pregnant', 'glucose', 'bp', 'skin', 'insulin', 'bmi', 'pedigree', 'age', 'label'] # load dataset
pima = pd.read_csv("C:\\Users\\HP\Desktop\\ML DATA 2022-23\\Datasets\\diabetes.csv", header=None, names=col_names) 
print(pima)
feature_cols = ['pregnant', 'insulin', 'bmi', 'age','glucose','bp']
X = pima[feature_cols] # Features 
y = pima.label # Target variable
# Splitting between train data into training and validation dataset
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20) # initializing the boosting module with default parameters
model = GradientBoostingRegressor()
# training the model on the train dataset 
model.fit(X_train, y_train)

# predicting the output on the test dataset 
y_pred = model.predict(X_test)
# printing the root mean squared error between real value and predicted value
from sklearn.metrics import r2_score 
print('score==',r2_score(y_test,y_pred))
print('mean_sqrd_error is==',mean_squared_error(y_test,y_pred)) 
print('root_mean_squared error of is==',np.sqrt(mean_squared_error(y_test,y_pred)))