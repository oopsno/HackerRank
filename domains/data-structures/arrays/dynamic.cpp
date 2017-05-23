#include <iostream>
#include <map>
#include <vector>

int main() {
  std::map<int, std::vector<int>> dyn;
  int n, q, op, x, y, seq, last_answer = 0;
  std::cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    std::cin >> op >> x >> y;
    seq = (x ^ last_answer) % n;
    if (op == 1) {
      if (dyn.find(seq) == dyn.end()) {
        dyn[seq] = {y};
      } else {
        dyn[seq].push_back(y);
      }
    } else {
      const auto &s = dyn[seq];
      last_answer = s[y % s.size()];
      std::cout << last_answer << std::endl;
    }
  }
}