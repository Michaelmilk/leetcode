#include<iostream>
#include<vector>
#include <string>

using namespace std;

void generate(int leftNum, int rightNum, string s, vector<string> &vec)
{
	if (0 == leftNum && 0 == rightNum)
	{
		vec.push_back(s);
		return;
	}

	if (leftNum > 0)
	{
		generate(leftNum - 1, rightNum, s + '(', vec);
	}

	if (rightNum > 0 && rightNum > leftNum)
	{
		generate(leftNum, rightNum - 1, s + ')', vec);
	}
}

vector<string> generateParenthesis(int n)
{
	vector<string> ret;

	generate(n, n, "", ret);

	return ret;
}

int main()
{
	vector<string> v;
	v = generateParenthesis(4);

	int size = v.size();
	cout << size << endl;

	for (int i = 0; i < size; i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}