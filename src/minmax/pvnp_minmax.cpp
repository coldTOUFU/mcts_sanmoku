#include "pvnp_minmax.hpp"

void pvnp_minmax() {
  Board *board = new Board();

  std::cout << "OとXのどちらかを選んでください(Xが先攻)。" << std::endl;
  std::cout << ">> ";
  
  char player_mark_input;
  int player_mark;
  std::cin >> player_mark_input;
  while (player_mark_input != 'O' && player_mark_input != 'X') {
    std::cout << std::endl << "不正な入力です。もう一度入力してください。" << std::endl << ">> ";
    std::cin >> player_mark_input;
  }
  player_mark = (player_mark_input == 'O' ? O : X);

  while (!board->is_game_end()) {
    if (player_mark == O && board->is_O_turn()) {
      player::move(board);
    }
    else if (player_mark == X && board->is_X_turn()) {
      player::move(board);
    }
    else {
      minmax_player::move(board);
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

int main(int argc, char* argv[]) {
  if (argc >= 2 && std::string(argv[1]) == "test") {
    minmax_player_unit_test();
  }
  else {
    pvnp_minmax();
  }
  return 0;
}
