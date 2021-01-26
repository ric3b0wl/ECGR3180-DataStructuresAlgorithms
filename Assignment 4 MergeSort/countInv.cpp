/*
? What would the complexity of a brute force approach be?
~ using brute force approach, big O of bubble sort will be O(n^2)

Code an O(nlog(n)) algorithm to count the number of inversions. Hint - piggy back on the merging step of the mergesort algorithm.
Note:
1. Brute force solutions will get zero points. Your solution has to be O(n log n). 
2. Study the merge sort C++ solution uploaded herePreview the document (also under Files/Code) carefully.  
3. I will be testing your solution with additional tests. So please test your code thoroughly. 
*/


// Count inversions - homework
// Based off of mergesort
#include <vector>
#include <algorithm> // For copy

using namespace std;


int mergeInv(vector<int>& nums, vector<int>& left, vector<int>& right) {
    int outputIdx = 0, ltIdx = 0, rtIdx = 0;
    int inv = 0;
    while ((ltIdx < left.size()) && (rtIdx < right.size())) {
		if (left[ltIdx] <= right[rtIdx]) {
			nums[outputIdx] = left[ltIdx];
			outputIdx++; 
			ltIdx++; // left index pointer shift by a digit
		} else {
			nums[outputIdx] = right[rtIdx];
			outputIdx++; 
			rtIdx++; // right index pointer shift by a digit
            inv += left.size() - ltIdx; // add number of remaining elements in left array to inversions
		}
	}

    //# take leftover from left array and put it in the output array
    while(ltIdx < left.size())  { //~ when right array is empty
  	nums[outputIdx] = left[ltIdx]; 
		outputIdx++; 
		ltIdx++;
	}

    //# take leftover from right array and put it in the output array
    while(rtIdx < right.size()) { //~ when left array is empty
		nums[outputIdx] = right[rtIdx];
		outputIdx++;
		rtIdx++;
	}

    return inv;
}

int countInv(vector<int>&nums) { //~ mergesort + count the total inversions
    //Base case - one element, nothing to sort
    int left_inversions = 0, right_inversions = 0, current_inversions = 0;
	if (nums.size() > 1) {
		int mid = nums.size()/2; 
		vector<int> left(mid);
		vector<int> right(nums.size()-mid);
		copy(nums.begin(), nums.begin() + mid, left.begin());
		copy(nums.begin() + mid, nums.end(), right.begin());

        //# adding inversions
		left_inversions = countInv(left);
		right_inversions = countInv(right);
		current_inversions = mergeInv(nums, left, right);
	}
    
    return left_inversions + right_inversions + current_inversions; //current-merge return total

}



