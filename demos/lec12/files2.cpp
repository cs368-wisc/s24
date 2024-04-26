#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream f("file.txt");
  std::string s;
  f >> s;
  int x;
  f >> x;
  cout << s << " (string)\n";
  cout << x << " (int)\n";
}
