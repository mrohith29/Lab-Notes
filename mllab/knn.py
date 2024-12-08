from sklearn.datasets import load_iris
from sklearn.neighbors import KNeighborsClassifier
import numpy as np
from sklearn.model_selection import train_test_split

iris_dataset = load_iris()
print(iris_dataset.target_names)

for i in range(len(iris_dataset.target_names)):
    print(i, iris_dataset.target_names[i])

x_train, x_test, y_train, y_test = train_test_split(iris_dataset['data'], iris_dataset['target'], random_state=0)

knn = KNeighborsClassifier(n_neighbors=1)
knn.fit(x_train, y_train)

# x = np.array([[5, 2.9, 1, 0.2]])
x = np.array([[2, 2, 2, 2]])
pred = knn.predict(x)

print(pred)
print(iris_dataset["target_names"][pred])

i=1
x_t = x_test[i]
x = np.array([x])
print(x)

for i in range(len(x_test)):
    x = x_test[i]
    x_new = np.array([x])
    pred = knn.predict(x_new)
    print(iris_dataset['target_names'][y_test[i]], pred, iris_dataset['target_names'][pred])

print(knn.score(x_test, y_test))