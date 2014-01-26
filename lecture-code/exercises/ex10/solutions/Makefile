#Makefile

CXX = c++
CXXFLAGS = -O3 -std=c++11 -stdlib=libc++ -march=native -pipe

all: random.pdf containers.png

random: random.cpp
	$(CXX) $(CXXFLAGS) random.cpp -o random

random.dat: random
	./random | tee random.dat

random.pdf: random.dat random_plot.py
	python random_plot.py

containers: containers.cpp
	$(CXX) $(CXXFLAGS) containers.cpp -o containers	

containers.dat: containers
	./containers | tee containers.dat

containers.png: containers.dat containers_plot.p
	gnuplot containers_plot.p

clean:
	rm -f random containers
