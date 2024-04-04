#include <iostream>
#include <string>

// strings, C style and std::string

using namespace std;

int main(int argc, char* argv[]) {
  int total = 0;
  for (int i=1; i<argc; i++) {
    total += std::stoi(argv[i]);    // std::to_string
  }
  cout << total << "\n";

  /*
  const char* cstr = "hello";
  cout << cstr << "\n";
  std::string s{"hello"};
  s[0] = 'H';
  cout << (s + " tyler") << " " << s.size() <<"\n";
  */
}
