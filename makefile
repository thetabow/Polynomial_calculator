all: Polynomial.o poly_class.o Fraction.o Vector.cpp
	g++ Polynomial.o poly_class.o Fraction.o -o Polynomial -std=c++11

%.o: %.cpp %.h
	g++ -c $< -std=c++11

clean:
	rm -rf ./*.o
