# Programming Techniques for Scientific Simulations, HS 2013
# Exercise 3.2

COMPILER = g++
FLAGS = -O0

all: simpson

simpson: libintegrate.a simpson_main.o
	$(COMPILER) $(FLAGS) simpson_main.o -o simpson -L. -lintegrate

libintegrate.a: simpson.o
	ar ruc libintegrate.a simpson.o
	ranlib libintegrate.a

simpson_main.o: simpson_main.cpp simpson.hpp
	$(COMPILER) $(FLAGS) -c simpson_main.cpp

simpson.o: simpson.hpp simpson.cpp
	$(COMPILER) $(FLAGS) -c simpson.cpp

clean:
	rm -f *.o *.a simpson