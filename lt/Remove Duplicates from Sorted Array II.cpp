#include <iostream>

using namespace std;
/*
int len;
int removeDuplicates(int A[], int n)
{
	if (0 == n)
	{
		return 0;
	}
	
	int sum = 0;
	int count = 1;
	len = n;

	for (int i = 1; i < len; i++)
	{
		if (A[i] == A[i - 1])
		{
			count++;
		}
		else
		{
			if (count < 3)
			{
				sum += count;
			}
			else
			{
				sum += 2;

				int t = count - 2;
				for (int j = i; j < len; j ++)
				{
					A[j - t] = A[j];
				}
				
				len = len - t;
				i = i - t;
			}
			count = 1;
		}
		
	}

	if (count < 3)
	{
		sum += count;
	}
	else
	{
		int t = count - 2;
		sum += 2;
		len = len - t;
	}
	
	
	return sum;
}
*/

int removeDuplicates(int A[], int n)
{

	if (n == 0)

		return 0;



	int cursor = 0;

	for (int i = 1; i < n; i++) {

		if (A[i] == A[cursor]) {

			continue;

		}
		else{

			if (i == cursor + 1)

				cursor++;

			else

				A[++cursor] = A[i];

		}

	}

	return cursor + 1;

}

int main()
{
	int a[] = { 1, 1, 1, 2, 2, 3, 3, 3};
	int sum = removeDuplicates(a, 8);

	cout << sum << endl;

	for (int i = 0; i < sum; i++)
	{
		cout << a[i] << endl;
	}
	
	return 0;
}