#!/bin/bash

B=$((32*1024))
M=2
T=2
R=8
NMAX=100000
N0=$((NMAX/10))
NMEAS=$B

DATFILE=population.dat

echo "Running with B=$B M=$M T=$T R=$R NMAX=$NMAX, N0=$N0..."
echo $B $M $T $R $NMAX $N0 $NMEAS |./penna >$DATFILE
