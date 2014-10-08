#include<iostream>
using namespace std;


int divide(int dividend, int divisor) {
	// Note: The Solution object is instantiated only once.
	long long a = abs((double)dividend);
	long long b = abs((double)divisor);
	long long res = 0;
	while (a >= b)
	{
		long long c = b;
		for (int i = 0; a >= c; i++, c <<= 1)
		{
			a -= c;
			res += 1 << i;//1×óÒÆiÎ»
		}
	}
	return ((dividend ^ divisor) >> 31) ? (-res) : (res);
}

int main()
{
	int div = divide(6, 2);
	cout << div << endl;

	int k = 4 >> 1;

	cout << k << endl;
	return 0;
}