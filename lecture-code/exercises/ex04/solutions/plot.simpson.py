#!/usr/bin/env python
import sys
from numpy import loadtxt
import matplotlib
matplotlib.use('PDF')
import matplotlib.pyplot as plt

if len(sys.argv) != 2:
    print 'Usage:', sys.argv[0], 'res.dat'

fname = sys.argv[1]
data = loadtxt(fname)

plt.figure()
plt.plot(data[:,0], 7.*(2*data[:,0]-1)/data[:,2] / 1024**3)
plt.xlabel('# bins')
plt.ylabel('GFlops/s')
plt.savefig('fig1.pdf')