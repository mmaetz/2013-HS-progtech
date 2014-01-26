# Programming Techniques for Scientific Simulations, HS 2013
# Exercise 4.3

COMPILER=c++

all: fig1.pdf fig2.pdf

fig1.pdf: data.simpson.dat
	./plot.simpson.py data.simpson.dat

data.simpson.dat: simpson
	./simpson > data.simpson.dat

simpson: simpson.cpp
	$(COMPILER) -O3 simpson.cpp -o simpson


fig2.pdf: data.cache.dat
	./plot.cache.py data.cache.dat

data.cache.dat: cache
	./cache > data.cache.dat

cache: cache.cpp
	$(COMPILER) -O3 -funroll-loops cache.cpp -o cache

clean:
	rm *.o simpson cache