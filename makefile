pvp: pvp.o player.o board.o
	g++ -o pvp pvp.o player.o board.o
pvp.o: pvp.cpp
	g++ -c pvp.cpp
player.o: player.cpp
	g++ -c player.cpp
board.o: board.cpp
	g++ -c board.cpp
