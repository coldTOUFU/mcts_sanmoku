#include "board.hpp"
#include "game_node.hpp"
#include "minmax_player.hpp"
#include "player.hpp"
#include "pmc_player.hpp"
#include "pvnp.hpp"
#include "pvnp_minmax.hpp"
#include "pvp.hpp"
#include "random_player.hpp"

int main(void) {
  // board_unit_test();
  // game_node_unit_test();
  // minmax_player_unit_test();
  pvnp_minmax();

  return 0;
}
