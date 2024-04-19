#include <iostream>

class IntArray {
private:
  int* data; // Pointer to the dynamically allocated array
  size_t size; // Size of the array

public:
  explicit IntArray(size_t size) : size(size) {
    data = new int[size];
  }

  ~IntArray() {
    delete[] data;
  }

  // Copy constructor: Creates a deep copy of another IntArray
  IntArray(const IntArray& other) : size(other.size) {
    data = new int[size];
    for (size_t i = 0; i < size; ++i) {
      data[i] = other.data[i];
    }
  }

  // Copy assignment operator: Assigns values from another IntArray
  IntArray& operator=(const IntArray& other) {
    if (this != &other) { // Avoid self-assignment
      delete[] data; // Free existing memory
      size = other.size;
      data = new int[size];
      for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
      }
    }
    return *this;
  }

  // Move constructor: Transfers ownership from another IntArray
  IntArray(IntArray&& other) {
    size = other.size;
    data = other.data;
    other.size = 0;
    other.data = nullptr;
  }

  // Move assignment operator: Transfers ownership from another IntArray
  IntArray& operator=(IntArray&& other) {
    if (this != &other) { // Avoid self-assignment
      delete[] data; // Free existing memory
      size = other.size;
      data = other.data;
      other.size = 0;
      other.data = nullptr;
    }
    return *this;
  }

  int& operator[](int idx) {
    return data[idx];
  }

  size_t getSize() const {
    return size;
  }

  friend std::ostream& operator<<(std::ostream& os, const IntArray& arr) {
    os << "[";
    for (size_t i = 0; i < arr.size; ++i) {
      os << arr.data[i];
      if (i < arr.size - 1) {
        os << ", ";
      }
    }
    os << "]";
    return os;
  }  
};

int main() {
  IntArray arr(5);
  for (size_t i = 0; i < arr.getSize(); ++i) {
    arr[i] = i * 10;
  }

  // test copy and move constructors
  IntArray arr2 = arr;
  std::cout << arr << " (arr)\n";
  arr2[0] = 100;
  std::cout << arr2 << " (arr2)\n";

  IntArray arr3 = std::move(arr);
  std::cout << arr << " (arr after move)\n";
  std::cout << arr3 << " (arr3)\n";

  // TODO: test copy and move assignment operators
}
