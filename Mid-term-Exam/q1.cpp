/*
ECGR 3180 Fall 2020
Midterm Exam
Question 1 - 60 points
Range swap sort with deduplication: Assume that we have a new sorting algorithm that sorts a list of integers in decrementing order and removes duplicates. 
The algorithm will search for the location of the currently-largest integer and swaps all integers in the range between the insert position and the largest integer (this results in an inversion of the positions of all integers in the sub-list). This process repeats until the list is sorted in decrementing order. 
In some cases, it is possible to have repeated values. If this is the case, the repeated number must be removed from the list during the sorting process when the value to be inserted in the sorted list is reached (i.e. it cannot be removed from the list at the end once the list is sorted).
Return a sorted list without duplicates.
Assume the input is given as a vector named nums.

What is the Big-Oh runtime of your solution? Explain your reasoning.

Include a list of tests as comments in the code. You do not have to write the code for the tests, just describe them.

----------------------------------------------------

Example 1: nums = {12, 9, 7, 6, 2, 0}
Array is sorted, nothing to do, but algorithm will still run through the checks. Do not use a Boolean variable to iterate through and search for a swap.

Example 2: nums = {2, 5, 10, 23, 9}
After first pass (23 is largest, insert in index 0): {23, 10, 5, 2, 9}
After second pass (10 is next largest, insert in index 1 -- nothing to do, no swaps): {23, 10, 5, 2, 9}
After third pass (9 is next largest, insert in index 2): {23, 10, 9, 2, 5}
After fourth pass (5 is next largest, insert in index 3): {23, 10, 9, 5, 2}
Done!

Example 3: nums = {2, 5, 5, 10, 23, 9} -- same as Example 2 but contains duplicate
After first pass (23 is largest, insert in index 0): {23, 10, 5, 5, 2, 9}
After second pass (10 is next largest, insert in index 1 -- nothing to do, no swaps): {23, 10, 5, 5, 2, 9}
After third pass (9 is next largest, insert in index 2): {23, 10, 9, 2, 5, 5}
After fourth pass (5 is next largest, insert in index 3): {23, 10, 9, 5, 5, 2}
After fifth pass (5 is next largest, however, there is a 5 already in the list. Remove this from vector.): {23, 10, 9, 5, 2}
Only one element is left to be checked (2), so it is sorted. Done!

*/


// the big O of the program will be: O(n^2), as in inserction sorting "n" is the size of vector array
#include <iostream>
#include <vector>

using namespace std;

vector<int> rangeSwapDedup(vector<int> nums)
{
  // Your code goes here
	// i ← 1
	// while i < length(A)
	//     j ← i
	//     while j > 0 and A[j-1] > A[j]
	//         swap A[j] and A[j-1]
	//         j ← j - 1
	//     end while
	//     i ← i + 1
	// end while

	vector<int> sortedPart;
	while (nums.size() != 0) {
		// find the next largest number
		int current_largest_num_idx = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[current_largest_num_idx]) {
				current_largest_num_idx = i;
			}
		}
		
		// if number not duplicate, then add it to the sorted list
		if (sortedPart.size() == 0) {
		    sortedPart.push_back(nums[current_largest_num_idx]);
		} 
		// check vector is empty
		else if (sortedPart.size() != 0 && sortedPart.back() != nums[current_largest_num_idx]) {
			sortedPart.push_back(nums[current_largest_num_idx]);
		}
		
    // erase the element just added
		nums.erase(nums.begin() + current_largest_num_idx);
	}
	return sortedPart;
}

// helper function, prints vector
void print(vector<int> nums)
{
	for (auto num : nums) 
		cout << num << " ";
	cout << endl;
}

// test code
// int main()
// {
// 	vector<int> nums {12, 32, 45, -1, 32, 5, 125};
	
// 	nums = rangeSwapDedup(nums);
// 	print(nums);	// should be: 125 45 32 12 5 -1	
// }







