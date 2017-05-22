/**
 * https://www.hackerrank.com/contests/projecteuler/challenges/euler002
 */

#include <iostream>
#include <type_traits>

template<size_t n>
struct fib : std::integral_constant<size_t, fib<n - 1>::value + fib<n - 2>::value> {};

template<>
struct fib<0> : std::integral_constant<size_t, 1> {};

template<>
struct fib<1> : std::integral_constant<size_t, 2> {};

template<size_t... values>
struct compile_time_array {
  static const size_t value[sizeof...(values)];
};

template<size_t... values>
const size_t compile_time_array<values...>::value[sizeof...(values)] = {values...};

template<size_t value, typename CTArray>
struct cons;

template<size_t value, size_t... xs>
struct cons<value, compile_time_array<xs...>> {
  using type =compile_time_array<value, xs...>;
};

template<typename CTArray, typename Selector=void>
struct even_filter;

template<size_t head, size_t... tail>
struct even_filter<compile_time_array<head, tail...>, std::enable_if_t<(head & 1) == 0>> {
  using type = typename cons<head, typename even_filter<compile_time_array<tail...>>::type>::type;
};

template<size_t head, size_t... tail>
struct even_filter<compile_time_array<head, tail...>, std::enable_if_t<(head & 1) == 1>> {
  using type = typename even_filter<compile_time_array<tail...>>::type;
};

template<>
struct even_filter<compile_time_array<>, void> {
  using type = compile_time_array<>;
};

template<template<size_t> typename f, size_t end, size_t ...args>
struct map_on_range : map_on_range<f, end - 1, end, args...> {};

template<template<size_t> typename f, size_t ...args>
struct map_on_range<f, 0, args...> {
  using type = compile_time_array<f<0>::value, f<args>::value...>;
};

int main() {
  using even_fib = even_filter<map_on_range<fib, 90>::type>::type;
  const auto length = sizeof(even_fib::value) / sizeof(size_t);
  size_t t, n;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::cin >> n;
    size_t sum = 0;
    for (int j = 0; j < length and even_fib::value[j] <= n; ++j) {
      sum += even_fib::value[j];
    }
    std::cout << sum << std::endl;
  }
  return 0;
}
