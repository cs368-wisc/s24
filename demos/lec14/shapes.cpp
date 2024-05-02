#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Coord {
  int x{0};
  int y{0};
  ~Coord() {
    cout << "release Coord " << x << " " << y << "\n";
  }
};

class Shape {
public:
  // pure virtual (children MUST override this function)
  virtual float area() = 0;

  // with inheritance, parents should almost always have virtual
  // destructors!  Otherwise their children might leak.
  virtual ~Shape() {};
};

class Square : public Shape {
  unique_ptr<Coord> bl; // bottom left
  unique_ptr<Coord> tr; // top right

public:
  Square(int x1, int y1, int x2, int y2)
    : bl(new Coord(x1, y1)), tr(new Coord(x2, y2)) {}

  float area() override {
    auto w = (tr->x - bl->x);
    auto h = (tr->y - bl->y);
    return w * h;
  }
};

class Circle : public Shape {
  float area() override {
    return -1; // TODO
  }
};

int main() {
  vector<unique_ptr<Shape>> shapes;
  shapes.push_back(make_unique<Square>(0,0,3,4));
  shapes.push_back(make_unique<Circle>());
  shapes.push_back(make_unique<Square>(1,1,5,5));
  for (auto& shape : shapes) {
    // 1. get is giving a raw pointer to a Square
    // 2. nullptr if shape is NOT a Square
    auto sq = dynamic_cast<Square*>(shape.get());

    if (sq)
      cout << shape->area() << " (square)\n";
    else
      cout << "skip non-square shape\n";
  }
}
