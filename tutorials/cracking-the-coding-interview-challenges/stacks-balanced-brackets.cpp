/**
 * https://www.hackerrank.com/challenges/ctci-balanced-brackets
 */

#include <iostream>

class BalancedStack {
 public:
  bool is_balanced(const std::string &text) {
    for (const char c : text) {
      if (is_open(c)) {
        stack[++top] = c;
      } else {
        if (not match(stack[top], c)) {
          return false;
        } else {
          --top;
        }
      }
    }
    return top == 0;
  }
  void reset() {
    top = 0;
    stack[0] = 0;
  }
 private:
  inline bool is_open(char c) {
    return c == '(' or c == '[' or c == '{';
  }
  inline bool match (char l, char r) {
    return l == '(' and ')' == r
        or l == '[' and ']' == r
        or l == '{' and '}' == r;
  }
  char stack[1000] = {0};
  size_t top = 0;
};

int main() {
  int n;
  std::string line;
  BalancedStack stack;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> line;
    std::cout << (stack.is_balanced(line) ? "YES" : "NO") << std::endl;
    stack.reset();
  }
  return 0;
}
