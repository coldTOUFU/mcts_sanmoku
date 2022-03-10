#include "pmc_player.hpp"

namespace pmc_player {
  void move(Board *board) {
    std::cout << "===============" << std::endl;
    std::cout << (board->get_mark_type() == O ? "O" : "X") << "のターン" << std::endl;
    std::cout << "現在の盤面" << std::endl;
    board->print_board();
    std::cout << std::endl;

    board->put(primary_monte_carlo(board));
  }

  int primary_monte_carlo(Board *board, int playout_num) {
    GameNode *node = new GameNode(board);
    std::vector<GameNode> children = node->children();
    /* playout_results[i] := children[i]のプレイアウトに対して、{ 試行回数 / 勝利数 }。 */
    std::vector<std::pair<int, int>> playout_results(children.size(), { 0, 0 });

    std::random_device seed_gen;
    std::default_random_engine rand_engine(seed_gen());
    std::uniform_int_distribution<> dist(0, children.size() - 1);

    for (int i = 0; i < playout_num; i++) {
      int idx = dist(rand_engine);
      int result = playout(&(children[idx]));

      playout_results[idx].first++;
      if (board->get_mark_type() == X) {
        playout_results[idx].second += result;
      }
      else {
        playout_results[idx].second -= result;
      }
    }

    int best_hand = 0;
    double max_prob = -1.0;
    for (int i = 0; i < children.size(); i++) {
      double prob = (double)(playout_results[i].second) / (double)(playout_results[i].first);
      std::cout << std::endl;
      if (max_prob < prob) {
        max_prob = prob;
        best_hand = children[i].last_hand();
      }
    }

    return best_hand;
  }

  int playout(GameNode *original_node) {
    GameNode *node = new GameNode(*original_node);
    std::random_device seed_gen;
    std::default_random_engine rand_engine(seed_gen());

    while (!node->is_terminal()) {
      std::vector<GameNode> children = node->children();
      std::shuffle(children.begin(), children.end(), rand_engine);
      delete node;
      node = new GameNode(children[0]);
    }
    int result = node->utility();
    delete node;

    return result;
  }
}
