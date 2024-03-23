#include <iostream>
#include <cstdint>

// DEMO: variables, types, casting

int main() {
  auto x{4'000};
  auto y(3);

  std::cout << x/static_cast<float>(y) << "\n";

  // x = "hi"; auto doesn't mean we can change types
}
