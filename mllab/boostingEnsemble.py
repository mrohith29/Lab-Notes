import pandas as pd
import numpy as np
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.ensemble import GradientBoostingRegressor
from sklearn.model_selection import train_test_split

pima = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\diabetes.csv", names=["pregnant", 'glucose', 'bp', 'skin', 'insulin', 'bmi', 'pedigree', 'age', 'label'])
print(pima)

feature_cols = ['pregnant', 'insulin', 'bmi', 'age', 'glucose', 'bp']
x = pima[feature_cols]
y = pima.label

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)

model = GradientBoostingRegressor()
model.fit(x_train, y_train)
y_pred = model.predict(x_test)

print('score == ', r2_score(y_test, y_pred))
print("mean sqrd error is === ", mean_squared_error(y_test, y_pred))
print('root mean sqrd error is === ', np.sqrt(mean_squared_error(y_test, y_pred)))