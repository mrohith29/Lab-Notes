import pandas as pd
from sklearn.ensemble import RandomForestClassifier
names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pedi', 'age', 'class'] 
data=pd.read_csv('C:\\Users\\HP\Desktop\\ML DATA 2022-23\\Datasets\\diabetes.csv',names=names)
print(data)
X =data.drop('class',axis=1)
y = data['class']
from sklearn.model_selection import train_test_split # implementing train-testsplit
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, random_state=66)
from sklearn import model_selection
#random forestmodelcreation
rfc =RandomForestClassifier() 
rfc.fit(X_train,y_train)
# predictions
rfc_predict = rfc.predict(X_test)
from sklearn.model_selection import cross_val_score
from sklearn.metrics import classification_report,confusion_matrix
rfc_cv_score = cross_val_score(rfc, X, y, cv=10, scoring='roc_auc')
print("=== Confusion Matrix ===") 
print(confusion_matrix(y_test,rfc_predict))
print('\n')
print("=== Classification Report ===") 
print(classification_report(y_test, rfc_predict))
print('\n')
print("=== All AUC Scores===")
print(rfc_cv_score) 
print('\n')
print("=== Mean AUC Score ===")
print("Mean AUC Score - Random Forest: ", rfc_cv_score.mean())
