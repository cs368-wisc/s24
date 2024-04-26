#include <iostream>
#include <memory>

using namespace std;
struct Coord {
  int x = 0;
  int y = 0;
  ~Coord() {
    cout << "Destroy " << x << ", " << y << "\n";
  }
};
ostream& operator<<(ostream& os, const Coord& obj) {
  os << "Coord(" << obj.x << ", " << obj.y << ")";
  return os;
}

auto a = make_shared<Coord>(1,2);

void test() {
  auto b = make_shared<Coord>(3,4);
  auto c = make_shared<Coord>(5,6);

  a = b;
  cout << "count: " << a.use_count() << "\n";
  cout << "\t...test retuning...\n";
}

int main() {
  test();
  cout << "count: " << a.use_count() << "\n";
  cout << "\t...main retuning...\n";
}
