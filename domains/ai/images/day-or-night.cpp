#include <iostream>
#include <cstdio>

int main() {
  int r, g, b;
  uint64_t total_gray = 0,  pixels = 0;
  while (std::scanf("%d,%d,%d", &b, &g, &r) != EOF) {
    total_gray += (r + g + b) / 3;
    pixels += 1;
  }
  const double rate = double(total_gray) / double(pixels) / 255;
  std::cout << (rate > 0.3 ? "day" : "night") << std::endl;
  return 0;
}
