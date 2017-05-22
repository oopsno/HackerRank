/**
 * https://www.hackerrank.com/challenges/ctci-lonely-integer
 */

#include <iostream>

int main() {
  int n, a, lonely = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a;
    lonely ^= a;
  }
  std::cout << lonely << std::endl;
  return 0;
}