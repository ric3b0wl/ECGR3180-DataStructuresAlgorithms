// Q1: (45 pts)
// For any input binary search tree, find the key/value of successor of the root node.
// Note: Successor is the node with the next highest key/value
//
// What is the complexity of your solution?
//
// Write a short test program (main() ) to test your code. Include as many test cases as possible.
//

#include <iostream>

using namespace std;

class Node
{
private:
   int key;
   string val;
   Node* left;
   Node* right;
   friend class BinarySearchTree;   
};   


class BinarySearchTree
{
public:   
       BinarySearchTree();
       void insert(int key, string val); // Recursive
       int rootSuccessor(); // Returns key of the successor of the root, -1 if no successor
 private:
        Node* root;
        void insertHelper(Node* parent, Node* new_node);
};

int main() {
    
   BinarySearchTree t;
   t.insert(5, "Boron");
   t.insert(3, "Lithium");
   t.insert(7, "Nitrogen");
   t.insert(2, "Helium");
   t.insert(4, "Berylium");
   t.insert(6, "Carbon");
   t.insert(8, "Oxygen");
   int succ = t.rootSuccessor();
   if (succ != -1) 
        cout << "Successor: " << succ << endl;
   else 
        cout << "No successor" << endl;
   
}

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

/////////////////////////////////////////////////////////////////////////
int BinarySearchTree::rootSuccessor() {
   Node* currentNode = this->root->right;

   while (currentNode->left != nullptr) {
      currentNode = currentNode->left;
   }
   
   return currentNode->key;
}
/////////////////////////////////////////////////////////////////////////