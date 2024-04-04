// Pointer Arithmetic

#include <iostream>

using namespace std;

int main() {
  int size = 5;
  int *nums = new int[size];

  for (int i=0; i<size; i++) {
    nums[i] = i+1;
    cout << nums[i] << " " << &nums[i] << " " << "\n";
  }

  /*
  for (int i=0; i<size; i++) {
    int *curr = nums + i;
    cout << *curr << " " <<
      curr << " " << "\n";
  }
  */

  char *bytes =
    reinterpret_cast<char *>(nums);
  for(int i=0; i<size*sizeof(int); i++) {
    cout << "byte " << i << ": "
         << int(bytes[i]) << "\n";
  }
}
