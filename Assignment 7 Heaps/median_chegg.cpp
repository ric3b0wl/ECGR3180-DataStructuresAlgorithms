// Given a sequence of integer numbers x1, x2, ..., xn input one-by-one, 
// find the median as the numbers arrive. 
// Median is the middle of a sorted list of numbers for an odd count. 
// For an even count of numbers, the median is the integer average of the middle two numbers. 

// Must use a heap. Heaps are implemented using the priority_queue container from the STL. 


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// Helper function to print queue for debugging 

template<typename T> void printQueue(T& q) {
    T q_copy(q);
    while(!q_copy.empty()) {
        cout << q_copy.top() << " ";
        q_copy.pop();
    }
    cout << endl;
}
 

vector<int> findMedian(vector<int>& data) {
    priority_queue<int> max_heap; // STL Max-heap
    priority_queue<int, vector<int>, greater<int> > min_heap; // STL Min-heap
    
    vector<int> res;
    
    double median = data[0];   // when only one number arrived
    max_heap.push(data[0]);
    res.push_back(median);
    
    for(int i = 1; i<data.size(); i++) 
    { 
        int x = data[i]; 
          
        if(max_heap.size() > min_heap.size())     // when left side heap has more elements
        { 
            if(x < median)         
            { 
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(x); 
            } 
            else
                min_heap.push(x); 
                median = (double)( max_heap.top() + min_heap.top() )/2; 
        } 
          
        else if(max_heap.size() == min_heap.size())     // when both heaps have equal elements
        { 
            if(x < median) 
            { 
                max_heap.push(x); 
                median = (double)max_heap.top(); 
            } 
            else
            { 
                min_heap.push(x); 
                median = (double)min_heap.top(); 
            } 
        } 
            
        else            // when right side heap has more elements
        { 
            if(x > median) 
            { 
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(x); 
            } 
            else
                max_heap.push(x); 
                median = (double)(max_heap.top() + min_heap.top())/2; 
              
        } 
        res.push_back(median); 
    } 
    
    return res;
}



//////////////////////////////////////////////////////////////////////////////////
int main() {
    vector<int> data_stream = {5, 42, 29, 85, 95, 99, 2, 15};
    // i-th element of median_stream is median of first i elements of input 
    vector<int> median_stream = findMedian(data_stream) ;
    for (auto ele: median_stream) {
        cout << ele << " "; // Answer should be - 5 23 29 35 42 63 42 35 
    }
    cout << endl;
}