/**
 * https://www.hackerrank.com/challenges/ctci-bubble-sort
 */

#include <iostream>
#include <algorithm>

template<typename T>
void summary(std::ostream &os, size_t swap, T fst, T lst) {
  os << "Array is sorted in " << swap << " swaps." << std::endl
     << "First Element: " << fst << std::endl
     << "Last Element: " << lst << std::endl;
}

template<typename T>
size_t bubble_sort(T a[], size_t n) {
  size_t swaps = 0;
  for (int i = 0; i < n; i++) {
    // Track number of elements swapped during a single array traversal
    size_t numberOfSwaps = 0;

    for (int j = 0; j < n - 1; j++) {
      // Swap adjacent elements if they are in decreasing order
      if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
        numberOfSwaps++;
      }
    }

    // If no elements were swapped during a traversal, array is sorted
    if (numberOfSwaps == 0) {
      break;
    } else {
      swaps += numberOfSwaps;
    }
  }
  return swaps;
}

int main() {
  size_t n;
  int *array = nullptr;
  std::cin >> n;
  array = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> array[i];
  }
  auto swap = bubble_sort(array, n);
  summary(std::cout, swap, array[0], array[n - 1]);
  delete[](array);
  return 0;
}