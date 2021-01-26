#include <iostream>
#include <cstdlib>

#include "LinkedList.h"

using namespace std;

List::List(){
	head = NULL;
	curr = NULL;
	temp = NULL;

} 

void List::AddNote(int addData){
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	if(head != NULL){
		curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = n;
	}
	else{
		head = n;
	}
	
}

void List::DeleteNode(int delData){
	nodePtr delPtr = NULL;

	temp = head;
	curr = head;
	

}

void List::PrintList(){

}

