/**
 * https://www.hackerrank.com/challenges/ctci-comparator-sorting
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Player {
  std::string name;
  int score;
};

std::vector<Player> comparator(std::vector<Player> players) {
  auto sorted = players;
  std::sort(sorted.begin(), sorted.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs.score == rhs.score) {
      return lhs.name < rhs.name;
    } else {
      return lhs.score > rhs.score;
    }
  });
  return sorted;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Player> players;
  std::string name;
  int score;
  for (int i = 0; i < n; i++) {
    std::cin >> name >> score;
    Player p1;
    p1.name = name, p1.score = score;
    players.push_back(p1);
  }

  std::vector<Player> answer = comparator(players);
  for (int i = 0; i < answer.size(); i++) {
    std::cout << answer[i].name << " " << answer[i].score << std::endl;
  }
  return 0;
}
