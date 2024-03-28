#pragma once

int divide(int x, int y);
double divide(double x, double y);
namespace safe::math {
  std::pair<int, bool> divide(int x, int y);
}

constexpr float pi = 3.14;
