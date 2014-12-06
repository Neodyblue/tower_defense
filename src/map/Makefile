CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++14 -g3

test : main.o gen.o map.o
	${CXX} -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system  -I include/map/

clean :
	rm test *.o -rf
