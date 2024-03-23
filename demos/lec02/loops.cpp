#include <iostream>
#include <vector>

// DEMO: loops, vectors

int main() {
  // example 1: while (count from 0 to 8, evens only)
  /*
  int i = 0;
  while (i <= 8) {
    std::cout << i << "\n";
    i+=2;
  }
  */

  // example 2: for
  /*
  for (int i = 0; i <= 8; i+=2) {
    std::cout << i << "\n";
  }
  */

  // example 3: for, looping over indexes
  /*
  std::vector<int> nums{5,4,3,2,9,8,7,6};
  for (int i = 0; i <= 6; i+=2) {
    std::cout << "index " << i << " => " << nums[i] << "\n";
  }
  */

  // example 4: for each loop
  std::vector<int> nums{5,4,3,2,9,8,7,6};
  for (auto val : nums) {
    std::cout << val << "\n";
  }
}
