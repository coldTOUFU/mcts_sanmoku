#include "player.hpp"

namespace player {
  void move(Board *board) {
    std::cout << "===============" << std::endl;
    std::cout << (board->get_mark_type() == O ? "O" : "X") << "のターン" << std::endl;
    std::cout << "現在の盤面" << std::endl;
    board->print_board();
    std::cout << std::endl;

    std::cout << "打つ場所を番号で指定してください。" << std::endl;
    std::cout << "012" << std::endl << "345" << std::endl << "678" << std::endl;
    std::cout << ">> ";

    int input_place;
    std::cin >> input_place;
    while(!board->put(input_place)) {
      std::cout << std::endl << "不正な入力です。もう一度入力してください。" << std::endl << ">> ";
      std::cin >> input_place;
    }
  }
}
