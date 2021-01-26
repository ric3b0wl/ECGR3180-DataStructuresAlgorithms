// C++ program to find factorial of given number 
#include<bits/stdc++.h> 
using namespace std; 
  
// ----- Recursion ----- 
// method to find factorial of given number 
int recursion(int n) 
{ 
    if (n == 0) 
        return 1; 
  
    // recursion call 
    return n * recursion(n - 1); 
} 
  
// ----- Iteration ----- 
// Method to find the factorial of a given number 
int iteration(int n) 
{ 
    int res = 1, i; 
  
    // using iteration 
    for (i = 2; i <= n; i++) 
        res *= i; 
  
    return res; 
} 

  
// Driver method 
int main() 
{ 
    int num = 5; //<<< test number 
    cout << "Factorial of " << num <<  
            " using Recursion is: " << 
            recursion(5) << endl; 
  
    cout << "Factorial of " << num << 
            " using Iteration is: " <<  
            iteration(5); 
  
    return 0; 
} 