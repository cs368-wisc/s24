#include <iostream>
#include <vector>

using namespace std;

class Coord {
  int x=-1, y=-1;

public:
  Coord() {
    //cout << "Construct Coord!\n";
  }

  Coord(int x, int y) : x(x), y(y) {
    //cout << "Construct Coord!\n";
  }

  ~Coord() {
    //cout << "Destruct Coord!\n";
  }
  
  friend ostream& operator<<(ostream& os, const Coord& coord);
};

ostream& operator<<(ostream& os, const Coord& coord) {
  os << "Coord(" << coord.x << "," << coord.y << ")";
  return os;
}

int main() {
  vector<Coord> items{{1,2}, {3,4}};
  auto ptr = &items[0];
  cout << *ptr << " " << ptr << "\n";
  cout << items.size() << " " << items.capacity() << " " << &items[0] << "\n";
  items.push_back({4,5});
  cout << *ptr << " " << ptr << "\n";
  cout << items.size() << " " << items.capacity() << " " << &items[0] << "\n";
}
