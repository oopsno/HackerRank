#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdio>

class SegmentTree {
 public:
  SegmentTree(size_t start, size_t end, size_t value = 0) : start(start), end(end), value(value) {}
  ~SegmentTree() {
    if (left != nullptr) {
      delete(left);
      delete(right);
    }
  }
  inline void accumulate(size_t from, size_t to, size_t x) {
    accumulate(this, from, to, x);
  }
  inline size_t max() const {
    return value;
  }
  void dump(std::ostream& os, size_t indent_level = 0) const {
    auto padding = build_indent(indent_level);
    if (left != nullptr) {
      os << padding << "[" << start << ", " << end << "] with max value: " << value << std::endl;
      left->dump(os, indent_level + 1);
      right->dump(os, indent_level + 1);
    } else {
      os << padding << "[" << start << ", " << end << "] = " << value << std::endl;
    }
  }
  auto to_vector() {
    std::vector<size_t> v(end - start + 1, 0);
    to_vector(this, v, start);
    return v;
  }
  size_t value, start, end;
  SegmentTree *left = nullptr;
  SegmentTree *right = nullptr;
 private:
  static void to_vector(SegmentTree* root, std::vector<size_t> &v, size_t offset) {
    if (root->left == nullptr) {
      for (auto i = root->start; i <= root->end; ++i) {
        v[i - offset] = root->value;
      }
    } else {
      to_vector(root->left,  v, offset);
      to_vector(root->right, v, offset);
    }
  }
  static std::string build_indent(size_t level) {
    std::stringstream ss;
    for (int i = 0; i < level; ++i) {
      ss << "  ";
    }
    return ss.str();
  }
  static inline size_t accumulate(SegmentTree *root, size_t start, size_t end, size_t x) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left != nullptr) {
      root->value = std::max(accumulate(root->left, start, end, x), accumulate(root->right, start, end, x));
    } else {
      root->value = update(root, start, end, x);
    }
    return root->value;
  }
  static inline size_t update(SegmentTree *root, size_t start, size_t end, size_t x) {
    size_t acc = root->value + x;
    if (start <= root->start and end >= root->end) {
      root->value = acc;
    } else if (start <= root->start and root->start <= end and end <= root->end) {
      root->left  = new SegmentTree(root->start, end,       acc);
      root->right = new SegmentTree(end + 1,     root->end, root->value);
    } else if (root->start < start and end < root->end) {
      auto *left  = new SegmentTree(root->start, start - 1, root->value);
      auto *mid   = new SegmentTree(start,       end,       acc);
      auto *right = new SegmentTree(end + 1,     root->end, root->value);
      auto *tmp   = new SegmentTree(root->start, end,       acc);
      tmp->left   = left;
      tmp->right  = mid;
      root->left  = tmp;
      root->right = right;
    } else if (root->start <= start and start <= root->end and root->end <= end) {
      root->left  = new SegmentTree(root->start, start - 1, root->value);
      root->right = new SegmentTree(start,       root->end, acc);
    } else {
      return root->value;
    }
    return acc;
  }
};

int _main() {
  SegmentTree s(1, 5);
  s.accumulate(1, 2, 100);
  s.accumulate(2, 5, 100);
  s.accumulate(3, 4, 100);
  s.dump(std::cout);
  auto printer = std::ostream_iterator<size_t>(std::cout, ", ");
  auto vec = s.to_vector();
  std::copy(vec.cbegin(), vec.cend(), printer);
  return 0;
}

int main() {
  uint64_t n, m, a, b, k;
  std::cin >> n >> m;
  SegmentTree seg(1, n);
  std::vector<uint64_t> xs(n, 0);
  auto printer = std::ostream_iterator<size_t>(std::cout, " ");
  for (int i = 0; i < m; ++i) {
    std::scanf("%lld%lld%lld", &a, &b, &k);
     seg.accumulate(a, b, k);
    for (auto i = a - 1; i < b; ++i) {
      xs[i] += k;
    }
     std::cout << "=============" << std::endl;
     std::cout << "a = " << a << " b = " << b << " k = " << k << std::endl;
     seg.dump(std::cout);
     auto vec = seg.to_vector();
     std::copy(xs.cbegin(), xs.cend(), printer);
     std::cout << std::endl;
     std::copy(vec.cbegin(), vec.cend(), printer);
     std::cout << std::endl;
     for (auto i = 0; i < n; ++i) {
       if (xs[i] != vec[i]) {
         std::cout << "DIFF: " << i + 1 << std::endl;
         exit(-1);
       }
     }
  }
  std::cout << seg.max() << std::endl;
  return 0;
}
