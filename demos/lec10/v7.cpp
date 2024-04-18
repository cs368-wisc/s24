#include <iostream>
#include <vector>
#include <ranges>

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
  vector<int> nums{1,2,3,4,5};

  cout << "with for each loop:\n";
  for (auto num : nums)
    cout << num << "\n";

  cout << "with iterators:\n";
  for (auto it = nums.begin(); it != nums.end(); it++)
    cout << *it << "\n";

  cout << "with iterators (reversed):\n";
  for (auto it = nums.rbegin(); it != nums.rend(); it++)
    cout << *it << " " << (&*it) << "\n";  

  cout << "with iterators, nested loop:\n";
  for (auto it = nums.begin(); it != nums.end(); it++) {
    for (auto it2 = nums.begin(); it != it2; it2++) {
      cout << *it2 << " ";
    }
    cout << "\n";
  }

  cout << "with ranges:\n";
  auto r = std::ranges::reverse_view(nums);
  for (auto num : r) {
    cout << num << "\n";
  }
}
