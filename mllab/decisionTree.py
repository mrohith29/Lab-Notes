import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn import metrics, tree
from sklearn.model_selection import train_test_split

data = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\cardata.csv", names=['buying', 'maint', 'doors', 'persons', 'lug_boot', 'safety', 'class'])
print(data)
data.head()
data.info()

data['class'], class_names = pd.factorize(data['class'])
print(class_names)

data['buying'], _ = pd.factorize(data['buying'])
data['maint'], _ = pd.factorize(data['maint'])
data['doors'], _ = pd.factorize(data['doors'])
data['persons'], _ = pd.factorize(data['persons'])
data['lug_boot'], _ = pd.factorize(data['lug_boot'])
data['safety'], _ = pd.factorize(data['safety'])

print(data)
data.head()
data.info()

x = data.iloc[:, :-1]
y = data.iloc[:, -1]

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=0)

dtree = tree.DecisionTreeClassifier(criterion='entropy', max_depth=3, random_state=0)

dtree.fit(x_train, y_train)

y_pred = dtree.predict(x_test)

cnf_matrix = metrics.confusion_matrix(y_test, y_pred)
print(cnf_matrix)

count_misclassified = (y_test != y_pred).sum()
print("Misclassified samples: {}".format(count_misclassified))

accuracy = metrics.accuracy_score(y_test, y_pred)
print('Accuracy:{:.2f}'.format(accuracy))