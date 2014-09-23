#undef NDEBUG
#include <assert.h>
#include <math.h>
#include <iostream>
#include <limits>
#include <string>

namespace {

uint64_t TriangleNumber(uint64_t n) {
  assert(n > 0);
  return (n * (n + 1)) / 2;
}

bool IsTriangleNumber(uint32_t x) {
  // x = (n * (n + 1)) / 2 => n = (sqrt(8*x + 1) - 1) / 2, so x is a triangle
  // number if (sqrt(8*x + 1) - 1) / 2 is an integer.
  assert(x > 0);
  double n = (sqrt(8.0*x + 1.0) - 1.0) / 2.0;
  double _;
  return modf(n, &_) == 0.0;
}

uint32_t WordValue(std::string word) {
  assert(word.size() <= std::numeric_limits<uint32_t>::max() / 26);
  uint32_t sum = 0;
  for (char c : word) {
    assert('A' <= c && c <= 'Z');
    sum += static_cast<uint32_t>(c - 'A' + 1);
  }
  return sum;
}

bool IsTriangleWord(std::string word) {
  return IsTriangleNumber(WordValue(word));
}

#ifndef NDEBUG

bool TestTriangleNumber() {
  assert(TriangleNumber(1) == 1);
  assert(TriangleNumber(2) == 3);
  assert(TriangleNumber(3) == 6);
  assert(TriangleNumber(4) == 10);
  assert(TriangleNumber(5) == 15);
  assert(TriangleNumber(6) == 21);
  assert(TriangleNumber(7) == 28);
  assert(TriangleNumber(8) == 36);
  assert(TriangleNumber(9) == 45);
  assert(TriangleNumber(10) == 55);
  return true;
}

bool TestIsTriangleNumber() {
  uint32_t n = 1;
  uint64_t t_n = TriangleNumber(n);
  uint32_t i = 1;
  for (;;) {
    if (i < t_n) {
      assert(!IsTriangleNumber(i));
    } else if (i == t_n) {
      assert(IsTriangleNumber(i));
      n++;
      t_n = TriangleNumber(n);
    } else {
      assert(false);
    }
    if (i == std::numeric_limits<uint32_t>::max())
      return true;
    i++;
  }
  assert(false);
  return false;
}

bool TestWordValue() {
  assert(WordValue("") == 0);
  assert(WordValue("SKY") == 19 + 11 + 25);
  assert(WordValue("FALL") == 6 + 1 + 12 + 12);
  assert(WordValue("INJURY") == 9 + 14 + 10 + 21 + 18 + 25);
  return true;
}

bool TestIsTriangleWord() {
  assert(IsTriangleWord("SKY"));
  assert(!IsTriangleWord("FALL"));
  return true;
}

bool TestAll() {
  assert(TestTriangleNumber());
  assert(TestIsTriangleNumber());
  assert(TestWordValue());
  assert(TestIsTriangleWord());
  return true;
}

#endif

}  // namespace

int main() {
  assert(TestAll());
  return 0;
}
