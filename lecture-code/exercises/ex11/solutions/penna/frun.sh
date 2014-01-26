#!/bin/bash

B=8192
M=2
T=2
R=8
M1=200
PF=0.45 #good values for F=0: .13, .15; for F=8: .4, ..., .46
F=$R
NMAX=100000
N0=$((NMAX/10))
NMEAS=1024

DATFILE=b${B}_m${M}_t${T}_r${R}_m1${M1}_pf${PF}_f${F}_nmax${NMAX}_nmeas${NMEAS}.dat

echo "Building..."
make
echo "Running..."
echo $B $M $T $R $M1 $PF $F $NMAX $N0 $NMEAS |./fishing >$DATFILE
echo "Plotting..."
echo "
	set log xy
	plot '${DATFILE}'
" | gnuplot -
echo "Done."
