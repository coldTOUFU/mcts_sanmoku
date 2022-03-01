pvnp: pvnp.o player.o random_player.o board.o
	g++ -o pvnp pvnp.o player.o random_player.o board.o
pvnp.o: pvnp.cpp
	g++ -c pvnp.cpp
player.o: player.cpp
	g++ -c player.cpp
random_player.o: random_player.cpp
	g++ -c random_player.cpp
board.o: board.cpp
	g++ -c board.cpp
