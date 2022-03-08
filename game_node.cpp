#include "game_node.hpp"

std::vector<GameNode> GameNode::children() {
  std::vector<GameNode> c;

  for (int i=0; i<9; i++) {
    if (board->is_legal(i)) {
      board->put(i);
      GameNode *n = new GameNode(board);
      c.push_back(*n);
      board->unput();
    }
  }

  return c;
}

bool GameNode::is_terminal() {
  return board->is_game_end();
}

/*
  Boardで勝利判定が出たとき、勝ったのは必ず最後の着手したプレイヤー。
  そのため、XとOのどちらが勝ったかで値を変えなくて良い。
 */
int GameNode::utility() {
  if (board->is_X_win() || board->is_O_win()) {
    return 1;
  }
  else {
    return 0;
  }
}

void game_node_unit_test() {
  Board *board;
  GameNode *node;

  std::cout << "--last_handテスト--" << std::endl;
  board = new Board();
  board->put(0);
  node = new GameNode(board);
  std::cout << "最後の着手(=0) -> " << node->last_hand() << std::endl;
  board->put(8);
  delete node;
  node = new GameNode(board);
  std::cout << "最後の着手(=8) -> " << node->last_hand() << std::endl;
  delete board, node;

  std::cout << "--is_terminal, utilityテスト--" << std::endl;
  board = new Board();
  node = new GameNode(board);
  std::cout << "終端節点ではない場合" << std::endl;
  std::cout << "  終端節点? -> " << node->is_terminal() << std::endl;
  std::cout << "  利得 -> " << node->utility() << std::endl;
  board->put(0);
  delete node;
  node = new GameNode(board);
  std::cout << "  終端節点? -> " << node->is_terminal() << std::endl;
  std::cout << "  利得 -> " << node->utility() << std::endl;
  delete node;
  board->put(8);
  node = new GameNode(board);
  std::cout << "  終端節点? -> " << node->is_terminal() << std::endl;
  std::cout << "  利得 -> " << node->utility() << std::endl;
  delete node, board;
  std::cout << "Xの勝ちの場合" << std::endl;
  board = new Board();
  board->put(0);
  board->put(3);
  board->put(1);
  board->put(4);
  board->put(2);
  node = new GameNode(board);
  std::cout << "  終端節点? -> " << node->is_terminal() << std::endl;
  std::cout << "  利得 -> " << node->utility() << std::endl;
  delete node, board;
  std::cout << "Oの勝ちの場合" << std::endl;
  board = new Board();
  board->put(0);
  board->put(3);
  board->put(1);
  board->put(4);
  board->put(6);
  board->put(5);
  node = new GameNode(board);
  std::cout << "  終端節点? -> " << node->is_terminal() << std::endl;
  std::cout << "  利得 -> " << node->utility() << std::endl;
  delete node, board;
  std::cout << "引き分け" << std::endl;
  board = new Board();
  board->put(1);
  board->put(0);
  board->put(3);
  board->put(2);
  board->put(4);
  board->put(5);
  board->put(6);
  board->put(7);
  board->put(8);
  node = new GameNode(board);
  std::cout << "  終端節点? -> " << node->is_terminal() << std::endl;
  std::cout << "  利得 -> " << node->utility() << std::endl;
  delete node, board;

  std::cout << "--childrenテスト--" << std::endl;
  board = new Board();
  node = new GameNode(board);
  std::cout << "0回着手している場合" << std::endl;
  for (auto& c : node->children()) {
    c.print_board();
    std::cout << "  合法手 -> " << c.last_hand() << std::endl;
  }
  delete node;
  board->put(1);
  board->put(0);
  board->put(3);
  board->put(2);
  board->put(4);
  node = new GameNode(board);
  std::cout << "5回着手している場合" << std::endl;
  for (auto& c : node->children()) {
    c.print_board();
    std::cout << "  合法手 -> " << c.last_hand() << std::endl;
  }
  delete node;
  board->put(5);
  board->put(6);
  board->put(7);
  board->put(8);
  node = new GameNode(board);
  std::cout << "9回着手している場合" << std::endl;
  for (auto& c : node->children()) {
    c.print_board();
    std::cout << "  合法手 -> " << c.last_hand() << std::endl;
  }
  delete node, board;
}
