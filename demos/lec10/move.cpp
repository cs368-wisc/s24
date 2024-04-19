#include <iostream>
#include <vector>

using namespace std;

void Debug(std::string label, const vector<int>& obj) {
  cout << label << ": vector at " << &obj
       << " uses " << sizeof(obj)
       << " bytes but points to "
       << (sizeof(*obj.data()) * obj.capacity())
       << " bytes at " << obj.data() << "\n";
}

ostream& operator<<(ostream& os, const vector<int>& obj) {
  for (auto num : obj)
    cout << num << " ";
  return os;
}

int main() {
  vector<int> v1{1,2,3,4,5,6,7,8,9,10};
  Debug("v1 (before moving)", v1);
  vector<int> v2 = std::move(v1); // OK because we don't need v1 for anything anymore
  Debug("v1 (after moving)", v1);
  Debug("v2", v2);
  cout << "v1: " << v1 << "\n";
  cout << "v2: " << v2 << "\n";
}
