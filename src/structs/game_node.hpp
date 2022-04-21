#ifndef GAME_NODE_HPP_
#define GAME_NODE_HPP_

#include<vector>
#include "board.hpp"

class GameNode {
 public:
  static const int INF_VALUE = 100;

  GameNode() {
    board = new Board();
  }

  GameNode(const GameNode& node) {
    board = new Board();
    board->copy_from(node.board);
  }

  GameNode(Board *b) {
    board = new Board();
    board->copy_from(b);
  }

  std::vector<GameNode> children();

  int last_hand() { return board->get_last_put(); }

  bool is_terminal();

  int utility();

  void print_board() {
    board->print_board();
  };

 protected:
  Board *board;
};

void game_node_unit_test();

#endif // GAME_NODE_HPP_
