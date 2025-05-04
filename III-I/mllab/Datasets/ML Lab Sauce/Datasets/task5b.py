import numpy as np
import pandas as pd
dataset = pd.read_csv(r'C:\Users\griet\Desktop\ML DATA 2022-23\Datasets\50_Startups.csv');
X = dataset.iloc[:,:-1]
Y = dataset.iloc[:,4]
states = pd.get_dummies(X['State'])
X = X.drop('State',axis=1)
X = pd.concat([X,states],axis = 1)
from sklearn.model_selection import train_test_split
X_train , X_test , Y_train , Y_test = train_test_split(X,Y,test_size=0.2, random_state = 0)
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
regressor = LinearRegression()
regressor.fit(X_train,Y_train)
y_pred = regressor.predict(X_test)
from sklearn.metrics import r2_score
score = r2_score(Y_test,y_pred)
print(score)
print('mean_sqrd_error is :',mean_squared_error(Y_test,y_pred))
print('root_mean_squared error of is :',np.sqrt(mean_squared_error(Y_test,y_pred)))

