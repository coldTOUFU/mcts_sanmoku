#include "monte_carlo_node.hpp"

MonteCarloNode* MonteCarloNode::best_child(int play_cnt_sum) {
  if (!has_children()) { return NULL; }

  MonteCarloNode* best_node = NULL;
  double best_ucb1 = -1;
  for (const auto& child: children) {
    if (child->play_cnt == 0) { return child; }

    double ucb1 = (double)child->win_cnt / child->play_cnt + std::sqrt(2.0 * std::log2(play_cnt_sum) / child->play_cnt);
    if (ucb1 > best_ucb1) {
      best_node = child;
      best_ucb1 = ucb1;
    }
  }

  return best_node;
}

bool MonteCarloNode::has_won_playout() {
  std::random_device seed_gen;
  std::default_random_engine rand_engine(seed_gen());
  Board *b = new Board(); b->copy_from(board);

  while (!b->is_game_end()) {
    std::vector<int> hands;
    for (int hand = 0; hand < 9; hand++) {
      if (b->is_legal(hand)) { hands.push_back(hand); }
    }
    std::shuffle(hands.begin(), hands.end(), rand_engine);
    b->put(hands[0]);
  }

  if (board->get_mark_type() == X && b->is_X_win()) { return true; }
  if (board->get_mark_type() == O && b->is_O_win()) { return true; }
  return false;
}

int MonteCarloNode::best_hand() {
  if (!has_children()) { return -1; }

  int best_hand = -1;
  int play_cnt_max = -1;
  for (const auto& child: children) {
    printf("hand: %d\n", child->last_hand());
    printf("cnt: %d\n", child->play_cnt);
    if (child->play_cnt > play_cnt_max) {
      best_hand = child->last_hand();
      play_cnt_max = child->play_cnt;
    }
  }

  return best_hand;
}


