/**
 * https://www.hackerrank.com/contests/projecteuler/challenges/euler001
 */

#include <iostream>

template<uint64_t r>
inline uint64_t sum_of(uint64_t n) {
  const uint64_t k = (n - 1) / r;
  return r * k * (1 + k) / 2;
}

uint64_t solve(uint64_t n) {
  return sum_of<3>(n) + sum_of<5>(n) - sum_of<15>(n);
}

int main() {
  uint64_t t, n;
  std::cin >> t;
  for (uint64_t i = 0; i < t; ++i) {
    std::cin >> n;
    std::cout << solve(n) << std::endl;
  }
  return 0;
}