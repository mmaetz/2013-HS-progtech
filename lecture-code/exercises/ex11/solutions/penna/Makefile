CXX = c++
CXXFLAGS = -Wall -O2

all: fishing

clean:
	rm *.o fishing

fishing: fishing.o fishing_population.o population.o animal.o genome.o
	$(CXX) -o $@ fishing.o fishing_population.o population.o animal.o genome.o

%.o: %.cpp *.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

