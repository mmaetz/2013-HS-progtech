CXX=c++
CXXFLAGS = -Wall -O2

all: genome-test animal-test

clean:
	rm *.o genome-test animal-test

genome-test: genome-test.o genome.o
	$(CXX) -o $@ genome-test.o genome.o

animal-test: animal-test.o genome.o animal.o
	c++ -o $@ animal-test.o genome.o animal.o

test: genome-test animal-test
	./genome-test
	./animal-test

%.o: %.cpp *.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<
