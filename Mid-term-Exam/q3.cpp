/*
ECGR 3180 Fall 2020
Midterm Exam
Question 3 - 10 points
Theory questions: What is the Big-Oh run time for the following snippets of code/problems? Write your answer after every snippet of code in a readable and easy to understand way.
*/
a)
int sum = 0;
for (int i = 0; i < n; i += 2)
	for (int i = 0; i < n*n; i++)
		sum++;
// O(n^2)


b) 
int sum = 0;
for (int i = 0; i < n; i++)
	for (int i = 0; i < n*n; i = i * n)
		sum++;
// O(n^2)


c)
Use the Master method on the following equation to calculate its Big-Oh runtime:
T(n) = 3*T(n/3) + 1
// O(n logn)


d)
Use the Master method on the following equation to calculate its Big-Oh runtime:
T(n) = 2*T(n/2) + O(n^2)
// O(n logn) + O(n^2) = O (n logn)