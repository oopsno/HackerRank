import scipy as sp
import scipy.misc
import numpy as np
import matplotlib.pyplot as plt


def load_data(serial):
    with open('input/input{:02d}.jpg'.format(serial), 'rb') as fd:
        image = (sp.misc.imread(fd, mode='L') < 50)[11:21, 5:-11]
    with open('output/output{:02d}.txt'.format(serial)) as fd:
        label = fd.read()
    return np.array([image[:, i:i + 8] for i in [0, 9, 18, 27, 36]]), label


def main():
    xs, label = [], ''
    for i in range(25):
        try:
            c, w = load_data(i)
            xs.append(c)
            label += w.strip()
        except:
            pass
    xs = np.concatenate(xs)
    sample = {}
    for i, w in enumerate(label):
        if w not in sample:
            sample[w] = xs[i]
        else:
            if not np.all(sample[w] == xs[i]):
                print('Confident: ', w, i)
    ws = []
    for i, key in enumerate(sorted(sample.keys())):
        ws.append(sample[key])
    ws = np.concatenate(ws).reshape(36, 80).astype(np.uint8)
    np.savetxt('model.txt', ws, fmt='%d')


if __name__ == '__main__':
    main()
