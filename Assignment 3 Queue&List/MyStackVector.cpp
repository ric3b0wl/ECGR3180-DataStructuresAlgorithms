//Implement the MyStackclass in Problem 1 using vectors

#include<iostream>
#include<vector>

class MyStack{
public: 

  std::vector<int> data; //creating a vector as container
  MyStack(){}

  void push(int n){
    data.push_back(n); // adding a element in the back to vector
  }

  int pop(){
    int temp =  data.front();
    data.pop_back(); // remove the last element in the vector
    return temp;
  }

  int top(){
    if (data.size() != 0){
		  std::cout << "The top of the stack value is: " << data.front() << std::endl;
		  return data.front();
    }
    else {
      std::cout << "The container is empty. " << std::endl;
        return 0;
    }
  }

  bool empty(){
    if (data.size() == 0) {
			std::cout << "This stack is empty" << std::endl;
			return true;
		}
    else {
      std::cout << "There are still elements in the stack" << std::endl;
			return false;
    }
  }
  
};

// int main() {
//  using namespace std;
//     int value = 5;
//     value = 7;
  
// 	MyStack *ptr = new MyStack();

// 	ptr->push(value);
//     ptr->push(value);
	
//     int pop1 = ptr->pop();
// 	int pop2 = ptr->pop();

// 	bool isEmpty = ptr->empty();
	
// 	return 0;
// }
