import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.metrics import classification_report, confusion_matrix

# Define column names
names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pedi', 'age', 'class']

# Load dataset
data = pd.read_csv('C:/Users/GRIET/Desktop/22241a05r2/datasets/diabetes.csv', names=names)
print(data)

# Split dataset into features and target variable
X = data.drop('class', axis=1)
y = data['class']

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, random_state=66)

# Create Random Forest model
rfc = RandomForestClassifier()
rfc.fit(X_train, y_train)

# Make predictions
rfc_predict = rfc.predict(X_test)

# Evaluate the model
rfc_cv_score = cross_val_score(rfc, X, y, cv=10, scoring='roc_auc')

# Print results
print("=== Confusion Matrix ===")
print(confusion_matrix(y_test, rfc_predict))
print("\n")

print("=== Classification Report ===")
print(classification_report(y_test, rfc_predict))
print("\n")

print("=== All AUC Scores ===")
print(rfc_cv_score)
print("\n")

print("=== Mean AUC Score ===")
print("Mean AUC Score - Random Forest: ", rfc_cv_score.mean())
