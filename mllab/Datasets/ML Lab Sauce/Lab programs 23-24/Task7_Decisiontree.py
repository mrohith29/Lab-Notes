import os
import numpy as np 
import pandas as pd
import numpy as np, pandas as pd 
import matplotlib.pyplot as plt 
from sklearn import tree, metrics
from sklearn.model_selection import train_test_split 
import pylab
data=pd.read_csv('C:\\Users\\HP\Desktop\\ML DATA 2022-23\\Datasets\\cardata.csv',names=['buying','maint','doors','persons','lug_boot','safety','class'])
print(data)
data.head() 
data.info()
data['class'],class_names = pd.factorize(data['class']) 
print(class_names)
print(data['class'].unique())
data['buying'],_ = pd.factorize(data['buying']) 
data['maint'],_ = pd.factorize(data['maint']) 
data['doors'],_ = pd.factorize(data['doors']) 
data['persons'],_ = pd.factorize(data['persons']) 
data['lug_boot'],_ = pd.factorize(data['lug_boot']) 
data['safety'],_ = pd.factorize(data['safety']) 
print(data)
data.head()
data.info()
X = data.iloc[:,:-1]
y = data.iloc[:,-1]
# implementing train-test-split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=0) 
# train the decision tree
dtree = tree.DecisionTreeClassifier(criterion='entropy', max_depth=3, random_state=0) 
dtree.fit(X_train, y_train)
#use the model to make predictions with the test data 
y_pred = dtree.predict(X_test)
# how did our model perform? 
cnf_matrix = metrics.confusion_matrix(y_test, y_pred) 
print(cnf_matrix) 
count_misclassified = (y_test != y_pred).sum()
print('Misclassified samples: {}'.format(count_misclassified))
accuracy = metrics.accuracy_score(y_test, y_pred) 
print('Accuracy: {:.2f}'.format(accuracy))