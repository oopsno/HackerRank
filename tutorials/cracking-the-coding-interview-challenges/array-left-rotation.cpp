/**
 * https://www.hackerrank.com/challenges/ctci-array-left-rotation
 */

#include <algorithm>
#include <vector>
#include <iostream>

void rotate(std::vector<int> &xs, const int shift) {
  std::vector<int> ys(shift);
  std::copy(xs.cbegin(), xs.cbegin() + shift, ys.begin());
  std::copy(xs.cbegin() + shift, xs.cend(), xs.begin());
  std::copy(ys.cbegin(), ys.cend(), xs.begin() + (xs.size() - shift));
}

int main() {
  int length, shift;
  std::cin >> length >> shift;
  std::vector<int> xs(length);
  for (int i = 0; i < length; ++i) {
    std::cin >> xs[i];
  }
  rotate(xs, shift % length);
  for (int i = 0; i < length; ++i) {
    std::cout << xs[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
