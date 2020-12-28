all: Stress_ball.o Collection.o main.o
	c++ -std=c++11 Stress_ball.o Collection.o main.o -o test
Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c -g Stress_ball.cpp
Collection.o: Collection.cpp Collection.h Stress_ball.h
	c++ -std=c++11 -c -g Collection.cpp
main.o: main.cpp Collection.h Stress_ball.h
	c++ -std=c++11 -c -g main.cpp
clean:
	rm *.o test
run: test
	./test