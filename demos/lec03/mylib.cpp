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

int divide(int x, int y) {
  return x/y;
}

double divide(double x, double y) {
  return x/y;
}
