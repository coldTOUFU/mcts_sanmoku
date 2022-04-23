#ifndef MONTE_CARLO_NODE_HPP_
#define MONTE_CARLO_NODE_HPP_

#include <algorithm>
#include <random>
#include <vector>
#include "board.hpp"

class MonteCarloNode {
 public:
  MonteCarloNode() {
    board = new Board();
    children = {};
    parent = NULL;
    win_cnt = 0;
    play_cnt = 0;
  }
  /* ルートノード用 */
  MonteCarloNode(Board *b) {
    board = new Board();
    board->copy_from(b);
    children = {};
    parent = NULL;
    win_cnt = 0;
    play_cnt = 0;
  }
  /* ノード展開用 */
  MonteCarloNode(Board *b, MonteCarloNode *p) {
    board = new Board();
    board->copy_from(b);
    children = {};
    parent = p;
    win_cnt = 0;
    play_cnt = 0;
  }

  ~MonteCarloNode() {
    delete board;
    children.clear();
  }

  int get_play_cnt() { return play_cnt; }
  int get_win_cnt() { return win_cnt; }
  MonteCarloNode *get_parent() { return parent; }

  void increment_play_cnt() { play_cnt++; }
  void increment_win_cnt() { win_cnt++; }

  int last_hand() { return board->get_last_put(); }

  bool is_root() {
    return parent == NULL;
  }

  bool has_children() { return children.size() > 0; }

  bool is_terminal() { return board->is_game_end(); }

  void print_board() {
    board->print_board();
  }

  void expand_children() {
    for (int i = 0; i < 9; i++) {
      if (board->is_legal(i)) {
        board->put(i);
        children.push_back(new MonteCarloNode(board, this));
        board->unput();
      }
    }
  }

  MonteCarloNode* best_child(int play_cnt_sum);

  bool has_won_playout();

  int best_hand();

 private:
  Board *board;
  MonteCarloNode *parent;
  std::vector<MonteCarloNode*> children;
  int play_cnt;
  int win_cnt;
};
#endif // MONTE_CARLO_NODE_HPP_
