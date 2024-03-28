#include <iostream>

// tip: NEVER return the address of a local variable

using namespace std;

int* mult2(int x) {
  int x2 = x * 2;
  int* y = &x2;
  return y;
}

int main() {
  int *a = mult2(1);
  int *b = mult2(2);
  int *c = mult2(3);
  cout << *a << "\n";
  cout << *b << "\n";
  cout << *c << "\n";
}
