#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream f("file.txt");
  f << "hello\n";
  f << "368\n";
}
