# board_test: main.o board.o
# 	g++ -o board_test main.o board.o
game_node_test: main.o board.o game_node.o
	g++ -o game_node_test main.o board.o game_node.o

main.o: main.cpp
	g++ -c main.cpp
pmc_player.o: pmc_player.cpp
	g++ -c pmc_player.cpp
minmax_player.o: minmax_player.cpp
	g++ -c minmax_player.cpp
game_node.o: game_node.cpp
	g++ -c game_node.cpp
pvnp.o: pvnp.cpp
	g++ -c pvnp.cpp
player.o: player.cpp
	g++ -c player.cpp
random_player.o: random_player.cpp
	g++ -c random_player.cpp
board.o: board.cpp
	g++ -c board.cpp
