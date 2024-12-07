import numpy as np
import matplotlib.pyplot as plt

def estimate_coeff(x, y):
    n = np.size(x)
    m_x = np.mean(x)
    m_y = np.mean(y)

    ss_xy = np.sum(y*x) - n*m_y*m_x
    ss_xx = np.sum(x*x) - n*m_x*m_x

    m = ss_xy / ss_xx
    c = m_y - m*m_x
    return (c, m)

def plot_regression_line(x, y, b):
    plt.scatter(x, y, color='m', marker='x', s=30)
    y_pred = b[0] + b[1]*x
    plt.plot(x, y_pred, color='g')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.show()

x = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
y = np.array([1, 3, 2, 5, 7, 8, 8, 9, 10, 12])
b = estimate_coeff(x, y)
print("Estimated coefficients:\nb_0 = {}\nb_1 = {}".format(b[0], b[1]))
plot_regression_line(x, y, b)