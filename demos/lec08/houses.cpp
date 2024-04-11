#include <iostream>

using namespace std;

struct Coord {
  int x{0};
  int y{0};
  int refcount{1}; // how many houses point to this coord?

  Coord(int x, int y) {
    cout << "Coord Constructed! " << this << "\n";
    this->x = x;
    this->y = y;
  }

  ~Coord() {
    cout << "Coord Destroyed! " << this << "\n";
  }
};

class House {
  // default in a class is private, default in a struct is public
  int beds{0};
  float sq_m{0};
  Coord* coord = nullptr;
public:
  House(House& other); // copy constructor
  explicit House(int beds);
  House(int beds, float sq_ft, int x, int y);
  ~House();

  void operator=(House& other); // copy assignment operator
  
  float SquareFeet();
  float SquareMeters();

  friend std::ostream& operator<<(std::ostream& os, const House &obj);
};

void House::operator=(House& other) {
  // Observation 1: this->coord is already set to something!
  coord->refcount--; // this house is not pointing to the coord anymore
  cout << "There are " << coord->refcount << " references left (after copy assignment op)\n";

  // was that the last house pointing to it?
  if (this->coord->refcount == 0) {
    delete this->coord;
  }
  
  // Observation 2: this->coord will now point to the same thing as other.coord
  this->coord = other.coord;
  coord->refcount++; // we have another house pointing to the same coord!
}

House::House(int beds):
  beds(beds),
  sq_m(0),
  coord(new Coord{0,0})
{
  //cout << "CONSTRUCT(A): " << *this << "\n";
}

House::House(int beds, float sq_ft, int x, int y):
  beds(beds),
  sq_m(sq_ft/10.76),
  coord(new Coord{x,y})
{
  //cout << "CONSTRUCT(B): " << *this << "\n";
}

House::House(House& other):
  beds(other.beds), sq_m(other.sq_m), coord(other.coord)
{
  // we have another house pointing to the same coord!
  coord->refcount++;
  cout << "CONSTRUCT(C): " << *this << "\n";
}

House::~House() {
  cout << "DESTROY: " << *this << "\n";

  coord->refcount--; // this house is not pointing to the coord anymore
  cout << "There are " << coord->refcount << " references left\n";
  
  // was that the last house pointing to it?
  if (this->coord->refcount == 0) {
    delete this->coord;
  }
}

float House::SquareFeet() {
  return sq_m * 10.76;
}

float House::SquareMeters() {
  return sq_m;
}

std::ostream& operator<<(std::ostream& os, const House &obj) {
  os << "House(beds=" << obj.beds << ")";
  return os;
}

int main() {
  // init styles:
  // =
  // (...)
  // {} or ={}

  House A{1};
  House B{2};
  House C{A}; // copy constructor
  B = A; // copy assignment operator

  // THIS VIDEO: copy assignment operator

  cout << "\n\t...returning from main...\n\n";
}
