#include "random_player.hpp"

namespace random_player {
  void move(Board *board) {
    std::cout << "===============" << std::endl;
    std::cout << (board->get_mark_type() == O ? "O" : "X") << "のターン" << std::endl;
    std::cout << "現在の盤面" << std::endl;
    board->print_board();
    std::cout << std::endl;

    std::random_device seed_gen;
    std::default_random_engine rand_engine(seed_gen());
    std::uniform_int_distribution<> dist(0, 8);

    int input_place = dist(rand_engine);
    while(!board->put(input_place)) {
      input_place = dist(rand_engine);
    }
  }
}
