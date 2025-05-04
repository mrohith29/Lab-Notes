import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataset = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\50_Startups.csv")
print(dataset)
x = dataset.iloc[:, :-1]
y = dataset.iloc[:, 4]
states = pd.get_dummies(x['State'])
print(states)
x = x.drop('State', axis=1)
x = pd.concat([x, states], axis=1)
print(x)
# print(np.size(x), np.size(y))

from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=0)

from sklearn.linear_model import LinearRegression

regressor = LinearRegression()
regressor.fit(x_train, y_train)

y_pred = regressor.predict(x_test)

from sklearn.metrics import r2_score
score = r2_score(y_test, y_pred)
print(score)

from sklearn.metrics import mean_squared_error
print('Mean_sqrd_erro is === ', mean_squared_error(y_test, y_pred))
print('room_mean_squared error of is === ', np.sqrt(mean_squared_error(y_test, y_pred)))