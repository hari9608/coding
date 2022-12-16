// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function that finds the minimum
// number of flips to make the
// binary string alternating if
// left circular rotation is allowed
int MinimumFlips(string s, int n)
{
	int a[n];

	for(int i = 0; i < n; i++)
	{
		a[i] = (s[i] == '1' ? 1 : 0);
	}

	// Initialize prefix arrays to store
	// number of changes required to put
	// 1s at either even or odd position
	int oddone[n + 1];
	int evenone[n + 1];

	oddone[0] = 0;
	evenone[0] = 0;

	for(int i = 0; i < n; i++)
	{
		
		// If i is odd
		if (i % 2 != 0)
		{
			
			// Update the oddone
			// and evenone count
			oddone[i + 1] = oddone[i] +
								(a[i] == 1 ? 1 : 0);
			evenone[i + 1] = evenone[i] +
								(a[i] == 0 ? 1 : 0);
		}

		// Else i is even
		else
		{
			
			// Update the oddone
			// and evenone count
			oddone[i + 1] = oddone[i] +
								(a[i] == 0 ? 1 : 0);
			evenone[i + 1] = evenone[i] +
								(a[i] == 1 ? 1 : 0);
		}
	}

	// Initialize minimum flips
	int minimum = min(oddone[n], evenone[n]);

	// Check if substring[0, i] is
	// appended at end how many
	// changes will be required
	for(int i = 0; i < n; i++)
	{
		if (n % 2 != 0)
		{
			minimum = min(minimum,
						oddone[n] -
						oddone[i + 1] +
						evenone[i + 1]);
			minimum = min(minimum,
						evenone[n] -
						evenone[i + 1] +
						oddone[i + 1]);
		}
	}

	// Return minimum flips
	return minimum;
}

// Driver Code
int main()
{
	
	// Given String
	string S = "000001100";

	// Length of given string
	int n = S.length();

	// Function call
	cout << (MinimumFlips(S, n));
}

// This code is contributed by chitranayal
