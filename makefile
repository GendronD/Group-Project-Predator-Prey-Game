
output: main.o Board.o Critter.o Doodlebug.o RunGame.o ant.o game.o promptUser.o
	g++ -std=c++0x main.o Board.o Critter.o Doodlebug.o RunGame.o ant.o game.o promptUser.o -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Board.o: Board.cpp Board.hpp
	g++ -std=c++0x -c Board.cpp

Critter.o: Critter.cpp Critter.hpp
	g++ -std=c++0x -c Critter.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
	g++ -std=c++0x -c Doodlebug.cpp

RunGame.o: RunGame.cpp RunGame.hpp
	g++ -std=c++0x -c RunGame.cpp

ant.o: ant.cpp ant.hpp
	g++ -std=c++0x -c ant.cpp	

game.o: game.cpp game.hpp
	g++ -std=c++0x -c game.cpp

promptUser.o: promptUser.cpp promptUser.hpp
	g++ -std=c++0x -c promptUser.cpp

clean:
	rm *.o output
