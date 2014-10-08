#include <iostream>

using namespace std;

/*
int singleNumber(int A[], int n)
{
	int ret = 0;
	int count = 0;

	for (int i = 0; i < 32; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (1 == ((A[j] >> i) & 0x01))
			{
				count++;
			}
		}
		ret += (count % 3) << i;
	}
	return ret;
}
*/

int singleNumber(int A[], int n) {

	// Note: The Solution object is instantiated only once and is reused by each test case.

	int one = 0;

	int two = 0;

	int three = 0;

	for (int i = 0; i < n; i++){

		two |= A[i] & one;

		one = A[i] ^ one;

		three = ~(one&two);

		one &= three;

		two &= three;

	}

	return one;

}

int main()
{
	int a[] = {2, 2, 2, 3};//{ 1, 2, 1, 4, 1, 4, 4, 6, 6, 3, 6, 2, 2};
	int ans = singleNumber(a, 4);
	cout << ans << endl;
	return 0;
}