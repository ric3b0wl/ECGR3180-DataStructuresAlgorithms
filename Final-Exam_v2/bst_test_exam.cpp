#include <iostream>
#include "bst_exam.h"

using namespace std;

// Tests the binary search tree class.

int main()
{  
	BinarySearchTree t;
	t.insert(5, "Boron");
	t.insert(3, "Lithium");
	t.insert(7, "Nitrogen");
	t.insert(2, "Helium");
	t.insert(4, "Berylium");
	t.insert(6, "Carbon");
	t.insert(8, "Oxygen");
   	t.insert(9, "Flourine");

	cout << t.getMax() << endl; // Prints 9

	if (t.isHeightBalanced()) // True
		cout << "Balanced tree" << endl; 
	else
		cout << "Unbalanced tree" << endl;

	t.insert(10, "Neon");
	if (t.isHeightBalanced()) // False
		cout << "Balanced tree" << endl; 
	else
		cout << "Unbalanced tree" << endl;

	
    return 0;
}
