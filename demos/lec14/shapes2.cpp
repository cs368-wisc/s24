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

class State {
public:
  string name;
  float sq_miles;
  
  float area() {
    return sq_miles;
  }
};

/*
void PrintAreaSum(vector<unique_ptr<Shape>>& items) {
  float total = 0;
  for (auto& item : items)
    total += item->area();
  cout << "Total: " << total << "\n";
}
*/

template <typename T>
void PrintAreaSum(T& items) {
  float total = 0;
  for (auto& item : items)
    total += item->area();
  cout << "Total: " << total << "\n";
}

int main() {
  // DEMO: inheritance vs. templates
  vector<unique_ptr<Shape>> shapes;
  shapes.push_back(make_unique<Square>(0,0,3,4));
  shapes.push_back(make_unique<Square>(1,1,5,5));
  PrintAreaSum(shapes);

  auto wi = new State("WI", 65'498);
  auto il = new State("IL", 57'915);
  auto states = vector<State*>{wi, il};
  PrintAreaSum(states);
  delete wi;
  delete il;
}
