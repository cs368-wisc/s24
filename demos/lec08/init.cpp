#include <iostream>
#include <initializer_list>

using namespace std;

class Test {
public:
  Test(int x, int y) {
    cout << x << " " << y << " (x, y)\n";
  }

  Test(std::initializer_list<int> args) {
    for (auto x : args) {
      cout << x << "\n";
    }
  }
};

int main() {
  Test t1(3,4);
  Test t2{3,4};
}
