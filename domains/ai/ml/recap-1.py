from numpy import corrcoef

xs = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
ys = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]
print('{:.3f}'.format(corrcoef(xs, ys)[0, 1]))
