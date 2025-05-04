from numpy import mean, cov, array
from numpy.linalg import eig

A = array([[1, 2], [3, 4], [5, 6]])

M = mean(A.T, axis=1)
print(M)

C = A-M
print(C)

V = cov(C.T)

values, vectors = eig(V)
print(vectors)

P = vectors.T.dot(C.T)
print(P.T)