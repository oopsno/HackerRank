import sys
import numpy as np
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression


def parse(text):
    seg = text.split()
    f, n = int(seg[0]), int(seg[1])
    seg = seg[2:]
    train = np.ndarray([n, f], dtype=np.float32)
    label = np.zeros(n, dtype=np.float32)
    for i in range(n):
        base = i * (f + 1)
        for j in range(f):
            train[i, j] = float(seg[base + j])
        label[i] = float(seg[base + f])
    t = int(seg[n * (f + 1)])
    seg = seg[n * (f + 1) + 1:]
    test = np.ndarray([t, f], dtype=np.float32)
    for i in range(t):
        for j in range(f):
            test[i, j] = float(seg[i * f + j])
    return train, label, test


def main():
    train, label, test = parse(sys.stdin.read())
    poly = PolynomialFeatures(degree=3)
    train = poly.fit_transform(train)
    test = poly.fit_transform(test)
    lr = LinearRegression()
    lr.fit(train, label)
    hy = lr.predict(test).reshape(len(test))
    for h in hy:
        print('{:.3f}'.format(h))

if __name__ == '__main__':
    main()
