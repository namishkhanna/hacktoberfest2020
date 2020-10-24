// C++ program to find length of the shortest supersequence using dynamic programming
#include<bits/stdc++.h> 
using namespace std; 

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

int lcs(char *X, char *Y, int m, int n); 

int shortestSuperSequence(char *X, char *Y) 
{ 
	int m = strlen(X), n = strlen(Y); 
    int l = lcs(X, Y, m, n);  
	return (m + n - l); 
} 

int lcs( char *X, char *Y, int m, int n) 
{ 
	int L[m + 1][n + 1]; 
	int i, j; 

	for (i = 0; i <= m; i++) 
	{ 
		for (j = 0; j <= n; j++) 
		{ 
			if (i == 0 || j == 0) 
				L[i][j] = 0; 

			else if (X[i - 1] == Y[j - 1]) 
				L[i][j] = L[i - 1][j - 1] + 1; 

			else
				L[i][j] = max(L[i - 1][j], 
							L[i][j - 1]); 
		} 
	} 

	return L[m][n]; 
} 

// Driver code 
int main() 
{ 
	char X[] = "AGGTA"; 
	char Y[] = "GXTXAY"; 
	
	cout << "Length of the shortest supersequence is "
		<< shortestSuperSequence(X, Y) << endl; 
		
	return 0; 
} 
