all: Vector_v1.o
	g++ Vector_v1.o -o Vector

%.o: %.cpp %.h
	g++ -c $<

clean:
	rm -rf ./*.o
