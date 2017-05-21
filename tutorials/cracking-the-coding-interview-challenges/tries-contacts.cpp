/**
 * https://www.hackerrank.com/challenges/ctci-contacts?h_r=next-challenge&h_v=zen
 */

#include <algorithm>
#include <iterator>
#include <iostream>

template <typename Element, size_t N, Element offset>
class Trie {
 public:
  ~Trie() {
    for (int i = 0; i < N; ++i) {
      auto node = nodes[i];
      if (node != nullptr) {
        delete(node);
      }
    }
  }

  template <typename Iteratable>
  void add(const Iteratable& word) {
    auto root = this;
    for (auto c = std::cbegin(word); *c and c != std::cend(word); ++c) {
      auto index = *c - offset;
      if (root->nodes[index] == nullptr) {
        root->nodes[index] = new Trie<Element, N, offset>();
      }
      root = root->nodes[index];
      root->counter += 1;
    }
  }

  template <typename Iteratable>
  size_t find(const Iteratable& word) {
    auto root = this;
    for (auto c = std::cbegin(word); *c and c != std::cend(word); ++c) {
      auto index = *c - offset;
      if (root->nodes[index] == nullptr) {
        return 0;
      }
      root = root->nodes[index];
    }
    return root->counter;
  }
 private:
  Trie<Element, N, offset>* nodes[N] = {nullptr};
  size_t counter = 0;
};

int main() {
  Trie<char, 26, 'a'> trie;
  int N;
  std::string command, word;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> command >> word;
    if (command == "add") {
      trie.add(word);
    } else {
      std::cout << trie.find(word) << std::endl;
    }
  }
  return 0;
}