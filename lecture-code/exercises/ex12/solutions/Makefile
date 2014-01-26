# Programming Techniques for Scientific Simulations, HS 2013
# Exercise 12

CXX = c++
CXXFLAGS = -Wall -O3 -DNDEBUG
LDFLAGS = -framework vecLib # -lblas -lgfortran

all: matrixmult strassen

clean:
	rm matrixmult strassen

matrixmult: matrixmult.cpp
	$(CXX) $(CXXFLAGS) matrixmult.cpp -o matrixmult $(LDFLAGS)

strassen: strassen.cpp
	$(CXX) $(CXXFLAGS) strassen.cpp -o strassen $(LDFLAGS)


