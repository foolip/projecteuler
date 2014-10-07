#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

// An n-digit |multiplicand| multiplied by an m-digit |multiplier| gives an
// (n+m-1)- or (n+m)-digit |product|. The total number of digits is 9, so either
// 2*(n+m)-1=9 or 2*(n+m)=9. Only the former has integer solutions, so n+m=5.
// The |product| is thus always a 4-digit number and the |mulitplicand| and
// |multiplier| are either 1- and 4- or 2- and 3-digit numbers, respectively.

// There are only 9*8*7*6=3024 unique 4-digit numbers |product|s to consider,
// and for each of those 5*4*3*2*1=120 unique ways of arranging the remaining 5
// digits, after which one can simply test if either the 1- and 4- or 2- and
// 3-digit |multiplicand| and |multiplier| give the |product|. That's just
// 3024*120*2=725760 combinations to test.

namespace {

int SumOfProducts() {
  auto products = std::unordered_set<int>{};

  auto digits = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9};
  do {
    auto multiplicand_1 = digits[0];
    auto multiplier_4 =
        digits[1] + 10 * digits[2] + 100 * digits[3] + 1000 * digits[4];

    auto multiplicand_2 = digits[0] + 10 * digits[1];
    auto multiplier_3 = digits[2] + 10 * digits[3] + 100 * digits[4];

    auto product =
        digits[5] + 10 * digits[6] + 100 * digits[7] + 1000 * digits[8];

    if (multiplicand_1 * multiplier_4 == product ||
        multiplicand_2 * multiplier_3 == product)
      products.emplace(product);
  } while (std::next_permutation(digits.begin(), digits.end()));

  return std::accumulate(products.begin(), products.end(), 0);
}

}  // namespace

int main() {
  auto sum_of_products = SumOfProducts();
  std::cout << sum_of_products << std::endl;
  return 0;
}
