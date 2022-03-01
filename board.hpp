#ifndef BOARD_HPP_
#define BOARD_HPP_

#include<iostream>
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
  int get_mark_type() { return cur_mark; }

  bool put(int place);
  bool is_O_turn();
  bool is_X_turn();
  void print_board(); 
  bool is_O_win();
  bool is_X_win();
  bool is_draw();
  bool is_game_end();

 private:
  int board[9];
  int cur_mark;
  bool is_legal(int place);
};

#endif // BOARD_HPP_
