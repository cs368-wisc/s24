# Lec 02 - Basics

## Hello World

### Watch

https://mediaspace.wisc.edu/media/t/1_sm7d0isy

### Practice

When learning a language, it's useful to intentionally write code with bugs so you can see how the compiler/linker describes the issue to you.  That will help you debug better when you unintentionally have such a bug!

Try compiling and running the following code and note the error messages:

```cpp
#include iostream

main() {
  cout << "hello world\n";
}
```

Then try to fix the issues -- there are 3 of them!

## Types

### Watch

https://mediaspace.wisc.edu/media/CS%20368%20S24%20-%20Types/1_xlx6pvjy

### Practice

```cpp
#include <iostream>

int main() {
  int result = 1.0 / 2.0;
  std::cout << result << "\n";

  bool flag = 3;
  std::cout << flag << "\n";
}
```

Compile and run the above program.  Then make two changes:
 - let C++ automatically decide the type for `result`
 - initialize `flag` using a different approach so that we get an error (`3` is an odd value for a `bool` and probably not what the programmer intended, so we would prefer to have the compiler let us know about it)

## Conditionals

### Watch

https://mediaspace.wisc.edu/media/CS%20368%20S24%20-%20Conditionals%20and%20Related%20Topics/1_ulbyt0xt

### Practice

Complete the following (by replacing `????` parts) and run your code:

```cpp
#include <iostream>
#include <bitset>

int main() {
  std::bitset<8> b1 {"11000000"};
  std::bitset<8> b2 {"10000001"};
  auto b3 = b1 ???? b2;
  std::cout << b3[????] << "\n";
}
```

Your goal: determine whether the **leftmost** bits in **both** `b1` and `b2` is 1 (hint: they both are, so your output should reflect that).

Bonus: write an if/else to print yes or no (instead of 1 or 0).

## Loops

### Watch

https://mediaspace.wisc.edu/media/CS%20368%20S24%20-%20Loops/1_0odsy1py

### Practice

Write a loop that counts down from 5 to 0.

## Functions

### Watch

https://mediaspace.wisc.edu/media/CS%20368%20S24%20-%20Functions/1_ynimm2j5

### Practice

Write code in `main` to call `f` functions and print A, B, and C (in
that order).  You may add a function declaration at the top if it
helps.

```cpp
#include <iostream>

void f(bool b) {
  std::cout << "A\n";
}

namespace Test {
  void f() {
    std::cout << "B\n";
  }
}

int main() {
  f(true);
  Test::f();
  f();
}

void f() {
  std::cout << "C\n";
}
```