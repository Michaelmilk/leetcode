#include <iostream>
#include <algorithm>

using namespace std;

int removeElement(int A[], int n, int elem)
{
	int newLen = 0;

	sort(A, A + n);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (elem != A[i])
		{
			A[count++] = A[i];
		}
	}
	
	newLen = count;
	return newLen;
}

int main()
{
	return 0;
}