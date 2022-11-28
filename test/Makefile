api.o: ../api.c

%.o: %.c
	gcc -c -o $@ $<

%.o: %.cpp
	g++ -c -o $@ $<

test: route.o ../api.o
	g++ -std=c++14 route.o ../api.o -lgtest -lgtest_main -o routeTest && ./routeTest

foo:
	g++ -std=c++14 footest.cpp ../api.c -o fooTest && ./fooTest
