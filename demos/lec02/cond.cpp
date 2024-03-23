#include <iostream>
#include <bitset>

// DEMO: blocks, bools, conditions, bitsets

int main() {
  std::bitset<8> b1 {"11000000"};
  std::bitset<8> b2 {"01000011"};
  std::bitset<16> b3;

  // b3 = b1;    b1 and b3 are different types

  std::cout << b1 << " (b1 before)\n";
  b1[0] = true; // indexing starts from the righthand start
  std::cout << b1 << " (b1 after)\n";

  /*
  std::cout << b2 << " (b2)\n";
  std::cout << (b1&b2) << " (b1&b2)\n";
  std::cout << (b1|b2) << " (b1|b2)\n";
  std::cout << (~b1) << " (~b1)\n";
  */
}
