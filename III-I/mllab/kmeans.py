from sklearn.cluster import KMeans
from sklearn.metrics import accuracy_score, f1_score, precision_score
import numpy as np, pandas as pd
import matplotlib.pyplot as plt

x1 = np.array([3, 1, 1, 2, 1, 6, 6, 6, 5, 6, 7, 8, 9, 8, 9, 9, 8])
x2 =np.array([5, 4, 6, 6, 5, 8, 6, 7, 6, 7, 1, 2, 1, 2, 3, 2 ,3])

plt.plot()
plt.xlim([0, 10])
plt.ylim([1, 10])
plt.title('Dataset')
plt.scatter(x1, x2)
plt.show()

plt.plot()
x = np.array(list(zip(x1, x2))).reshape(len(x1), 2)
colors = ['b', 'g', 'r']
markers = ['o', 'v', 's']

k = 3
kmeans_model = KMeans(n_clusters=k).fit(x)

print(kmeans_model.labels_)
plt.plot()
for i, l in enumerate(kmeans_model.labels_):
    plt.plot(x1[i], x2[i], color = colors[l], marker=markers[l], ls='None')
    plt.xlim([0, 10])
    plt.ylim([0, 10])
plt.show()