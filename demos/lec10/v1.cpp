#include <iostream>
#include <vector>

using namespace std;

class Coord {
  int x=-1, y=-1;

public:
  Coord() {
    cout << "Construct Coord!\n";
  }

  ~Coord() {
    cout << "Destruct Coord!\n";
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
  for (auto &item : items) {
    cout << item << "\n";
  }
  cout << "\n\t...returning from main...\n\n";
}

/*
int main() {
  vector<Coord*> items;
  items.resize(3);
  for (auto &item : items) {
    item = new Coord{};
  }
  for (auto &item : items) {
    cout << *item << "\n";
  }
  cout << "\n\t...returning from main...\n\n";
}
*/
