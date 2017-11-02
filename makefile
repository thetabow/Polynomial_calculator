all: Polynomial_v3.o poly_class_v3.o Fraction.o Vector_v1.cpp
	g++ Polynomial_v3.o poly_class_v3.o Fraction.o -o Polynomial -std=c++11

%.o: %.cpp %.h
	g++ -c $< -std=c++11

clean:
	rm -rf ./*.o
