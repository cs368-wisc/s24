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
  vector<int> nums1{1,2,3};
  vector<int> nums2 = nums1;
  nums2[0] = 10;
  nums2.push_back(4);
  for (auto num : nums1)
    cout << num << " ";
}
