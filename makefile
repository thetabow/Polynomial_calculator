all: Polynomial_v3.o poly_class_v3.o Fraction.o
	g++ Polynomial_v3.o poly_class_v3.o Fraction.o -o Polynomial

%.o: %.cpp %.h
	g++ -c $<

clean:
	rm -rf ./*.o
