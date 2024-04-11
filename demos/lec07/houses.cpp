#include <iostream>

using namespace std;

struct Coord {
  int x{0};
  int y{0};

  Coord(int x, int y) {
    cout << "Coord Created!\n";
    this->x = x;
    this->y = y;
  }
};

class House {
  // default in a class is private, default in a struct is public
  int beds{0};
  float sq_m{0};
  Coord coord{0, 0};
public:
  House(int beds, float sq_ft, int x, int y);
  
  float SquareFeet();
  float SquareMeters();
};

House::House(int beds, float sq_ft, int x, int y):
  beds(beds),
  sq_m(sq_ft/10.76),
  coord({x,y}) {
}

float House::SquareFeet() {
  return sq_m * 10.76;
}

float House::SquareMeters() {
  return sq_m;
}

int main() {
  House h{3, 200, -89, 49};
  cout << "Sq Ft: " << h.SquareFeet() << "\n";
  cout << "Sq meters: " << h.SquareMeters() << "\n";
}
