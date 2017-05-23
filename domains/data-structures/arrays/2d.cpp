#include <iostream>
#include <array>
#include <algorithm>
#include <memory>
#include <iterator>

template<typename T, size_t Row, size_t Col>
class Matrix {
 public:
  Matrix(): elements(new std::array<T, Row * Col>()) { }
  explicit Matrix(T value): Matrix{} {
    std::fill(elements.get(), elements.get() + Row * Col, value);
  }
  Matrix(std::initializer_list<T> xs): Matrix{} {
    std::copy_n(xs.begin(), std::min(xs.size(), Row * Col), begin());
  }
  template <size_t KRow, size_t KCol>
  auto conv(const Matrix<T, KRow, KCol> &kernel) {
    static_assert(Row >= KRow and Col >= KCol, "kernel size miss matched");
    constexpr size_t nr = Row - KRow + 1, nc = Col - KCol + 1;
    Matrix<T, nr, nc> result;
    for (auto i = 0; i < nr; ++i) {
      for (auto j = 0; j < nc; ++j) {
        result.at(i, j) = conv_op(kernel, i, j);
      }
    }
    return result;
  };
  inline const auto cbegin() const {
    return elements->cbegin();
  }
  inline const auto cend() const {
    return elements->cend();
  }
  inline auto begin() {
    return elements->begin();
  }
  inline auto end() {
    return elements->end();
  }
  inline const T at(size_t row, size_t col) const {
    return elements->at(row * Col + col);
  }
  inline T& at(size_t row, size_t col) {
    return elements->at(row * Col + col);
  }
  void dump(std::ostream &os) {
    for (int i = 0; i < Row; ++i) {
      for (int j = 0; j < Col; ++j) {
        os << at(i, j) << "\t";
      }
      os << std::endl;
    }
  }
 private:
  template <size_t KRow, size_t KCol>
  inline T conv_op(const Matrix<T, KRow, KCol> &kernel, const size_t lt_row, const size_t lt_col) {
    T sum = 0;
    for (int i = 0; i < KRow; ++i) {
      for (int j = 0; j < KCol; ++j) {
        sum += at(lt_row + i, lt_col + j) * kernel.at(i, j);
      }
    }
    return sum;
  };
  std::unique_ptr<std::array<T, Row * Col>> elements;
};

int main() {
  Matrix<int, 6, 6> matrix{};
  Matrix<int, 3, 3> kernel{1, 1, 1, 0, 1, 0, 1, 1, 1};
  auto reader = std::istream_iterator<int>(std::cin);
  std::copy_n(reader, 36, matrix.begin());
  auto hourglasses = matrix.conv(kernel);
  #ifndef NDEBUG
  matrix.dump(std::cout);
  kernel.dump(std::cout);
  hourglasses.dump(std::cout);
  #endif
  const int max_hourglass_value = *std::minmax_element(hourglasses.cbegin(), hourglasses.cend()).second;
  std::cout << max_hourglass_value << std::endl;
  return 0;
}
