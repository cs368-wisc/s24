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

void f(Coord& obj) {
  cout << "f: " << obj << "\n";
}

class House {
public:
  int beds=0;
  unique_ptr<Coord> coord = nullptr;
  House(int beds, float x, float y) : beds(beds), coord(new Coord(x, y)){}
  House(const House& other) : beds(other.beds), coord(new Coord(*other.coord)){}
};

int main() {
  House h1{3,55,66};
  House h2 = h1;
  cout << "\t...main retuning...\n";
}
