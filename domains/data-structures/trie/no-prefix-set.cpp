#include <iostream>
#include <algorithm>

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

  bool good(const std::string &word) {
    auto root = this;
    for (auto i = 0; i < word.size(); ++i) {
      auto index = word[i] - offset;
      if (root->nodes[index] == nullptr) {
        root->nodes[index] = new Trie<Element, N, offset>();
      }
      root = root->nodes[index];
      if (root->counter != 0) {
        return false;
      }
    }
    root->counter += 1;
    return std::count(root->nodes, root->nodes + N, nullptr) == N;
  }
 private:
  Trie<Element, N, offset>* nodes[N] = {nullptr};
  size_t counter = 0;
};

int main() {
  Trie<char, 'j' - 'a' + 1, 'a'> trie;
  size_t n;
  std::string word;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> word;
    if (not trie.good(word)) {
      std::cout << "BAD SET" << std::endl << word << std::endl;
      return 0;
    }
  }
  std::cout << "GOOD SET";
  return 0;
}
