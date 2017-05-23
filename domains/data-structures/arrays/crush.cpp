/**
 * https://www.hackerrank.com/challenges/crush
 * Hats off to @amansbhandari
 */

#include <iostream>
#include <algorithm>
#include <memory>
#include <cstdio>

int main() {
  int64_t n, m, a, b, k, current = 0, max = 0;
  std::cin >> n >> m;
  std::unique_ptr<int64_t[]> array(new int64_t[n + 2]());
  for (auto i = 0; i < m; ++i) {
    std::scanf("%lld%lld%lld", &a, &b, &k);
    array[a]     += k;
    array[b + 1] -= k;
  }
  for (auto i = 0; i < n + 1; ++i) {
    current += array[i];
    max = std::max(max, current);
  }
  std::cout << max << std::endl;
  return 0;
}
