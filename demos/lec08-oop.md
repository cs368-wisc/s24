# Lec 08 - Object Oriented Programming

## Overloading the `<<` Operator

### Watch

https://mediaspace.wisc.edu/media/t/1_iqwmkd1t

### Practice

Look back at the example code from the previous lecture: https://github.com/cs368-wisc/s24/blob/main/demos/lec07/houses.cpp.

Add some code so we can print coordinates with something like this:

```cpp
std::cout << SOME_COORD_OBJECT << "\n";
```

For reference, here's the example function from the recording for printing a house:

```cpp
std::ostream& operator<<(std::ostream& os, const House &obj) {
  os << "House(beds=" << obj.beds << ")";
  return os;
}
```

## Destructors

### Watch

https://mediaspace.wisc.edu/media/t/1_xbau7tag

### Practice

Add delete statements to the following as necessary so that we see A,
B, and C being destroyed (don't worry about the order).

```cpp
#include <iostream>

using namespace std;

class A {
public:
  ~A() {
    cout << "destroy A\n";
  }
};

class B {
public:
  ~B() {
    cout << "destroy B\n";
  }
};

class C {
  A a;
  B* b;
public:
  C(): a({}), b(new B) {}

  ~C() {
    cout << "destroy C\n";
  }
};


int main() {
  auto obj = new C;
}
```

## Copy Constructors

### Watch

https://mediaspace.wisc.edu/media/CS%20368%20S24%20-%20Copy%20Constructor/1_da2tcqmc


## Copy Assignment Operators

### Watch

https://mediaspace.wisc.edu/media/t/1_ykeqa0lr


## Assignment Style

### Watch

https://mediaspace.wisc.edu/media/t/1_3zdyg7fo

### Practice

The C++ vector type has MANY overloaded constructors: https://en.cppreference.com/w/cpp/container/vector/vector.

The following code uses a constructor that takes a `initializer_list`, and the result is a vector containing one number, which is 10.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums{10};
  cout << "there are " << nums.size() << " numbers\n";
}
```

Modify the initialization style for `nums` so that we instead get a
vector of 10 numbers.
