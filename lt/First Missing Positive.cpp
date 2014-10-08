#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// int firstMissingPositive(int A[], int n)
// {
// 	int ret = 1;
// 	
// 	if (0 == n)
// 	{
// 		return ret;
// 	}
// 	
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (A[i] <= 0)
// 		{
// 			A[i] = n + 1;//如果A[i] = n，那么A[A[i] - 1] 就会把A[n - 1]设置为负数，此时误以为数组含有值n
// 		}
// 	}
// 
// 	for (int i = 0; i < n; i++)
// 	{
// 		
// 		if (A[i] < 0 && 0 <= (-A[i] - 1) && (-A[i] - 1) < n)
// 		{
// 			if (A[-A[i] - 1] < 0)
// 			{
// 				continue;
// 			}
// 			else
// 			{
// 				A[-A[i] - 1] = -A[-A[i] - 1];
// 			}
// 		}
// 		else if (0 <= A[i] - 1 && A[i] - 1 < n)
// 		{
// 			if (A[A[i] - 1] < 0)
// 			{
// 				continue;
// 			}
// 			else
// 			{
// 				A[A[i] - 1] = -A[A[i] - 1];
// 			}
// 		}
// 		
// 	}
// 	
// 	int sign;
// 	for (sign = 0; sign < n; sign++)
// 	{
// 		if (A[sign] > 0)
// 		{
// 			ret = sign + 1;
// 			break;
// 		}
// 	}
// 
// 	if (sign == n)
// 	{
// 		return n + 1;
// 	}
// 	
// 
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << A[i] << " ";
// 	}
// 	cout << endl;
// 	
// 	return ret;
// }

//---------------------------------------------------------------------------------------

// int firstMissingPositive(int A[], int n)
// {
// 	vector<bool> hash(n, false);
// 	int ret = 0;
// 
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (0 < A[i] && A[i] <= n)
// 		{
// 			hash[A[i] - 1] = true;
// 		}
// 	}
// 	
// 	int sign = 0;
// 	for (sign = 0; sign < n; sign++)
// 	{
// 		if (!hash[sign])
// 		{
// 			ret = sign + 1;
// 			break;
// 		}
// 		
// 	}
// 	
// 	if (sign == n)
// 	{
// 		return n + 1;
// 	}
// 
// 	return ret;
// }

int firstMissingPositive(int A[], int n)
{
	int i = 0;

	while (i < n)
	{
		if (A[i] != i + 1 && A[i] >= 0 && A[i] <= n && A[i] != A[A[i] - 1])
		{
			swap(A[i], A[A[i] - 1]);
		}
		else
		{
			i++;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (A[i] != i + 1)
		{
			return i + 1;
		}
	}

	return n + 1;
}

int main()
{
	int a[] = {1};//{ 0, 2, 2, 1, 1};//{ 9, 7, 6, 5, 3, 1, 4, 5, 8, 4 };
	int r = firstMissingPositive(a, 1);
	cout << r << endl;
	return 0;
}