// Q3: (10 pts)
//Theory questions: What is the Big-Oh run time for the following snippets of code/problems? Write your answer after every snippet of code in a readable and easy to understand way.

a)
int sum = 0;
for (int i = 0; i < n; i += 5)
	for (int i = 0; i < n*n+2; i++)
		sum++;
			
		// O(n^2)
	
b) 
int sum = 0;
for (int i = 0; i < n; i++)
	for (int i = 0; i < 2*n; i = i * n + 1)
		sum++;
		
		// O(n)
	
c)
Use the Master method on the following equation to calculate its Big-Oh runtime:
T(n) = 4*T(n/2) + 5
		
		// O(n^2)


d)
Use the Master method on the following equation to calculate its Big-Oh runtime:
T(n) = 2*T(n/6) + O(n)

		// O(n)
