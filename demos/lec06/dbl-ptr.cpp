#include <iostream>

// double pointers
using namespace std;

int init_range(int** arrp) {
  int size=8;
  *arrp = new int[size];
  for (int i=0; i<size; i++) {
    (*arrp)[i] = 10-i;
  }
  return size;
}

int main() {
  int* arr;
  int size = init_range(&arr);

  for (int i=0; i<size; i++) {
    cout << arr[i] << "\n";
  }
}
