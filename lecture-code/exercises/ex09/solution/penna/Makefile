CXX = c++
CXXFLAGS = -Wall -O2

all: penna population.pdf

clean:
	rm *.o penna

penna: main.o population.o animal.o genome.o
	$(CXX) $(CXXFLAGS) -o $@ main.o population.o animal.o genome.o

%.o: %.cpp *.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

population.dat gene_histogram.dat: penna run.sh
	./run.sh

population.pdf gene_histogram.pdf: plot.py population.dat gene_histogram.dat
	python plot.py
