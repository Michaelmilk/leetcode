#include <iostream>

using namespace std;

void merge(int A[], int m, int B[], int n)
{
	if (0 == m)
	{
		for (int i = 0; i < n; i++)
		{
			A[i] = B[i];
		}
	}

	if (0 == n)
	{
		return;
	}
	
	if (B[n - 1] <= A[0])
	{
		for (int i = 0; i < m; i++)
		{
			A[i + n] = A[i];
		}

		for (int j = 0; j < n; j++)
		{
			A[j] = B[j];
		}
		return;
	}

	if (B[0] >= A[m - 1])
	{
		for (int i = 0; i < n; i++)
		{
			A[m + i] = B[i];
		}
		return;
	}
	
	int k = 0;
	int j;

	for (int i = 0; i < n; i++)
	{
		for (j = k; j < m + i; j++)
		{
			if (A[j] > B[i])
			{
				for (int t = m + i - 1; t >= j; t--)//将插入位置之后数值往后移动
				{
					A[t + 1] = A[t];
				}
				k = j + 1;
				A[j] = B[i];//将B中的值插入A中
				break;
			}
		}

		if (j == m + i)//如果之后B中的数值都比A中的大，则直接复制
		{
			for (int t = i; t < n; t++)
			{
				A[m + i] = B[t];
				i++;
			}
			break;
		}
	}
}

int main()
{
	int *a = new int[6];
	a[0] = 4;
	int  b[] = { 1, 2, 3, 5, 6 };
	merge(a, 1, b, 5);

	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}
}