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

  // Coord(const Coord& other) = delete;  
  Coord(const Coord& other) : x(other.x), y(other.y) {
    cout << "Copy Constructor!\n";
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
  // style 1
  {
    // vector<int> items = {10}; same as following line!
    vector<int> items{10};
    cout << items.size() << " " << items.capacity() << " " << &items[0] << "\n";
  }
  // style 2
  {
    vector<int> items(10);
    cout << items.size() << " " << items.capacity() << " " << &items[0] << "\n";
  }
  // style 3
  {
    // NOT ALLOWED because the constructor taking one number is "explicit"
    //vector<int> items = 10;
    //cout << items.size() << " " << items.capacity() << " " << &items[0] << "\n";
  }  
}
