/*
The functions will implement an integerstackusing dequesonly.
Try to implement it using only one deque, 
but a solution with two deques will also be accepted.
You may add additional public helper functions or private members/functions.

*/

/*
What is the Big-Oh O()time for your implementation of the functions push()and pop()below?

There not much involved in stack, two primary methods are push and pop. 
For both, O(1) for both time and space. 
In worst case, functions will have big O(n).

*/

#include<iostream>
#include<deque>

//~ template < class T, class Alloc = allocator<T> > class deque;

class MyStack {
public:
	//# Default Constructor
    std::deque<int> data;

	//# Push integer onto top of MyStack
	void push(int value) {
		data.push_front(value); //adding the fisrt element
	}

	//# Pop element on top of MyStack
	int pop() {
    int tmp = data.front();
		data.pop_front(); // removing the first element in vector
		return tmp;

	}

	//# Get the top element but do not pop it (peek at top of stack)
	int top() {
		if (data.size() != 0){
		  return data.front();
		}
		else {
		  std::cout << "The container is empty. " << std::endl;
		  return 0;
		}
		
	}

	//# Return whether the stack is empty or not
	bool empty() {
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
// using namespace std;
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
