all: Stress_ball.o Jeans.o Stress_ball_test.o Jeans_test.o collection-test.o
	c++ -std=c++11 Stress_ball.o Jeans.o Stress_ball_test.o Jeans_test.o collection-test.o -o test
Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c -g Stress_ball.cpp
Jeans.o: Jeans.cpp Jeans.h
	c++ -std=c++11 -c -g Jeans.cpp
Stress_ball_test.o: Stress_ball_test.cpp Stress_ball_test.h Collection.h Stress_ball.h
	c++ -std=c++11 -c -g Stress_ball_test.cpp
Jeans_test.o: Jeans_test.cpp Jeans_test.h Collection.h Jeans.h
	c++ -std=c++11 -c -g Jeans_test.cpp
collection-test.o: collection-test.cpp Stress_ball_test.h Jeans_test.h Collection.h Stress_ball.h
	c++ -std=c++11 -c -g collection-test.cpp
clean:
	rm *.o test
run: test
	./test