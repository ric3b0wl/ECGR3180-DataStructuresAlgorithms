// Practice questions for pretest - Your solution

#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

vector<string> removeDuplicates(const vector<string>& s) {
    // Your code here
    
    sort(s.begin(), s.end());
  	s.erase(unique(s.begin(), s.end()), s.end());
  	
}