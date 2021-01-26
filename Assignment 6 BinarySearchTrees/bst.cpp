#include <iostream>
#include "bst.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{  
   root = nullptr;
}
   
void BinarySearchTree::insert(int key, string val) 
{  
   Node* new_node = new Node;
   new_node->key = key;
   new_node->val = val;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) { 
      root = new_node; 
   } else { 
      insertHelper(root, new_node); 
      }
}

/
void BinarySearchTree::insertHelper(Node* parent, Node* new_node)
{  
   if (new_node->key < parent->key) {  
      if (parent->left == nullptr) { 
         parent->left = new_node; 
      }
      else { 
         insertHelper(parent->left, new_node);
         }
   }
   else if (new_node->key > parent->key) {  
      if (parent->right == nullptr) {
         parent->right = new_node; 
      }
      else { 
         insertHelper(parent->right, new_node); 
      }
   }
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
string BinarySearchTree::find(int key) const { //! Iterativly
   Node* currentNode = root;

   while (true) { 
      if (currentNode->key == key) { //return matching key,value
         return currentNode->val;
      }
      else if (currentNode->key > key) { // if less than current key, then move to left
         currentNode = currentNode->left;
      }
      else if (currentNode->key < key) { // if greater than current key, then move to right
         currentNode = currentNode->right;
      }

      // if the currnet node is null, then it reached leaf node end
      // Return an empty string to show no element found
      if (currentNode == nullptr) {
         return " ";
      }
   }

}

//! Recursivly
// string BinarySearchTree::find_rec(node* parentNode_rec, int key){
//    if (parentNode_rec->key == key){
//       return parentNode_rec->val;
//    }

//    if (key < current_node->key){
//       insertHelper(parentNode_rec->left, key);
//    }
//    else if (key > current_node->key){
//       insertHelper(parentNode_rec->right, key);
//    }

//    if (parentNode_rec == nullptr){
//       return " ";
//    }

// }



void BinarySearchTree::printInOrder() const {
	if (root == nullptr) {
		cout << endl;
	}
	printInOrderHelper(root);
	cout << endl;

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BinarySearchTree::printInOrderHelper(Node* n) const {
   printInOrderHelper(n->left); //print left node first, less than current

   cout << n->key << " : " << n->val << std::endl; 

   printInOrderHelper(n->right); //print right node second, greater than current

   if (n == nullptr) return; //pasting lead node, return
}

   