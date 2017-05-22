/**
 * https://www.hackerrank.com/challenges/ctci-ransom-note
 */

#include <iostream>
#include <vector>

template<typename Character>
size_t alphabetic_index(Character c) {
  if (c >= 'a') {
    return c - 'a';
  } else {
    return c - 'A' + 26;
  }
}

class Trie {
 public:
  ~Trie() {
    for (Trie * c : child) {
      if (c != nullptr) {
        delete(c);
      }
    }
  }

  void add(const std::string &word) {
    Trie *root = this;
    for (auto c : word) {
      auto index = alphabetic_index(c);
      if (root->child[index] == nullptr) {
        root->child[index] = new Trie();
      }
      root = root->child[index];
    }
    root->counter += 1;
  }

  bool use(const std::string &word) {
    Trie *root = this;
    for (auto c : word) {
      auto index = alphabetic_index(c);
      if (root->child[index] == nullptr) {
        return false;
      }
      root = root->child[index];
    }
    if (root->counter > 0) {
      root->counter -= 1;
      return true;
    } else {
      return false;
    }
  }
 private:
  size_t counter = 0;
  Trie *child[52] = {nullptr};
};

int main() {
  int m, n;
  std::cin >> m >> n;
  Trie trie;
  std::string word;
  for (int i = 0; i < m; ++i) {
    std::cin >> word;
    trie.add(word);
  }
  bool doable = true;
  for (int i = 0; i < n; ++i) {
    std::cin >> word;
    doable &= trie.use(word);
  }
  std::cout << (doable ? "Yes" : "No") << std::endl;
}