import re
import numpy as np
with open('input.txt') as f:
    lines = [x.strip() for x in f.readlines()]

# load vectors
ns = np.array([[int(x) for x in re.findall(r'-?\d+', s)] for s in lines])
p = ns[:, :2]
v = ns[:, 2:]

# max 200,000 seconds/iterations
upper_bound = 200000
p_t = np.copy(p)
max_dist = np.empty(upper_bound)
for i in range(upper_bound):
		# find the max manhattan distance for each second
    #max_dist[i] = np.ptp(p_t)
		# ptp as 1-D ?
    max_dist[i] = np.sum(np.amax(p_t, 0) -np.amin(p_t, 0))
    p_t += v
# find the min distance
best_t = np.argmin(max_dist)
a = p + best_t * v

# normalize
a -= np.min(a, 0)
d = np.max(a, 0) + 1
sky = np.zeros(d)
sky[tuple(a.T)] = 1

# Part one
for l in map(''.join, np.where(sky.T, '#', ' ')):
    print(l)
