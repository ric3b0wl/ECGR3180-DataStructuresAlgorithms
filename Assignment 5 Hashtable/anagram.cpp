/*
Write a program that takes as input a set of words (vector of strings) and returns groups of anagrams for those words. 
An anagram is a word that can be using the letters of another word exactly once. 
Code MUST run in O(n), where n is the number of words.

	unordered_map class will be very useful for this assignment


Example: if the list is "debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis",

the output should be:
		freedom  //word has no anagram in this list
		silent listen
		debitcard badcredit
		elvis lives levis

Note that your particular order could be different.

Include a list of tests that you would use to test the robustness of your code. 
Include a description of the test (or pseudocode, or even running code) as comments in the anagram.cpp file you submit.

*/


#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
// vector<vector<string>> findAnagrams(const vector<string>& dict);

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109
};
//~ reason to use prime instead of the regular index is dulpicate sum
//~ when using regular index
//~     bad => b(2) a(1) d(4) => 2*1*4=8
//~     h => h(8) => 8
//~     8 = 8, bad != h
//* when using prime number
//*     bad => b(3) a(2) d(7) => 3*2*7=42
//*     h => h(19) => 19 
//*     42 != 19, bad !== h

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// return vector as the return value
vector<vector<string>> findAnagrams(const vector<string>& dict) {
    unordered_map<  // hashtable
      string,
      vector<string>,
      string_hasher, 
      string_equal 
    > hashTab{ };

    for(const string& charIdx : dict) {
      string copyStr{ charIdx };
      hashTab[copyStr].push_back(copyStr);
    }
    
    vector<vector<string>> returnVec; 
    for(auto& hashTabValue : hashTab) // for each element of hash table key and value (key : value)
      returnVec.push_back(move(hashTabValue.second));

    return returnVec;
}

// assign all alphabet to index starting from 0 = a
class string_hasher { //* b(1)
private:  
  size_t char2idx(char charIdx) const {
    return charIdx - 'a';
  }

public:
  size_t operator() (const string& inputStr) const {
    size_t hash = 1;
    for (char charIdx: inputStr) {
      size_t idx = char2idx(charIdx);
      hash *= primes[idx];
    }
    return hash;
  }
};


// make key string == to value string 
class string_equal { //* bad == adb
public:
  bool operator() (const string& sortedStr, const string& unsortedStr) const {
      string_hasher hashAlgo{  };
      return hashAlgo(sortedStr) == hashAlgo(unsortedStr);
  }
};