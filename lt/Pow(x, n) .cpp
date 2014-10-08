#include <iostream>

using namespace std;


/*
double pow1(double x, int n) {
	if (n == 0)
		return 1.0;
	if (n < 0)
		return 1.0 / pow(x, -n);
	double half = pow(x, n >> 1);
	if (n % 2 == 0)
		return half*half;
	else
		return half*half*x;
}
*/

/*
double power(double x, int n)
{
	if (n == 0)
		return 1;

	double v = power(x, n / 2);

	if (n % 2 == 0)
		return v * v;
	else
		return v * v * x;
}

double pow(double x, int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (n < 0)
		return 1.0 / power(x, -n);
	else
		return power(x, n);
}*/


double pow1(double x, int n) {
	int k = n;
	if (n < 0)
	{
		k = -n;
	}
	if (0 == n)
	{
		return 1;
	}

	if (1 == n)
	{
		return x;
	}

	if (-1 == n)
	{
		return 1.0 / x;
	}
	
	double ret = 1.0;

	for (; k > 0; x *= x, k >>= 1)
	{
		if (k & 1)
		{
			ret *= x;
		}
		
	}

	if (n < 0)
	{
		return 1.0 / ret;
	}
	else
	{
		return ret;
	}
}


int main()
{
	cout << pow1(34.00515, -3) << endl;
	return 0;
}