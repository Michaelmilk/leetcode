#include <iostream>

using namespace std;



// int searchInsert(int A[], int n, int target)
// {
// 	int left = 0;
// 	int right = n - 1;
// 	int mid = 0;
// 
// 	while (left <= right)
// 	{
// 		mid = (left + right) / 2;
// 
// 		if (A[mid] == target)
// 		{
// 			return mid;
// 		}
// 		else if (A[mid] < target)
// 		{
// 			left = mid + 1;
// 		}
// 		else
// 		{
// 			right = mid - 1;
// 		}
// 	}
// 
// 	if (target < A[0])
// 	{
// 		return 0;
// 	}
// 	
// 	if (target > A[n - 1])
// 	{
// 		return n;
// 	}
// 	
// 	if (target > A[mid])
// 	{
// 		return mid + 1;
// 	}
// 	
// 	if (target < A[mid])
// 	{
// 		return mid;
// 	}
// 	
// }
 int searchInsert(int A[], int n, int target) 
 {
		int i = 0;
		int j = n - 1;

		while (i <= j) {
			int mid = (int)((i + j) / 2);
			if (A[mid] == target) {
				return mid;
			}
			else if (A[mid] > target) {
				j = mid - 1;
			}
			else {
				i = mid + 1;
			}
		}
		return i;
}


int main()
{
	int a[] = { 1, 3, 5, 6 };
	int ret = searchInsert(a, 4, 4);
	cout << ret << endl;
	return 0;
}