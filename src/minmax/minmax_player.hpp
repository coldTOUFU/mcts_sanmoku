#ifndef MINMAX_PLAYER_HPP_
#define MINMAX_PLAYER_HPP_

#include <algorithm>
#include <random>
#include "../structs/board.hpp"
#include "../structs/game_node.hpp"

namespace minmax_player {
  void move(Board *board);
  int best_hand(Board *board);
  int max_value(GameNode *n);
  int min_value(GameNode *n);
}

void minmax_player_unit_test();

#endif // MINMAX_PLAYER_HPP_
