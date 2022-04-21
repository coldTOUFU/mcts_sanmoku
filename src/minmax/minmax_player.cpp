#include "minmax_player.hpp"

namespace minmax_player {
  void move(Board *board) {
    std::cout << "===============" << std::endl;
    std::cout << (board->get_mark_type() == O ? "O" : "X") << "のターン" << std::endl;
    std::cout << "現在の盤面" << std::endl;
    board->print_board();
    std::cout << std::endl;

    board->put(best_hand(board));
  }

  int best_hand(Board *board) {
    int my_mark = board->get_mark_type();
    GameNode *node = new GameNode(board);
    int hand = -1;

    /*
      得点はXが勝ったら1点、Oが勝ったら-1点なので、
      自分のマークに合わせて最良の着手を選ぶ処理を切り替える。
    */
    if (my_mark == X) {
      int value = -GameNode::INF_VALUE;
      for (auto& n_c : node->children()) {
          int child_val = min_value(&n_c);
          if (child_val > value) {
            hand = n_c.last_hand();
            value = child_val;
          }
      }
    }
    else {
      int value = GameNode::INF_VALUE;
      for (auto& n_c : node->children()) {
        int child_val = max_value(&n_c);
        if (child_val < value) {
          hand = n_c.last_hand();
          value = child_val;
        }
      }
    }

    return hand;
  }

  int max_value(GameNode *n) {
    if (n->is_terminal()) { return n->utility(); }

    int value = -GameNode::INF_VALUE;
    for (auto& n_c : n->children()) {
      value = std::max(value, min_value(&n_c));
    }

    return value;
  }

  int min_value(GameNode *n) {
    if (n->is_terminal()) { return n->utility(); }

    int value = GameNode::INF_VALUE;
    for (auto& n_c : n->children()) {
      value = std::min(value, max_value(&n_c));
    }

    return value;
  }
}

void minmax_player_unit_test() {
  Board *board;
  GameNode *node;

  std::cout << "Xからみてまだ必勝でも必敗でもない場合" << std::endl;
  board = new Board();
  node = new GameNode(board);
  std::cout << "  盤面" << std::endl;
  board->print_board();
  std::cout << "  max_value -> " << minmax_player::max_value(node) << std::endl;
  std::cout << "  hand -> " << minmax_player::best_hand(board) << std::endl;
  std::cout << "  盤面(元の盤面の値が破壊されていないか)" << std::endl;
  board->print_board();
  std::cout << std::endl;
  delete board, node;

  std::cout << "Xからみて必勝の場合" << std::endl;
  board = new Board();
  board->put(0);
  board->put(3);
  board->put(1);
  board->put(4);
  node = new GameNode(board);
  std::cout << "  盤面" << std::endl;
  board->print_board();
  std::cout << "  max_value -> " << minmax_player::max_value(node) << std::endl;
  std::cout << "  hand -> " << minmax_player::best_hand(board) << std::endl;
  std::cout << "  盤面(元の盤面の値が破壊されていないか)" << std::endl;
  board->print_board();
  std::cout << std::endl;
  delete board, node;

  std::cout << "Xからみて必敗の場合" << std::endl;
  board = new Board();
  board->put(1);
  board->put(4);
  board->put(3);
  board->put(7);
  board->put(5);
  board->put(8);
  node = new GameNode(board);
  std::cout << "  盤面" << std::endl;
  board->print_board();
  std::cout << "  max_value -> " << minmax_player::max_value(node) << std::endl;
  std::cout << "  hand -> " << minmax_player::best_hand(board) << std::endl;
  std::cout << "  盤面(元の盤面の値が破壊されていないか)" << std::endl;
  board->print_board();
  std::cout << std::endl;
  delete board, node;

  std::cout << "Xからみて引き分けの場合" << std::endl;
  board = new Board();
  board->put(0);
  board->put(2);
  board->put(1);
  board->put(3);
  board->put(6);
  board->put(8);
  node = new GameNode(board);
  std::cout << "  盤面" << std::endl;
  board->print_board();
  std::cout << "  max_value -> " << minmax_player::max_value(node) << std::endl;
  std::cout << "  hand -> " << minmax_player::best_hand(board) << std::endl;
  std::cout << "  盤面(元の盤面の値が破壊されていないか)" << std::endl;
  board->print_board();
  std::cout << std::endl;
  delete board, node;

  std::cout << "Oからみてまだ必勝でも必敗でもない場合" << std::endl;
  board = new Board();
  board->put(0);
  node = new GameNode(board);
  std::cout << "  盤面" << std::endl;
  board->print_board();
  std::cout << "  min_value -> " << minmax_player::min_value(node) << std::endl;
  std::cout << "  hand -> " << minmax_player::best_hand(board) << std::endl;
  std::cout << "  盤面(元の盤面の値が破壊されていないか)" << std::endl;
  board->print_board();
  std::cout << std::endl;
  delete board, node;
  
  std::cout << "Oからみて必勝の場合" << std::endl;
  board = new Board();
  board->put(3);
  board->put(0);
  board->put(7);
  board->put(1);
  board->put(8);
  node = new GameNode(board);
  std::cout << "  盤面" << std::endl;
  board->print_board();
  std::cout << "  min_value -> " << minmax_player::min_value(node) << std::endl;
  std::cout << "  hand -> " << minmax_player::best_hand(board) << std::endl;
  std::cout << "  盤面(元の盤面の値が破壊されていないか)" << std::endl;
  board->print_board();
  std::cout << std::endl;
  delete board, node;

  std::cout << "Oからみて必敗の場合" << std::endl;
  board = new Board();
  board->put(4);
  board->put(1);
  board->put(7);
  board->put(3);
  board->put(8);
  board->put(5);
  board->put(2);
  node = new GameNode(board);
  std::cout << "  盤面" << std::endl;
  board->print_board();
  std::cout << "  min_value -> " << minmax_player::min_value(node) << std::endl;
  std::cout << "  hand -> " << minmax_player::best_hand(board) << std::endl;
  std::cout << "  盤面(元の盤面の値が破壊されていないか)" << std::endl;
  board->print_board();
  std::cout << std::endl;
  delete board, node;

  std::cout << "Oからみて引き分けの場合" << std::endl;
  board = new Board();
  board->put(2);
  board->put(0);
  board->put(3);
  board->put(5);
  board->put(8);
  board->put(6);
  board->put(1);
  node = new GameNode(board);
  std::cout << "  盤面" << std::endl;
  board->print_board();
  std::cout << "  min_value -> " << minmax_player::min_value(node) << std::endl;
  std::cout << "  hand -> " << minmax_player::best_hand(board) << std::endl;
  std::cout << "  盤面(元の盤面の値が破壊されていないか)" << std::endl;
  board->print_board();
  std::cout << std::endl;
  delete board, node;
}
