/**
 * https://www.hackerrank.com/challenges/ctci-recursive-staircase
 */

#include <iostream>
#include <type_traits>

template<size_t n>
struct step : std::integral_constant<size_t, step<n - 1>::value + step<n - 2>::value + step<n - 3>::value> {};

template<>
struct step<0> : std::integral_constant<size_t, 0> {};

template<>
struct step<1> : std::integral_constant<size_t, 1 + 0 + 0> {};

template<>
struct step<2> : std::integral_constant<size_t, 1 + 1 + 0> {};

template<>
struct step<3> : std::integral_constant<size_t, 1 + 2 + 1> {};

template<size_t ...values>
struct compile_time_array {
  static const size_t value[sizeof...(values)];
};

template<size_t ...values>
const size_t compile_time_array<values...>::value[sizeof...(values)] = {values...};

template<template<size_t> class f, size_t end, size_t ...args>
struct map_on_range : map_on_range<f, end - 1, end, args...> {};

template<template<size_t> class f, size_t ...args>
struct map_on_range<f, 0, args...> : compile_time_array<f<0>::value, f<args>::value...> {};

int main() {
  int s, n;
  std::cin >> s;
  for (int i = 0; i < s; ++i) {
    std::cin >> n;
    std::cout << map_on_range<step, 36>::value[n] << std::endl;
  }
  return 0;
}