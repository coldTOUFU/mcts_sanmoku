#ifndef PMC_PLAYER_HPP_
#define PMC_PLAYER_HPP_

#include <algorithm>
#include <utility>
#include <vector>
#include <random>
#include "board.hpp"
#include "game_node.hpp"

namespace pmc_player {
  void move(Board *board);
  int primary_monte_carlo(Board *board, int playout_num = 1000);
  int playout(GameNode *original_node);
}

#endif // PMC_PLAYER_HPP_
