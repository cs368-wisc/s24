#include <iostream>

using namespace std;

// TIP: don't use NULL (use nullptr instead)

void print_num(long x) {
  cout << x << " (value)\n";
}

void print_num(long *x) {
  if (x) // means if it is not nullptr
    cout << *x << " (pointer)\n";
  else
    cout << "no value!\n";
}

int main() {
  long x = 368;
  print_num(x);

  auto y = &x;
  print_num(y);

  auto z = nullptr; // prefer this over NULL
  print_num(z);
}
