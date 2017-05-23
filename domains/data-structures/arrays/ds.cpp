#include <algorithm>
#include <iostream>

int main() {
  size_t n;
  std::cin >> n;
  auto array = std::make_unique<int[]>(n);
  auto reader = std::istream_iterator<int>(std::cin);
  auto printer = std::ostream_iterator<int>(std::cout, "\n");
  std::copy_n(reader, n, array.get());
  std::reverse_copy(array.get(), array.get() + n, printer);
  return 0;
}
