
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

all: Board.o Critter.o Doodlebug.o Ant.o promptUser.o main.o output

output: main.o Board.o Critter.o Doodlebug.o Ant.o promptUser.o
        g++ ${CXXFLAGS} main.o Board.o Critter.o Doodlebug.o Ant.o promptUser.o -o output

main.o: main.cpp
        g++ ${CXXFLAGS} -c main.cpp

Board.o: Board.cpp Board.hpp
        g++ ${CXXFLAGS} -c Board.cpp

Critter.o: Critter.cpp Critter.hpp
        g++ ${CXXFLAGS} -c Critter.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
        g++ ${CXXFLAGS} -c Doodlebug.cpp

Ant.o: Ant.cpp Ant.hpp
        g++ ${CXXFLAGS} -c Ant.cpp

promptUser.o: promptUser.cpp promptUser.hpp
        g++ ${CXXFLAGS} -c promptUser.cpp

val:
        valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes ./output

clean:
        rm *.o output

