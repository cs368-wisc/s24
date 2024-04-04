// references and auto
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums{1,2,3};

  for(auto& num : nums) {
    num *= 10;
  }
  
  for(auto num : nums) {
    cout << num << "\n";
  }
  
  /*
  int x = 3;
  int& y = x;

  y = 4;
  auto& z = y;
  z = 5;
  
  cout << x << " " << y << " " << z << "\n";
  */
}
