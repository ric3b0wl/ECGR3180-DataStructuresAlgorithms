//
//  main.cpp
//  Assignment 1 Merge Vectors
//  Data Structures and Algorithms
//  Created by Michael Carter-Barkman on 10/5/20.
//

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

vector<int> mergeVector(vector<vector<int>> vectors) {
    // merge the vectors
    // go through each array and see if the numidx exists. If it
    // does add it to the mergedVector, if it doesnt, go to the
    // next vector. If we are at the end of all the vectors, then
    // done will not be set to false and the loop will exit

    // imagine this function as a 2D grid, each grid has a number in it
    /*
        Array 1: 1 2 3 4         ▲
        Array 2: 5 6      < - arrayidx
        Array 3: 7 8 9           ▼
                 ^
                 |
             < numidx >
    */
    // The outer loop moved the numidx right and the inner loop down
    // because the numidx is in the outer loop the algorithm first goes to
    // the first index of Array 1 then to the first index of Array 2 then first
    // index of Array 3. After this numidx increments and then goes second index of
    // Array 1, second index of Array 2 and so on and so forth
    // Because we dont know the length of each index, we have to manually check it
    // before we access the number. If that index exists then add it to the merged vector
    // if it does not exist, then just skip it and go to the next array
    vector<int> mergedVector = vector<int>();
    for (int numidx = 0; /* true */; ++numidx) { // outer loop
        bool done = true;
        for (int arridx = 0; arridx < vectors.size(); ++arridx) { // inner loop
            if (numidx < vectors[arridx].size()) {
                mergedVector.push_back(vectors[arridx][numidx]);
                done = false;
            } else {
                continue;
            }
        }
        if (done) {
            // done is only true here when we have gone through all
            // the arrays and no more numbers exists
            break;
        }
    }

    return mergedVector;
}


int main() {
   char digit[5];

    while (true) {
        vector<vector<int>> bigArray;
        cout << "Enter Numbers of arrays : ";

        // read user input
        fgets(digit,5,stdin);
        digit[strlen(digit) - 1] = '\0';

        // if input is "-1" , to end read from console
       if (strcmp(digit, "-1") == 0) {
           break;
       }

       int numArrays = (int) strtol(digit, NULL, 10);

       for (int i = 0; i < numArrays; i++) {
            vector<int> smallArray;
            while (true) {
                cout << "Enter Numbers to add to Array ";
                cout << i;
                cout << " : ";
                // read user input
                fgets(digit,5,stdin);
                digit[strlen(digit) - 1] = '\0';

                // if input is "-1" , to end read from console
                if (strcmp(digit, "-1") == 0) {
                    break;
                }

                int value = (int) strtol(digit, NULL, 10);

                smallArray.push_back(value);
            }
            bigArray.push_back(smallArray);
       }
       cout << "Merged array is : " << endl;
       vector<int> merged = mergeVector(bigArray);
       for (int i = 0; i < merged.size(); ++i) {
            cout << merged[i] << ", ";
        }
       cout << endl;
    }
}
