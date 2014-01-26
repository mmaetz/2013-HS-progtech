#!/usr/bin/env python
# Programming Techniques for Scientific Simulations, HS 2013
# Exercise 4.2

from numpy import *
import matplotlib
matplotlib.use('PDF')
import matplotlib.pyplot as plt
import sys

data = loadtxt(sys.argv[1])

markers = ['s', 'o', '^', '>', 'v', '<', 'd', 'p', 'h', '+', 'x']
imark = 0

strides = unique(data[:,1])
# strides = [64,] # uncomment to plot only stride = 64B

plt.figure()
for s in strides:
    cond = (data[:,1] == s)
    x = compress(cond, data[:,0])
    y = compress(cond, data[:,3])
    order = argsort(x)
    x = x[order]
    y = y[order]
    if s < 1024:
        label='step size = %dB' % s
    else:
        label='step size = %dkB' % (int(s)/1024)
    plt.semilogx(x, y, '-'+markers[imark], label=label)
    imark = (imark+1) % len(markers)
plt.xlabel('array size [kB]')
plt.ylabel('Mops')
plt.legend(loc='lower left', frameon=False)
plt.savefig('fig2.pdf')
