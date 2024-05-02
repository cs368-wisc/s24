#include <iostream>
#include <string>

using namespace std;

// v1: overloading
/*
int Plus(int x, int y) {
  return x+y;
}

string Plus(string x, string y) {
  return x+y;
}
*/

// v2: auto
/*
auto Plus(auto x, auto y) {
  return x+y;
}
*/

// v3: templates
template<typename T>
T Plus(T x, T y) {
  return x + y;
}

int main() {
  cout << Plus(1, 23) << "\n";
  cout << Plus("A"s, "BC"s) << "\n";
  //cout << Plus("ABCD", 2) << "\n";
}
