import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.model_selection import train_test_split, cross_val_score

data = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\diabetes.csv")
print(data)
x = data.iloc[:, :-1]
y = data.iloc[:, -1]

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.33, random_state=66)

rfc = RandomForestClassifier()
rfc.fit(x_train, y_train)
rfc_predict = rfc.predict(x_test)

rfc_cv_score = cross_val_score(rfc, x, y, cv=10, scoring='roc_auc')

print("hi", confusion_matrix(y_test, rfc_predict))

print(classification_report(y_test, rfc_predict))

print(rfc_cv_score)

print(rfc_cv_score.mean())