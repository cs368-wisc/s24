#include <iostream>
#include <utility>

#include "mylib.h"
#include "mylib.h"

int main() {
  std::cout << "hi\n";
  if (auto [num, ok] = safe::math::divide(2,-2); ok) {
    std::cout << num << "\n";
  } else {
    std::cout << "cannot divide!\n";
  }
}
