#include <iostream>
#include <utility>

int divide(int x, int y);
double divide(double x, double y);

namespace safe::math {
  // return: result, whether it is a valid result
  std::pair<int, bool> divide(int x, int y) {
    std::cout << "safe divide\n";
    if (y != 0) {
      return {x/y, true};
    } else {
      return {-1, false};
    }
  }
}

int main() {
  if (auto [num, ok] = safe::math::divide(2,-2); ok) {
    std::cout << num << "\n";
  } else {
    std::cout << "cannot divide!\n";
  }

  /*
  std::cout << divide(7,2) << "\n";
  std::cout << divide(7.0,2.0) << "\n";
  */
  // std::cout << divide(7.0,2) << "\n"; // ambiguous

  // the main function returns 0 by default.
  // no other function has a default return value.
}

int divide(int x, int y) {
  return x/y;
}

double divide(double x, double y) {
  return x/y;
}

