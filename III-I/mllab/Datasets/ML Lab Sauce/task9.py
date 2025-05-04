from sklearn.datasets import load_iris
from sklearn.neighbors import KNeighborsClassifier 
import numpy as np
from sklearn.model_selection import train_test_split 

# Load the iris dataset
iris_dataset = load_iris()
print("\n IRIS FEATURES \ TARGET NAMES: \n", iris_dataset.target_names)
for i in range(len(iris_dataset.target_names)):
    print("\n[{0}]:[{1}]".format(i, iris_dataset.target_names[i]))

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(iris_dataset["data"], iris_dataset["target"], random_state=0)

# Create and train the k-NN classifier
kn = KNeighborsClassifier(n_neighbors=1)
kn.fit(X_train, y_train)

# Predict for a new sample
x_new = np.array([[5, 2.9, 1, 0.2]])
print("\n XNEW \n", x_new)
prediction = kn.predict(x_new)
print("\n Predicted target value: {}\n".format(prediction))
print("\n Predicted feature name: {}\n".format(iris_dataset["target_names"][prediction]))

i = 1
x = X_test[i]
x_new = np.array([x])
print("\n XNEW \n",x_new)
# Test and print results for the test set
for i in range(len(X_test)):
    x = X_test[i]
    x_new = np.array([x])
    prediction = kn.predict(x_new)
print("\n Actual: {0} {1}, Predicted: {2} {3}".format(y_test[i], iris_dataset["target_names"][y_test[i]], prediction, iris_dataset["target_names"][prediction]))

# Print the test score (accuracy)
print("\n TEST SCORE[ACCURACY]: {:.2f}\n".format(kn.score(X_test, y_test)))
