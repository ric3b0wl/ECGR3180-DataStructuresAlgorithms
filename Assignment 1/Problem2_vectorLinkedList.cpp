/*
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

#include <iostream>
#include <vector>

using namespace std;

void  mergeVector();

int main() 
{ 
        mergeVector();
} 

/*******************************************************************/
// YOUR FUNCTION mergeVectors GOES HERE. IT WILL BE OF TYPE void AND TAKE

vector<int> mergeVector(vector<vector<int>> vectors){

	int largestVectorSize = 0;

	for (int i = 0; i < vectors.size(); ++i){

		if (vectors[i].size() > largestVectorSize){

			largestVectorSize = vectors[i].size();
		}
	}

	vector<int> mergedVector; //merge the vector

	for (int numIndex = 0; numIndex < largestVectorSize; ++numIndex){ //going thru each array
		bool endOfArray = true;
        for (int arridx = 0; arridx < vectors.size(); ++arridx) {
            if (numIndex < vectors[arridx].size()) {
                mergedVector.push_back(vectors[arridx][numIndex]);
                endOfArray = false;
            } else {
                continue;
            }
        }
        if (endOfArray) {
            break;
        }

	}

	return mergedVector;
}

void mergeVector(){

	// vector<vector<int>> testArray = {
	// 	{1, 2, 3, 4},
	// 	{5, 6, 7, 8}
	// };

	// vector<vector<int>> testArray = {
	// 	{1, 2, 3, 4, 9, 10},
	// 	{5, 6, 7, 8},
	// 	{9, 10, 11}
	// };

	vector<vector<int>> testArray = {
		{1, 2, 3, 4, 9, 10, 11},
		{5, 6, 7, 8},
		{9, 10, 11},
		{11, 12, 13, 14, 19, 20}
	};

	vector<int> merged = mergeVector(testArray);

  cout << "Total vector entered: " << merged.size() << endl << "Output: ";
	for (int i = 0; i < merged.size(); ++i){
		cout << merged[i] << ", ";
	}

	cout << endl;
}