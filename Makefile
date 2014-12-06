OBJS=./src/main2.o \
	./src/point.o \
	./src/mob/mob_stats.o \
	./src/mob/mob.o \
	./src/entity/entity.o \
	./src/map/gen.o \
	./src/map/map.o \
	./src/play/play.o

CXX=clang++
CXXFLAGS=-Wall -Werror -Wextra -pedantic -std=c++1y -I include -g3

all: $(OBJS)
	$(CXX) $(OBJS) -o tower -lsfml-system -lsfml-graphics -lsfml-window

clean:
	rm -f $(OBJS) tower
