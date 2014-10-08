#include<iostream>

using namespace std;

int search(int A[], int n, int target)
{
	int front = 0;
	int rear = n - 1;

	while (front <= rear)//=是为了满足n=1的情况
	{
		int m = (front + rear) / 2;

		if (target == A[m])
		{
			return m;
		}

		if (A[m] >= A[front])
		{
			if (target >= A[front] && target < A[m])
			{
				rear = m - 1;
			}
			else
			{
				front = m + 1;
			}
		}
		else
		{
			if (target > A[m] && target <= A[rear])
			{
				front = m + 1;
			}
			else
			{
				rear = m - 1;
			}
		}
	}
	return -1;
}

int main()
{
	int a[] = {5, 6, 7, 8, 1, 2, 3, 4 };
	int ret = search(a, 8, 3);
	cout << ret << endl;
	return 0;
}