import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import Birch

dataset, cluster = make_blobs(n_samples=600, centers=8, cluster_std=0.75, random_state=0)
print(dataset)
model = Birch(branching_factor=50, n_clusters=None, threshold=1.5)
model.fit(dataset)
pred = model.predict(dataset)

plt.scatter(dataset[:, 0], dataset[:, 1], c=pred, cmap='rainbow', alpha=0.7, edgecolors='black')
plt.show()
plt.scatter(dataset[:, 0], dataset[:, 1], c=pred, cmap='viridis', alpha=0.7, edgecolors='black')
plt.show()
plt.scatter(dataset[:, 0], dataset[:, 1], c=pred, cmap='plasma', alpha=0.7, edgecolors='black')
plt.show()
plt.scatter(dataset[:, 0], dataset[:, 1], c=pred, cmap='inferno', alpha=0.7, edgecolors='black')
plt.show()
plt.scatter(dataset[:, 0], dataset[:, 1], c=pred, cmap='magma', alpha=0.7, edgecolors='black')
plt.show()
plt.scatter(dataset[:, 0], dataset[:, 1], c=pred, cmap='cividis', alpha=0.7, edgecolors='black')
plt.show()
plt.scatter(dataset[:, 0], dataset[:, 1], c=pred, cmap='RdYlBu', alpha=0.7, edgecolors='black')
plt.show()