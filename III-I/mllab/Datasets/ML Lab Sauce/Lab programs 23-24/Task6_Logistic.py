import pandas as pd
col_names = ['pregnant', 'glucose', 'bp', 'skin', 'insulin', 'bmi', 'pedigree', 'age', 
'label'] 
# load dataset
pima = pd.read_csv("C:\\Users\\HP\Desktop\\ML DATA 2022-23\\Datasets\\diabetes.csv", header=None, names=col_names) 
print(pima)
feature_cols = ['pregnant', 'insulin', 'bmi', 'age','glucose','bp']
X = pima[feature_cols] # Features 
y = pima.label # Target variable 
print(X)
print(y)
# split X and y into training and testing sets
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.25,random_state=0) 
# import the class
from sklearn.linear_model import LogisticRegression
# instantiate the model (using the default parameters)
logreg = LogisticRegression(random_state=0, solver='lbfgs')
# fit the model with data 
logreg.fit(X_train,y_train)
y_pred=logreg.predict(X_test)
# import the metrics class 
from sklearn import metrics
cnf_matrix = metrics.confusion_matrix(y_test, y_pred) 
print(cnf_matrix) 
print("Accuracy:",metrics.accuracy_score(y_test, y_pred)) 
print("Precision:",metrics.precision_score(y_test, y_pred))