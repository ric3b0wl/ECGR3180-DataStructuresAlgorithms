// Q3: (10 pts)
//Theory questions: What is the Big-Oh run time for the following snippets of code/problems? Write your answer after every snippet of code in a readable and easy to understand way.

a)		
int sum = 0;
for (int i = 0; i < n; i += 5)
	for (int i = 0; i < n*n; i++)
		sum++;
	
		// O(n^2)
b)		
int sum = 0;
for (int i = 0; i < n; i++)
	for (int i = 0; i < n*n*n; i = i * n + 1)
		sum++;

		// O(n)
	
c)		
Use the Master method on the following equation to calculate its Big-Oh runtime:
T(n) = 4*T(n/2) + 5
		
		// T(n)= aT(n/b) + Theta {n^k [(log n)^i]}
		// T(n) = aT(n/b) + n
		// O(log n)

d)
Use the Master method on the following equation to calculate its Big-Oh runtime:
T(n) = 2*T(n/6) + O(n)

		// O(n log n)
