#include <iostream>
#include <vector>
#include <stack>
#include <windows.h>

using namespace std;

/*
int largestRectangleArea(vector<int> &height)
{
	int size = height.size();
	if (0 == size)
	{
		return 0;
	}
	
	int maxArea = 0;
	int minHeight = height[0];
	int width = 0;

	for (int i = 0; i < size; i++)
	{
		width = 1;
		minHeight = height[i];
		maxArea = (minHeight * width) > maxArea ? (minHeight * width) : maxArea;
		for (int j = i + 1; j < size; j++)
		{
			width++;
			minHeight = minHeight > height[j] ? height[j] : minHeight;
			maxArea = (minHeight * width) > maxArea ? (minHeight * width) : maxArea;
		}
	}
	return maxArea;
}
*/

/*
最关键的一点：找出一个递增序列。
可以维护一个递增的栈，每次比较栈顶与当前元素。如果当前元素大于栈顶元素，
则入栈，否则合并现有栈。直至栈顶元素小于当前元素，则继续进行上述过程。
结尾入站元素0，重复合并一次。因为找到一个递增序列后，当下一个元素小于
当前栈顶元素时，开始计算栈中元素可形成的最大矩形，并且根据当前下标值计算
矩形宽度（em：2 1 5 6 2 3,： 当栈中为：1 5 6时，下一个元素是2，
小于以栈顶元素为下标的元素的值，元素2的小标为4，栈顶值为3是元素6的下标，
maxArea = max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));
按照上面的公式对最大矩形面积进行计算（i为递增序列下一个值得小标就是上述元素2的小标为4）。
当栈顶为2时，代表元素值5，由于序列是递增的，所以i的值与元素5的小标3之间的值绝对大于5，
所以公式如上述所示）
*/
int largestRectangleArea(vector<int> &height) {
	int maxArea = 0;
	height.push_back(0);
	stack<int> stk;
	int i = 0;
	while (i < height.size())
	{
		if (stk.empty() || height[stk.top()] <= height[i])
		{
			stk.push(i++);
		}
		else
		{
			int t = stk.top();
			stk.pop();
			maxArea = max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));
		}
	}
	return maxArea;
}

int main()
{
	vector<int> v = {2, 1, 5, 6, 2, 3};//{ 1, 1, 1, 6, 2 };
	cout << largestRectangleArea(v) << endl;
	return 0;
}