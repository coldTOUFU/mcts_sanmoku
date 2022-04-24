#include "mcts_player.hpp"

namespace mcts_player {
  void move(Board *board) {
    std::cout << "===============" << std::endl;
    std::cout << (board->get_mark_type() == O ? "O" : "X") << "のターン" << std::endl;
    std::cout << "現在の盤面" << std::endl;
    board->print_board();
    std::cout << std::endl;

    board->put(monte_carlo_tree_search(board));
  }

  int monte_carlo_tree_search(Board *board, int expansion_n, int playout_limit) {
    if (board->is_game_end()) { return -1; }

    MonteCarloNode *root_node = new MonteCarloNode(board);
    MonteCarloNode *cur_node = root_node;
    cur_node->expand_children();
    int playout_cnt = 0;

    while (playout_cnt < playout_limit) {
      if (cur_node->has_children()) {
        cur_node = cur_node->best_child(root_node->get_play_cnt());
        if (cur_node == NULL) {
          std::cerr << "best_childがNULLです。" << std::endl;
          exit(1);
        }
      }
      else {
        if (cur_node->get_play_cnt() >= expansion_n && !cur_node->is_terminal()) {
          cur_node->expand_children();
        }
        else {
          bool has_won = cur_node->has_won_playout(board->get_mark_type());
          playout_cnt++;

          while (!cur_node->is_root()) {
            cur_node->increment_play_cnt();
            if (has_won) { cur_node-> increment_win_cnt(); }
            cur_node = cur_node->get_parent();
          }
          cur_node->increment_play_cnt();
          if (has_won) { cur_node->increment_win_cnt(); }
        }
      }
    }

    int best_hand = root_node->best_hand();

    delete root_node;

    return best_hand;
  }
}
