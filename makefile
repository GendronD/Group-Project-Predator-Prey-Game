CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = ValidInt.o Menu.o UserInput.o Game.o Board.o Critter.o Ant.o Doodlebug.o
SRCS = sim.cpp

all: ValidInt Menu UserInput Game Board Critter Ant Doodlebug Sim

ValidInt: ValidInt.hpp ValidInt.cpp 
	${CXX} ${CXXFLAGS} ValidInt.cpp -c

Menu: ValidInt.hpp Menu.hpp ValidInt.cpp Menu.cpp
	${CXX} ${CXXFLAGS} ValidInt.cpp Menu.cpp -c
 
UserInput: UserInput.hpp UserInput.cpp 
	${CXX} ${CXXFLAGS} UserInput.cpp -c

Game: Game.hpp Game.cpp 
	${CXX} ${CXXFLAGS} Game.cpp -c

Board: Board.hpp Board.cpp 
	${CXX} ${CXXFLAGS} Board.cpp -c

Critter: Critter.hpp Critter.cpp 
	${CXX} ${CXXFLAGS} Critter.cpp -c

Ant: Ant.hpp Ant.cpp 
	${CXX} ${CXXFLAGS} Ant.cpp -c

Doodlebug: Doodlebug.hpp Doodlebug.cpp 
	${CXX} ${CXXFLAGS} Doodlebug.cpp -c

Sim: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${SRCS} -o sim

val:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes ./sim

clean:
	rm *.o sim
