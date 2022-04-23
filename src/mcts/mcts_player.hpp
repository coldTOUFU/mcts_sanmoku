#ifndef MCTS_PLAYER_HPP_
#define MCTS_PLAYER_HPP_

#include <algorithm>
#include <utility>
#include <vector>
#include <random>
#include "../structs/board.hpp"
#include "../structs/monte_carlo_node.hpp"

namespace mcts_player {
  void move(Board *board);
  int monte_carlo_tree_search(Board *board, int expansion_n = 5, int playout_limit = 10000);
}

#endif // MCTS_PLAYER_HPP_
