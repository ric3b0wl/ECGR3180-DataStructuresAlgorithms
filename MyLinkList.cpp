#include <iostream>
using namespace std;

class MyLinkedList{

private:
	struct Node{
		int data;
		Node *next;

		Node(int val){
			data = val;
			next = NULL;
		}
	};

public: 
	MyLinkedList(){
		head = NULL;
		size = 0;
	};

	int get(int index);
	void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void delteAtIndex(int index);

};

/*********************************************************/

int MyLinkedList::get(int index){

	if(index > size  || index < 0)
		return -1;

	Node *ptr = head;
	for(int i = 0; i < index; i++){
		ptr = ptr-> next;
	}
	
	return ptr->data;
}

void MyLinkedList::addAtHead(int val){

	Node *ptr = new Node(val);

	ptr->next = head;
}

/*********************************************************/

int main (){
	MyLinkedList *List;

	list->delteAtIndex(5);
	list->get(2);
	list->get(-2);
	list->addAtIndex(3,5);
	list->addAtIndex(100,5);
	list->addAtIndex(0,5);
	list->addAtIndex(1,5);
	list->addAtIndex(1,4);
	list->addAtIndex(1);
}