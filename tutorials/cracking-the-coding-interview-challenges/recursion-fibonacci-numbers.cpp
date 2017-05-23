/**
 * https://www.hackerrank.com/challenges/ctci-fibonacci-numbers
 */

#include <iostream>
#include <type_traits>

template<size_t n>
struct fib : std::integral_constant<size_t, fib<n - 1>::value + fib<n - 2>::value> {};

template<>
struct fib<0> : std::integral_constant<size_t, 0> {};

template<>
struct fib<1> : std::integral_constant<size_t, 1> {};

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
  int n;
  std::cin >> n;
  std::cout << map_on_range<fib, 40>::value[n] << std::endl;
  return 0;
}
