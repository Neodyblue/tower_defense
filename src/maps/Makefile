CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++14 -g3

test : main.o gen.o
	${CXX} ${CXXFLAGS} -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

clean :
	rm test *.o -rf
