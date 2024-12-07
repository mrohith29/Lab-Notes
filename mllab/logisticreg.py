import numpy as np
import pandas as pd
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import f1_score, confusion_matrix, accuracy_score, precision_score

col_names = ['pregnant', 'glucose', 'bp', 'skin', 'insulin', 'bmi', 'pedigree', 'age', 'label']  # load dataset 
pima = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\diabetes.csv", header=None, names=col_names) 
print(pima) 

feature_cols = ['pregnant', 'insulin', 'bmi', 'age', 'glucose', 'bp']

x = pima[feature_cols]
y = pima.label

print(x)
print(y)

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.35, random_state=0)

logreg = LogisticRegression(random_state=0, solver='lbfgs')

logreg.fit(x_train, y_train)
y_pred = logreg.predict(x_test)

cnf_matrix = confusion_matrix(y_test, y_pred)
print(cnf_matrix)

print("Accuracy: ", accuracy_score(y_test, y_pred))
print("Precision: ", precision_score(y_test, y_pred))