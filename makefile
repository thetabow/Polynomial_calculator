all: Polynomial_v2.o poly_class_v2.o 
	g++ Polynomial_v2.o poly_class_v2.o -o Polynomial

%.o: %.cpp %.h
	g++ -c $<
