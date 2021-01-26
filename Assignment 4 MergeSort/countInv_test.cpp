
/* Count the number of inversions in O(n log n) time */
#include <iostream>
#include <vector>


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

int main()
{
    int n;
    vector<int> numvec{4, 5, 6, 1, 2, 3};
    n = countInv(numvec);
    cout << "Number of inversions " << n << endl; // Should be 9
    
    numvec = {1, 2, 3, 4, 5, 6};
    n = countInv(numvec);
    cout << "Number of inversions " << n << endl; // Should be 0
    
    numvec = {6, 5, 4, 3, 2, 1};
    n = countInv(numvec);
    cout << "Number of inversions " << n << endl;  // Should be 15
    
    numvec = {0, 0, 0, 0, 0, 0};
    n = countInv(numvec);
    cout << "Number of inversions " << n << endl;;  // Should be 0
}
