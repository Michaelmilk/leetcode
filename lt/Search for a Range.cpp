#include <iostream>
#include <vector>

using namespace std;

/*
vector<int> searchRange(int A[], int n, int target)
{
	vector<int> ret;

	int left = 0;
	int right = n - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (target > A[mid])
		{
			left = mid + 1;
		} 
		else if (target < A[mid])
		{
			right = mid - 1;
		}
		else
		{
			int i = mid;

			while (i >= left && A[i] == target)
			{
				--i;
			}

			int j = mid;

			while (j <= right && A[j] == target)
			{
				++j;
			}

			ret.push_back(++i);
			ret.push_back(--j);

			return ret;
		}
	}

	ret.push_back(-1);
	ret.push_back(-1);
	
	return ret;
}*/

int b = -1;
int e = -1;

void find(int A[], int l, int r, int target)
{
	if (l > r)
	{
		return;
	}

	int mid = (l + r) / 2;

	if (A[mid] == target)
	{
		if (mid < b || b == -1)
		{
			b = mid;
		}
		if (mid > e)
		{
			e = mid;
		}

		find(A, l, mid - 1, target);
		find(A, mid + 1, r, target);
	}
	else if (A[mid] > target)
	{
		find(A, l, mid - 1, target);
	}
	else
	{
		find(A, mid + 1, r, target);
	}
}

vector<int> searchRange(int A[], int n, int target)
{
	vector<int> ret;
 	//int l = 0;
 	//int r = n - 1;

	//find(A, l, r, target);
	find(A, 0, n - 1, target);

	ret.push_back(b);
	ret.push_back(e);
	return ret;
}
int main()
{
	vector<int> v;
	int a[] = { 5, 7, 7, 8, 8, 10, 11};

	v = searchRange(a, 7, 8);

	for (int i = 0; i < v.size(); i ++)
	{
		cout << v[i] << endl;
	}
	return 0;
}