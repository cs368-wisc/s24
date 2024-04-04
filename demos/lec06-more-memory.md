# Lec 06 - More Memory

## Lecture Catchup

### Watch

https://mediaspace.wisc.edu/media/CS%20368%20S24%20-%20Wed%20Wrapup%3A%20arrays%2C%20const%2C%20references/1_rtz4ox59

* arrays on the heap
* delete[]
* const
* references

## References and Auto

### Watch

https://mediaspace.wisc.edu/media/CS%20368%20S24%20-%20References%20and%20Auto/1_wkmh738m

### Practice

Run the following program:

```cpp
#include <iostream>
#include <vector>

using namespace std;

struct Coord {
  int x = 0;
  int y = 0;
};

int main() {
  vector<Coord> coords = {{3,3}, {4,5}, {8,10}};
  cout << "addr of Coord at idx 0: " << &coords[0] << "\n";
  cout << "addr of Coord at idx 1: " << &coords[1] << "\n";
  cout << "addr of Coord at idx 2: " << &coords[2] << "\n";

  for (auto c : coords) {
    cout << c.x << " " << c.y << " " << &c << "\n";
  }
}
```

Note that the c doesn't change, and is different than the addresses of
the elements.  This is because a Coord is being copied for each
iteration of the loop.  That could become a problem if the struct gets
much bigger (more members).

Modify the code so that c refers each element in turn (instead of
copying it).

## Pointer Arithmetic

### Watch

https://mediaspace.wisc.edu/media/CS%20368%20S24%20-%20Pointer%20Arithmetic/1_o3x9kp3p

### Practice

Replace `????` with some pointer arithmetic to get the index of the
number within `nums` (it's 3, as you can see in the `getnum` function,
but pretend you can't see that).

```cpp
#include <iostream>
#include <vector>

using namespace std;

int nums[] = {1,3,2,7,9};

int *getnum() {
  return &nums[3];
}

int main() {
  int *num = getnum();
  cout << *num << " (value)\n";
  cout << (????) << " (index)\n";
}
```

If you want even more practice, write a safety check to verify `num`
actually points to an element in `nums` before printing the index
(print a warning instead if it points some number outside of the
array).

## Double Pointers

### Watch

https://mediaspace.wisc.edu/media/CS%20368%20S24%20-%20Double%20Pointers/1_rth7n0ja

### Practice

Here is the code from the demo:

```cpp
#include <iostream>

// double pointers                                                                                                                
using namespace std;

int init_range(int** arrp) {
  int size=8;
  *arrp = new int[size];
  for (int i=0; i<size; i++) {
    (*arrp)[i] = 10-i;
  }
  return size;
}

int main() {
  int* arr;
  int size = init_range(&arr);

  for (int i=0; i<size; i++) {
    cout << arr[i] << "\n";
  }
}
```

Write a similar `float_range` function that returns a range of floats.
It should have start, end, and step params.  For example, if you have
start=3, end=3.5, and step=0.1, you would get an array back with these
numbers:

3.0
3.1
3.2
3.3
3.4

## Strings

### Watch

https://mediaspace.wisc.edu/media/t/1_a9yuzqyk

### Practice

Complete this program:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  std::vector<std::string> args{};

  for (????) {
    args.push_back(????);
  }

  for (auto& s : args) {
    cout << s << "\n";
  }
}
```

Your goal is to take all the C-style strings from argv (excluding the
program name!) and add them as standard stings to the `args` vector.

Example execution:

```
./a.out hello 1 2 3
hello
1
2
3
```

## const vs. constexpr

### Watch

https://mediaspace.wisc.edu/media/t/1_jlh5t9td
