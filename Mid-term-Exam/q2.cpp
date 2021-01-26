/*
ECGR 3180 Fall 2020
Midterm Exam
Question 2 - 30 points
In an ancient land, the beautiful princess Eve had many suitors. She decided on the following procedure to determine which suitor she would marry out of n total suitors. First, all suitors are lined up one after the other in a circle and assigned numbers starting at 1 (first suitor is 1, second is 2, etc.) Then, she chooses a number at random (k) and counts in a circular way (i.e. if she reaches the highest index, she continues from the lowest index still in the list), the k-th person is eliminated from the list and the process continues until only 1 suitor is left (the winner). 

Example 1: Given n = 5, k = 3, the function should return 4.
1 2 3 4 5
At first, index 3 is eliminated. Next, index 1 is eliminated (circular counting). Next, index 5 is eliminated. Next, index 2 is eliminated, leaving index 4 as the last index.

Example 2: Given n = 15, k = 4, the function should return 13.
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
At first, index 4 is eliminated, then 8, then 12, then 1, then 6, then 11, then 2, then 9, then 15, then 10, then 5, then 3, then 7, and then 14, leaving index 13 as the winner.

Write a recursive function 
int luckySuitor(int n, int k)
that will take the number of suitors and the random number to count and return the index of the winning suitor. There are no restrictions on data types used. Solutions that are not recursive will not receive any points.
It may help to work this problem out pen and paper first to be able to observe the patterns and solve the problem recursively.
The code below can be used as starting code for your solution.

As part of this problem, you have to also include a list of tests (a description as comments is enough, you do not need to write the code for them). Given the description above, think of a list of possible tests that your code can be checked against and describe them in a list.
*/

#include <iostream>
#include <vector>

using namespace std;

	// creat array
	// k for counting
	// set cursor to first num and starting count by k
	// cursor move to right by k
	// delete the number on the left side of cursor 
	// recall luckySuitor()
	// check if the array is empty


void luckySuitorRecurse(vector<int> &suitors, int start, int n, int k) {
	if (suitors.size() == 1){  // checking if its empty
		return;
	}
	
	int idx = (start + k) % n; // remainder
	suitors.erase(suitors.begin() + idx);

	luckySuitorRecurse(suitors, idx - 1, n - 1, k);
}

int luckySuitor(int n, int k)
{
	vector<int> suitorsList; 
	
	for (int i = 1; i < n + 1; ++i) {
		suitorsList.push_back(i);
	}
	
	luckySuitorRecurse(suitorsList, -1, n, k);
	
	return suitorsList[0];
	
}

// Test code
int main()
{
	int n = 15;
	int k = 4;
	
	cout << "The winning suitor is at index " << luckySuitor(n, k) << endl; // should be index 13
	return 0;	
}