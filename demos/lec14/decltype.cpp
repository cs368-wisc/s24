#include <iostream>
#include <string>

using namespace std;

auto Plus(auto x, decltype(x) y) {
  return x+y;
}

int main() {
  cout << Plus(1, 23) << "\n";
  cout << Plus("A"s, "BC"s) << "\n";
  //cout << Plus("ABCD", 2) << "\n";

  int x = 3;
  int& y = x;
  //auto z = y; // type deduction: infer that z is an int, but will ignore ref-ness
  //decltype(y) z = y; // type deduction: infer that z is an int reference
  decltype(auto) z = y; // type deduction: infer that z is an int reference
  z++;
  cout << x << " " << z << "\n";
}
