import sys
import numpy as np
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
    lr = LinearRegression()
    lr.fit(train, label)
    hy = lr.predict(test)
    for h in hy:
        print('{:.2f}'.format(h))


if __name__ == '__main__':
    main()
