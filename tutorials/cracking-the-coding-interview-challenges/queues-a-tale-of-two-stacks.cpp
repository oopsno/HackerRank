/**
 * https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks
 */

#include <iostream>
#include <queue>

int main() {
  std::queue<int> queue;
  int q, t, x;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    std::cin >> t;
    switch (t) {
      case 1:
        std::cin >> x;
        queue.push(x);
        break;
      case 2:
        queue.pop();
        break;
      default:
        std::cout << queue.front() << std::endl;
    }
  }
  return 0;
}