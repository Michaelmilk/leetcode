#include <iostream>

using namespace std;

void sortColors(int A[], int n)
{
	int j = -1;
	int k = -1;

	for (int i = 0; i < n; i++)
	{
		int v = A[i];
		A[i] = 2;

		if (0 == v)
		{
			A[++j] = 1;
			A[++k] = 0;
		} 
		else if (1 == v)
		{
			A[++j] = 1;
		}
	}
	
}