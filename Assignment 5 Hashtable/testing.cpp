// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
//	typically using all the original letters exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]


// Example 2:
// Input: strs = [""]
// Output: [[""]]


// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]
 
// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lower-case English letters.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
public:

class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(const auto& s:strs) {
            string t {s};
            sort(t.begin(),t.end());
            map[t].push_back(s);
        }
        
        vector<vector<string>> res;
        for(auto& i:map) res.push_back(move(i.second));
        return res;
    }
};
