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
  vector<Coord> items;
  items.resize(3);
  items.resize(2);
  cout << items.size() << " " << items.capacity() << "\n";
  items.shrink_to_fit();
  cout << items.size() << " " << items.capacity() << "\n";
}
