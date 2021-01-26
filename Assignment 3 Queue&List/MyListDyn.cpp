//The functions will implement an integerlistusingadynamic arrayonly
//(an array that can grow and shrink as needed, uses a pointerand size of array.)

#include<iostream>
#include<list>

#include <algorithm>
#include <iterator>

using namespace std;

class MyList{
private:

  void expand_array() {
    capacity = capacity * 2;
    int* newArray = new int[capacity];

    for (int i = 0; i < size; ++i) {
      newArray[i] = data[i];
    }

    delete[] data;
    data = newArray;
  }
  
public:
  
  int *data;
  int size;
  int capacity;
  
  MyList(){
    capacity = 10;
    data = new int[capacity];
    size = 0;
  }
  
  void push_back(int n){
    if (size == capacity) { // achieve the limit
      expand_array();
    }
    data[size] = n;
    size++;
  }
  
  void push_front(int n){ // move all elements forward
    if (size == capacity) {
      expand_array();
    }

    for (int i = size - 1; i >= 0; --i) { 
      data[i + 1] = data[i];
    }

    data[0] = n;
    size++;
  }
  
  int pop_back(){ // remove the last element
    int back = data[size];
    size--;
    return back;
  }
  
  int pop_front(){ // move all element backwards
    int front = data[0];

    for (int i = 1; i < size; ++i) { 
      data[i - 1] = data[i];
    }
    
    size--;

    return front;
  }
  
  void emplace(int pos, int values){ // insert element in the middle
    if (size == capacity) {
      expand_array();
    }
    
    // move all elements forward starting at pos
    for (int i = size - 1; i >= pos; --i) {
      data[i + 1] = data[i];
    }

    data[pos] = values;
    size++;
  }
  
  bool empty(){
    return size == 0;
  }
  

  void dump() {
    std::cout << "\n";
    std::copy(data, data + size, std::ostream_iterator<int>(cout, " "));
    std::cout << "\n";
  }
  
  ~MyList() {
        delete[] data;
  }
  
};

// int main(){
//   MyList test{};

//   std::cout << test.empty() << "\n";

//   test.emplace(0, 11);
//   test.dump();
//   test.emplace(1, 12);
//   test.dump();
//   test.emplace(2, 13);
//   test.dump();

//   test.push_back(0);
//   test.push_back(1);
//   test.push_back(2);
//   test.push_back(3);
//   test.push_back(4);
//   test.push_back(5);
//   test.push_back(0);
//   test.push_back(1);
//   test.dump();

//   test.pop_back();
//   test.dump();
//   test.pop_front();
//   test.dump();
//   test.pop_back();
//   test.dump();
//   test.pop_front();
//   test.dump();
//   test.pop_back();
//   test.dump();

//   std::cout << test.empty() << "\n";
// }