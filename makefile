all: Polynomial_v3.o poly_class_v3.o 
	g++ Polynomial_v3.o poly_class_v3.o -o Polynomial

%.o: %.cpp %.h
	g++ -c $<

clean:
	rm -rf ./*.o
