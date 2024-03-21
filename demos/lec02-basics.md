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
