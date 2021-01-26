#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>

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
		int getMax() const; //Retuns max key in the tree, INT_MAX if root is null ptr
		bool isHeightBalanced() const; //Returns true if tree is balanced; false otherwise; See Hint
private:
        Node* root;
        void insertHelper(Node* parent, Node* new_node);
		bool isHeightBalancedHelper(Node* n) const;
		int height(Node* n) const;
		
};

/*
Hint - 
isHeightBalanced(tree)
    return (tree is empty) or 
           (isHeightBalanced(tree.left) and
            isHeightBalanced(tree.right) and
            abs(height(tree.left) - height(tree.right)) <= 1)
*/

#endif
