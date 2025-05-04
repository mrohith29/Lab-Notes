import numpy as np
import pandas as pd
from sklearn.naive_bayes import GaussianNB
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score

play_tennise = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\PlayTennis.csv")
print(play_tennise.head())
number = LabelEncoder()

play_tennise['Outlook'] = number.fit_transform(play_tennise['Outlook'])
play_tennise['Temperature'] = number.fit_transform(play_tennise['Temperature'])
play_tennise['Humidity'] = number.fit_transform(play_tennise['Humidity'])
play_tennise['Wind'] = number.fit_transform(play_tennise['Wind'])
play_tennise['Play Tennis'] = number.fit_transform(play_tennise['Play Tennis'])

features = ['Outlook', 'Temperature', 'Humidity', 'Wind']
target = 'Play Tennis'
print(play_tennise.head())

from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(play_tennise[features], play_tennise[target], test_size=0.33, random_state=54)
model = GaussianNB()
model.fit(x_train, y_train)
pred = model.predict(x_test)
accuracy = accuracy_score(y_test, pred)
print(accuracy)
print(model.predict([[2,1,0,1]]))