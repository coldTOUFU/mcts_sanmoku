all: pvp pvnp_random pvnp_minmax pvnp_pmc pvnp_mcts

pvp: ./out/obj/structs/board.o ./out/obj/player/player.o ./out/obj/pvp/pvp.o
	g++ -o ./out/pvp ./out/obj/structs/board.o ./out/obj/player/player.o ./out/obj/pvp/pvp.o
pvnp_random: ./out/obj/structs/board.o ./out/obj/player/player.o ./out/obj/random/random_player.o ./out/obj/random/pvnp.o
	g++ -o ./out/pvnp_random ./out/obj/structs/board.o ./out/obj/player/player.o ./out/obj/random/random_player.o ./out/obj/random/pvnp.o
pvnp_minmax: ./out/obj/structs/board.o ./out/obj/structs/game_node.o ./out/obj/player/player.o ./out/obj/minmax/minmax_player.o ./out/obj/minmax/pvnp_minmax.o
	g++ -o ./out/pvnp_minmax ./out/obj/structs/game_node.o ./out/obj/structs/board.o ./out/obj/player/player.o ./out/obj/minmax/minmax_player.o ./out/obj/minmax/pvnp_minmax.o
pvnp_pmc: ./out/obj/structs/board.o ./out/obj/structs/game_node.o ./out/obj/player/player.o ./out/obj/pmc/pmc_player.o ./out/obj/pmc/pvnp_pmc.o
	g++ -o ./out/pvnp_pmc ./out/obj/structs/board.o ./out/obj/structs/game_node.o ./out/obj/player/player.o ./out/obj/pmc/pmc_player.o ./out/obj/pmc/pvnp_pmc.o
pvnp_mcts: ./out/obj/structs/board.o ./out/obj/structs/monte_carlo_node.o ./out/obj/player/player.o ./out/obj/mcts/mcts_player.o ./out/obj/mcts/pvnp_mcts.o
	g++ -g -o ./out/pvnp_mcts ./out/obj/structs/board.o ./out/obj/structs/monte_carlo_node.o ./out/obj/player/player.o ./out/obj/mcts/mcts_player.o ./out/obj/mcts/pvnp_mcts.o

./out/obj/mcts/pvnp_mcts.o: ./src/mcts/pvnp_mcts.cpp
	g++ -c ./src/mcts/pvnp_mcts.cpp -o ./out/obj/mcts/pvnp_mcts.o
./out/obj/pmc/pvnp_pmc.o: ./src/pmc/pvnp_pmc.cpp
	g++ -c ./src/pmc/pvnp_pmc.cpp -o ./out/obj/pmc/pvnp_pmc.o
./out/obj/mcts/mcts_player.o: ./src/mcts/mcts_player.cpp
	g++ -c ./src/mcts/mcts_player.cpp -o ./out/obj/mcts/mcts_player.o
./out/obj/pmc/pmc_player.o: ./src/pmc/pmc_player.cpp
	g++ -c ./src/pmc/pmc_player.cpp -o ./out/obj/pmc/pmc_player.o
./out/obj/minmax/pvnp_minmax.o: ./src/minmax/pvnp_minmax.cpp
	g++ -c ./src/minmax/pvnp_minmax.cpp -o ./out/obj/minmax/pvnp_minmax.o
./out/obj/minmax/minmax_player.o: ./src/minmax/minmax_player.cpp
	g++ -c ./src/minmax/minmax_player.cpp -o ./out/obj/minmax/minmax_player.o
./out/obj/random/pvnp.o: ./src/random/pvnp.cpp
	g++ -c ./src/random/pvnp.cpp -o ./out/obj/random/pvnp.o
./out/obj/random/random_player.o: ./src/random/random_player.cpp
	g++ -c ./src/random/random_player.cpp -o ./out/obj/random/random_player.o
./out/obj/pvp/pvp.o: ./src/pvp/pvp.cpp
	g++ -c ./src/pvp/pvp.cpp -o ./out/obj/pvp/pvp.o
./out/obj/player/player.o: ./src/player/player.cpp
	g++ -c ./src/player/player.cpp -o ./out/obj/player/player.o
./out/obj/structs/monte_carlo_node.o: ./src/structs/monte_carlo_node.cpp
	g++ -c ./src/structs/monte_carlo_node.cpp -o ./out/obj/structs/monte_carlo_node.o
./out/obj/structs/game_node.o: ./src/structs/game_node.cpp
	g++ -c ./src/structs/game_node.cpp -o ./out/obj/structs/game_node.o
./out/obj/structs/board.o: ./src/structs/board.cpp
	g++ -c ./src/structs/board.cpp -o ./out/obj/structs/board.o

clean:
	rm -f ./out/obj/*/*.o ./out/structs ./out/pvp ./out/random ./out/minmax ./out/pmc ./out/mcts
