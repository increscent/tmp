import numpy as np
import sys

argv = sys.argv
q = np.array([17,16])
p1 = np.array([int(argv[1]), int(argv[2])])
p2 = np.array([int(argv[3]), int(argv[4])])

print(q, p1, p2)

print(np.dot(q-p1, p2-p1))
