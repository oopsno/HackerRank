import sys
import numpy as np
from numpy import corrcoef
from sklearn.linear_model import LinearRegression

xs = np.array([15, 12, 8,  8,  7,  7,  7,  6,  5, 3]).reshape(10, 1)
ys = np.array([10, 25, 17, 11, 13, 17, 20, 13, 9, 15]).reshape(10, 1)

lr = LinearRegression()
lr.fit(xs, ys)
print('{:.3f}'.format(lr.predict(10)[0, 0]))
