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

vector<vector<int>> tbl;

vector<int> MakeRow(int start, int end) {
  if (end<start)
    return vector<int>{}; // empty
    
  vector<int> result;
  for (int i=start; i<end; i++)
    result.push_back(i);
  Debug("MakeRow result", result);
  return result;
}

void InsertRow(vector<int> insertRow) {
  Debug("InsertRow insertRow", insertRow);
  tbl.emplace_back(std::move(insertRow));
}

int main() {
  auto row = MakeRow(1, 1000);
  Debug("main row", row);
  cout << "row before: " << row << "\n";
  InsertRow(std::move(row));
  cout << "row after: " << row << "\n";
  Debug("tbl[0]", tbl[0]);
}
