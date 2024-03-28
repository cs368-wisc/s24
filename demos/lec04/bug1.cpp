#include <iostream>

using namespace std;

static void print2(int* val) {
  auto val2 = *val * 2;
  cout << val2 << "\n";
}

int main() {
  int *x;
  print2(x);
}
