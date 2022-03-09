#include "pvp.hpp"

void pvp() {
  Board *board = new Board();
  while (!board->is_game_end()) {
    if (board->is_O_turn()) {
      player::move(board);
    }
    else {
      player::move(board);
    }
  }
  if (board->is_O_win()) {
    std::cout << "Oの勝ち!" << std::endl;
  }
  else if (board->is_X_win()) {
    std::cout << "Xの勝ち!" << std::endl;
  }
  else {
    std::cout << "引き分け" << std::endl;
  }
}
