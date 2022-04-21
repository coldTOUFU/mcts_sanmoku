#ifndef BOARD_HPP_
#define BOARD_HPP_

#include<iostream>
#include<stack>
#define NOT_DECIDED -1
#define O 0
#define X 1

class Board {
 public:
  Board() {
    for (int i = 0; i < 9; i++) { board[i] = NOT_DECIDED; }
    cur_mark = X;
  };
  Board(const Board& b) {
    for (int i = 0; i < 9; i++) { board[i] = b.board[i]; }
    cur_mark = b.cur_mark;
  }

  void copy_from(Board *b);
  bool put(int place);
  bool unput();
  int get_mark_type() { return cur_mark; }
  int get_last_put() { return put_log.empty() ? -1 : put_log.top(); }
  void print_board(); 
  bool is_O_turn();
  bool is_X_turn();
  bool is_legal(int place);
  bool is_O_win();
  bool is_X_win();
  bool is_draw();
  bool is_game_end();

 private:
  std::stack<int> put_log;
  int board[9];
  int cur_mark;
};

int board_unit_test();

#endif // BOARD_HPP_
