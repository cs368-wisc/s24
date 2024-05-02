#include <iostream>

using namespace std;

template<typename T>
class MyArray {
private:
  T* data; // Pointer to the dynamically allocated array
  size_t size; // Size of the array

public:
  explicit MyArray(size_t size) : size(size) {
    data = new T[size];
  }

  ~MyArray() {
    delete[] data;
  }

  // Copy constructor: Creates a deep copy of another MyArray
  MyArray(const MyArray<T>& other) : size(other.size) {
    data = new T[size];
    for (size_t i = 0; i < size; ++i) {
      data[i] = other.data[i];
    }
  }

  // Copy assignment operator: Assigns values from another MyArray
  MyArray& operator=(const MyArray<T>& other) {
    if (this != &other) { // Avoid self-assignment
      delete[] data; // Free existing memory
      size = other.size;
      data = new T[size];
      for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
      }
    }
    return *this;
  }

  // Move constructor: Transfers ownership from another MyArray
  MyArray(MyArray<T>&& other) {
    size = other.size;
    data = other.data;
    other.size = 0;
    other.data = nullptr;
  }

  // Move assignment operator: Transfers ownership from another MyArray
  MyArray& operator=(MyArray<T>&& other) {
    if (this != &other) { // Avoid self-assignment
      delete[] data; // Free existing memory
      size = other.size;
      data = other.data;
      other.size = 0;
      other.data = nullptr;
    }
    return *this;
  }

  T& operator[](int idx) {
    return data[idx];
  }

  size_t getSize() const {
    return size;
  }

  friend std::ostream& operator<<(std::ostream& os, const MyArray<T>& arr) {
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
  MyArray<string> arr(5);
  for (size_t i = 0; i < arr.getSize(); ++i) {
    arr[i] = "A";
  }
  arr[1] = "B";
  std::cout << arr[0] << "\n";
  std::cout << arr[1] << "\n";
  std::cout << arr << "\n";
}
