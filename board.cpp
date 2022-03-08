#include "board.hpp"

void Board::copy_from(Board *b) {
  std::stack<int> tmp_stack;

  while (!b->put_log.empty()) {
    tmp_stack.push(b->put_log.top());
    b->put_log.pop();
  }
  while (!tmp_stack.empty()) {
    int tmp = tmp_stack.top();
    tmp_stack.pop();
    b->put_log.push(tmp); // 借りてるbのスタックを元通りにする。
    put_log.push(tmp);
  }
  for (int i = 0; i < 9; i++) {
    board[i] = b->board[i];
  }
  cur_mark = b->cur_mark;
}

bool Board::put(int place) {
  if (!is_legal(place)) { return false; }

  board[place] = cur_mark;
  cur_mark = (cur_mark == O ? X : O);
  put_log.push(place);
  return true;
}

bool Board::unput() {
  if (put_log.empty()) { return false; }

  board[put_log.top()] = NOT_DECIDED;
  cur_mark = (cur_mark == O ? X : O);
  put_log.pop();
  return true;
}

bool Board::is_O_turn() { return cur_mark == O; }
bool Board::is_X_turn() { return cur_mark == X; }

void Board::print_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i * 3 + j] == NOT_DECIDED) { std::cout << "_"; }
      else { std::cout << (board[i * 3 + j] == O ? "O" : "X"); }
    }
    std::cout << std::endl;
  }
}

bool Board::is_O_win() {
  for (int i = 0; i < 3; i++) {
    if (board[i * 3 + 0] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2]) {
      return board[i * 3 + 0] == O;
    }
    if (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i]) {
      return board[0 + i] == O;
    }
  }

  /* O__
     _O_
     __O の場合 */
  if (board[0] == board[4] && board[4] == board[8]) {
    return board[0] == O;
  }
  /* __O
     _O_
     O__ の場合 */
  if (board[2] == board[4] && board[4] == board[6]) {
    return board[2] == O;
  }
  return false;
}

bool Board::is_X_win() {
  for (int i = 0; i < 3; i++) {
    if (board[i * 3 + 0] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2]) {
      return board[i * 3 + 0] == X;
    }
    if (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i]) {
      return board[0 + i] == X;
    }
  }
  if (board[0] == board[4] && board[4] == board[8]) {
    return board[0] == X;
  }
  if (board[2] == board[4] && board[4] == board[6]) {
    return board[2] == X;
  }
  return false;
}

bool Board::is_draw() {
  if (is_O_win() || is_X_win()) { return false; }
  for (int i = 0; i < 9; i++) {
    if (board[i] == NOT_DECIDED) { return false; }
  }
  return true;
}

bool Board::is_game_end() {
  return is_O_win() || is_X_win() || is_draw();
}

bool Board::is_legal(int place) {
  return place >= 0 && place <= 8 && board[place] == NOT_DECIDED;
}


/* 単体テスト */
int board_unit_test() {
  Board *board;

  std::cout << "--putテスト--" << std::endl;
  board = new Board();
  std::cout << "正常系(成功する)" << std::endl;
  std::cout << "  成功 -> " << board->put(0 * 3 + 0) << std::endl;
  std::cout << "  成功 -> " << board->put(1 * 3 + 1) << std::endl;
  std::cout << "  成功 -> " << board->put(2 * 3 + 2) << std::endl;
  std::cout << "異常系(成功しない)" << std::endl;
  std::cout << "  成功 -> " << board->put(-1) << std::endl;
  std::cout << "  成功 -> " << board->put(9) << std::endl;
  std::cout << "  成功 -> " << board->put(1 * 3 + 1) << std::endl;
  std::cout << "盤面" << std::endl;
  board->print_board();
  delete board;

  std::cout << "--unputテスト--" << std::endl;
  board = new Board();
  std:: cout << "正常系(成功する)" << std::endl;
  board->put(0);
  std::cout << "  盤面(0の位置にXがある)" << std::endl;
  board->print_board();
  std::cout << "  成功 -> " << board->unput() << std::endl;
  std::cout << "  盤面(空になっている)" << std::endl;
  board->print_board();
  std::cout << "異常系(失敗する)" << std::endl;
  std::cout << "  成功 -> " << board->unput() << std::endl;
  delete board;

  std::cout << "--勝敗テスト--" << std::endl;
  std::cout << "斜め(Xが勝つ)" << std::endl;
  board = new Board();
  board->put(0);
  board->put(1);
  board->put(4);
  board->put(2);
  board->put(8);
  std::cout << "  結果(Oが勝つ?) -> " << board->is_O_win() << std::endl;
  std::cout << "  結果(Xが勝つ?) -> " << board->is_X_win() << std::endl;
  std::cout << "  結果(引き分け?) -> " << board->is_draw() << std::endl;
  delete board;
  std::cout << "斜め(Oが勝つ)" << std::endl;
  board = new Board();
  board->put(0);
  board->put(2);
  board->put(1);
  board->put(4);
  board->put(3);
  board->put(6);
  std::cout << "  結果(Oが勝つ?) -> " << board->is_O_win() << std::endl;
  std::cout << "  結果(Xが勝つ?) -> " << board->is_X_win() << std::endl;
  std::cout << "  結果(引き分け?) -> " << board->is_draw() << std::endl;
  delete board;
  std::cout << "縦(Oが勝つ)" << std::endl;
  board = new Board();
  board->put(1);
  board->put(0);
  board->put(2);
  board->put(3);
  board->put(4);
  board->put(6);
  std::cout << "  結果(Oが勝つ?) -> " << board->is_O_win() << std::endl;
  std::cout << "  結果(Xが勝つ?) -> " << board->is_X_win() << std::endl;
  std::cout << "  結果(引き分け?) -> " << board->is_draw() << std::endl;
  delete board;
  std::cout << "横(Xが勝つ)" << std::endl;
  board = new Board();
  board->put(0);
  board->put(3);
  board->put(1);
  board->put(4);
  board->put(2);
  std::cout << "  結果(Oが勝つ?) -> " << board->is_O_win() << std::endl;
  std::cout << "  結果(Xが勝つ?) -> " << board->is_X_win() << std::endl;
  std::cout << "  結果(引き分け?) -> " << board->is_draw() << std::endl;
  delete board;
  std::cout << "引き分け" << std::endl;
  board = new Board();
  board->put(0);
  board->put(1);
  board->put(2);
  board->put(4);
  board->put(3);
  board->put(6);
  board->put(5);
  board->put(8);
  board->put(7);
  std::cout << "  結果(Oが勝つ?) -> " << board->is_O_win() << std::endl;
  std::cout << "  結果(Xが勝つ?) -> " << board->is_X_win() << std::endl;
  std::cout << "  結果(引き分け?) -> " << board->is_draw() << std::endl;
  delete board;

  return 0;
}
