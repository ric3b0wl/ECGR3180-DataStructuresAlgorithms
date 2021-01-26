/*
ECGR 3180 Fall 2020
Pre-test
Question 2:

The following problem involves the design of function to merge multiple vectors using iterators. For more information and references to use the vector container, see http://www.cplusplus.com/reference/vector/vector/ or any other reference. This function will require the use of an iterator to traverse the vector.

- Write a function (named "mergeVectors") that will take in user input for a list of integers for each vector and output a merged vector to the console. The user will first enter a list of vectors as an array of vectors and then merging will occur. For an example of an array of vectors
-- The first value requested as user input is the number of vectors that will be entered. This number must be larger than 0. Include a checkpoint for this in your code and do no advance until proper input is given.
-- The code will then request for the user to enter the values in each vector. The values will be non-negative. If the user enters a negative value (such as -1 or more negative), the function will stop taking user data for the current vector and move to asking for data for the next vector in the array (entering a negative value essentially means the user is done entering data for the given vector.)
-- Populate the array with vectors (possibly of different sizes, depending on user input) using the approach described above.

- After the array of vectors has been populated with user data, iterate through every element in the array of vectors and output the elements to the console using the following algorithm:
-- The code will output the elements at index [0] for all vectors, then for index [1] if available, etc.
-- If a vector is shorter than the current index to be output, it will be skipped during output and the code will move to the next vector in the array, etc. See the examples below on how this merging will occur.

------------------------------------------------------------------------------

Example 1:
If the user has entered all of the vectors below as part of your code (this is just showing the vectors, not how they are stored), then the merging will be as follows:

v1 = [1, 2, 3, 4]
v2 = [5, 6, 7, 8]

Console output:
1, 5, 2, 6, 3, 7, 4, 8

-----------------------------------

Example 2: (spacing is added in this example for readability)

v1 = [1,  2,  3, 4, 9, 10]
v2 = [5,  6,  7, 8]
v3 = [9, 10, 11]

Console output:
1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 9, 10

-----------------------------------

Example 3: (spacing is added in this example for readability)

v1 = [1,   2,  3,  4,  9, 10, 11]
v2 = [5,   6,  7,  8]
v3 = [9,  10, 11]
v4 = [11, 12, 13, 14, 19, 20]

Console output:
1, 5, 9, 11, 2, 6, 10, 12, 3, 7, 11, 13, 4, 8, 14, 9, 19, 10, 20, 11

*/

/*******************************************************************/

// YOUR FUNCTION mergeVectors GOES HERE. IT WILL BE OF TYPE void AND TAKE NO ARGUMENTS. ALL OPERATIONS WILL TAKE PLACE IN THIS FUNCTION.

/*******************************************************************/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> mergeVector(vector<vector<int>> vectors){

	int largestVectorSize = 0;

	for (int i = 0; i < vectors.size(); ++i){

		if (vectors[i].size() > largestVectorSize){

			largestVectorSize = vectors[i].size();
		}
	}

	vector<int> mergedVector; //merge the vector

	for (int numIndex = 0; numIndex < largestVectorSize; ++numIndex){ //going thru each array
		
		for (int i = 0; i < vectors.size(); ++i) {
		if (vectors[i].size() > largestVectorSize) {
			largestVectorSize = vectors[i].size();
      for (int r = 0; r = )  //runing out of time, double for loop to push back by roll and column
		}
		}
	}

	return mergedVector;
}

int main() 
{
	//Testing your code
	//mergedVector();

  

	vector<vector<int>> testArray1 = {
		{1, 2, 3, 4},
		{5, 6, 7, 8}
	};

	vector<vector<int>> testArray2 = {
		{1,  2,  3, 4, 9, 10},
		{5,  6,  7, 8},
		{9, 10, 11}
	};

	vector<vector<int>> testArray3 = {
		{1,   2,  3,  4,  9, 10, 11},
		{5,  6,  7, 8},
		{9, 10, 11},
		{11, 12, 13, 14, 19, 20}
	};

	vector<int> merged = mergeVector(testArray3);
	//vector<int> merged = mergeVector(testArray2);
	//vector<int> merged = mergeVector(testArray1);

  std::cout << merged.size() << std::endl;
	for (int i = 0; i < merged.size(); ++i){
		cout << merged[i] << ", ";
	}

	cout << endl;
}