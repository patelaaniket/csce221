all: pa1.o main.o
	c++ -std=c++11 main.o pa1.o -o test
pa1.o: pa1.cpp pa1.h
	c++ -std=c++11 -c pa1.cpp
main.o: main.cpp pa1.h
	c++ -std=c++11 -c main.cpp
clean:
	rm *.o test
