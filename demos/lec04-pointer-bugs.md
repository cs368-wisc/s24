# Lec 04 - Pointer Bugs

## gdb Debugger

### Watch

https://mediaspace.wisc.edu/media/t/1_ogpdxgum

### Practice

The following segfault bug is subtle enough that `-Wall` doesn't give a good hint.  Compile and use a debugger (gdb as in the video, or learn about a different one on your own if you like) to identify the line number causing the issue.

```cpp
#include <iostream>

using namespace std;

int* bigger(int* x, int *y) {
  int* result{nullptr};

  if (*x > *y)
    result = x;
  else if (*y > *x)
    result = y;

  return result;
}
  
int main() {
  int a{4};
  int b{4};
  int *biggest = bigger(&a, &b);
  cout << "the biggest num is " << *biggest << "\n";
}
```

## Never Return Addresses of Local Variables

### Watch

https://mediaspace.wisc.edu/media/t/1_k7cxldh3

### Practice (Optional)

This kind of bug is hard to troubleshoot with a debugger like gdb, but there are tools out there that can help.  `valgrind` is one of them.

If you want to experiment with valgrind, do a debug build (`-g`) with the code from the demo, then run this:

```
valgrind --track-origins=yes a.out
```

The output will be hard to read, but see if you can find where it says "Uninitialised value was created by a stack allocation."

For your convenience, here is the code from the demo:

```cpp
#include <iostream>

// tip: NEVER return the address of a local variable

using namespace std;

int* mult2(int x) {
  int x2 = x * 2;
  int* y = &x2;
  return y;
}

int main() {
  int *a = mult2(1);
  int *b = mult2(2);
  int *c = mult2(3);
  cout << *a << "\n";
  cout << *b << "\n";
  cout << *c << "\n";
}
```

## Use nullptr (not NULL)

### Watch

https://mediaspace.wisc.edu/media/t/1_7lpbyucf

```cpp
int main() {
  int x;
  x = ????;
}
```

Try compiling this program, replacing `????` with `NULL`, and then
`nullptr`.  When do you get just a warning?  When does compilation
actually fail?
