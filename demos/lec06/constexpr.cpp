#include <iostream>

// const vs. constexpr

constexpr int sumN(int N) {
  int tot = 0;
  for (int i=1; i<=N; i++)
    tot += i;
  return tot;
}

// const is done at run time
//const int sum5 = sumN(5);

// constexpr is computed at compile time!
constexpr int sum5 = sumN(5);

using namespace std;

int main() {
  cout << sum5 << "\n";
}
