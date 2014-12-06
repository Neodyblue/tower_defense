OBJS=	./src/point.o \
	./src/mob/mob_stats.o \
	./src/mob/mob.o \
	./src/entity/entity.o \
	./src/map/gen.o \
	./src/map/map.o \
	./src/play/play.o \
	./src/tower/tower.o \
	./src/tower/tower_stats.o \
	./src/game/button.o \
	./src/game/create_buttons.o \
	./src/game/main.o \
	./src/game/menu.o

CXX=clang++
CXXFLAGS=-Wall -Werror -Wextra -pedantic -std=c++1y -I include -g3

all: $(OBJS)
	$(CXX) $(OBJS) -o tower -lsfml-system -lsfml-graphics -lsfml-window

clean:
	rm -f $(OBJS) tower
