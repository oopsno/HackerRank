import numpy as np
from sklearn.linear_model import LinearRegression


def train():
    xs = np.genfromtxt('trainingdata.txt', dtype=np.float32, delimiter=',')
    fulfill = []
    for c, l in xs:
        if l == 8:
            fulfill.append(c)
    fulfill = min(fulfill)
    print('Fulfill time:', fulfill)
    xs = np.array(sorted([x for x in xs if x[1] <= fulfill], key=lambda x: x[0]))
    print(xs)
    # y = min(2x, 8)


if __name__ == '__main__':
    train()

