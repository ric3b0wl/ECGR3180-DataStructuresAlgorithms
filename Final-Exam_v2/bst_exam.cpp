// Add code to the:
// getMax()
// height()
// isHeightBalanced()
// isHeightBalancedHelper() functions below

#include <iostream>
#include <climits> // For INT_MAX
#include <algorithm> // For max
#include <cmath> // For abs
#include "bst_exam.h"
// #include "bst_test_exam.cpp"

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

void BinarySearchTree::insertHelper(Node* parent, Node* new_node) 
{  
   if (new_node->key < parent->key) {  
      if (parent->left == nullptr) { 
         parent->left = new_node; 
      }
      else { 
         insertHelper(parent->left, new_node); }
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


/*
Hint - 
isHeightBalanced(tree)
    return (tree is empty) or 
           (isHeightBalanced(tree.left) and
            isHeightBalanced(tree.right) and
            abs(height(tree.left) - height(tree.right)) <= 1)
*/


// returns max value in BST
int BinarySearchTree::getMax() const {
   Node* currentNode = this->root;

   while (currentNode->right != nullptr) {
      currentNode = currentNode->right;
   }
   
   return currentNode->key;
}

// returns height of BST
int BinarySearchTree::height(Node* n) const {
   if (n == nullptr) {
      return 0;
   }

   int left = height(n->left);
   int right = height(n->right);

   if (left > right) {
      return left + 1;
   } else {
      return right + 1;
   }
}

// checks whether tree is balanced or not. Returns TRUE if balanced, FALSE otherwise.
bool BinarySearchTree::isHeightBalanced() const {
   return isHeightBalancedHelper(root);
}

// use this as a helper function for the isHeightBalanced() function above.
bool BinarySearchTree::isHeightBalancedHelper(Node *n) const {
   if (n == nullptr) {
      return true;
   }
   
   int left = height(n->left);
   int right = height(n->right);

   if (abs(left - right) <= 1 
   && isHeightBalancedHelper(n->left) 
   && isHeightBalancedHelper(n->right) ) {
      return true;
   } 
   else {
      return false;
   }
}