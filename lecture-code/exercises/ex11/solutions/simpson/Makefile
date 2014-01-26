# Programming Techniques for Scientific Simulations, HS 2013
# Exercise 11.1

COMPILER = c++
FLAGS = -O3 -funroll-loops

all: simpson_benchmark_1

simpson_benchmark_1: simpson.hpp simpson_1.o simpson_test_functions_macros.hpp simpson_benchmark.cpp
	$(COMPILER) $(FLAGS) -DF1 simpson_benchmark.cpp -o simpson_benchmark_1 simpson_1.o
	$(COMPILER) $(FLAGS) -DF2 simpson_benchmark.cpp -o simpson_benchmark_2 simpson_2.o
	$(COMPILER) $(FLAGS) -DF3 simpson_benchmark.cpp -o simpson_benchmark_3 simpson_3.o
	$(COMPILER) $(FLAGS) -DF4 simpson_benchmark.cpp -o simpson_benchmark_4 simpson_4.o
	$(COMPILER) $(FLAGS) -DF5 simpson_benchmark.cpp -o simpson_benchmark_5 simpson_5.o
	$(COMPILER) $(FLAGS) -DF6 simpson_benchmark.cpp -o simpson_benchmark_6 simpson_6.o

simpson_1.o: simpson.hpp simpson.cpp simpson_test_functions_macros.hpp
	$(COMPILER) $(FLAGS) -c -DF1 simpson.cpp -o simpson_1.o
	$(COMPILER) $(FLAGS) -c -DF2 simpson.cpp -o simpson_2.o
	$(COMPILER) $(FLAGS) -c -DF3 simpson.cpp -o simpson_3.o
	$(COMPILER) $(FLAGS) -c -DF4 simpson.cpp -o simpson_4.o
	$(COMPILER) $(FLAGS) -c -DF5 simpson.cpp -o simpson_5.o
	$(COMPILER) $(FLAGS) -c -DF6 simpson.cpp -o simpson_6.o

clean:
	rm -f *.o simpson_benchmark_1 simpson_benchmark_2 simpson_benchmark_3 simpson_benchmark_4 simpson_benchmark_5 simpson_benchmark_6
