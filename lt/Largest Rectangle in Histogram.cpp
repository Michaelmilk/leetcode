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
��ؼ���һ�㣺�ҳ�һ���������С�
����ά��һ��������ջ��ÿ�αȽ�ջ���뵱ǰԪ�ء������ǰԪ�ش���ջ��Ԫ�أ�
����ջ������ϲ�����ջ��ֱ��ջ��Ԫ��С�ڵ�ǰԪ�أ�����������������̡�
��β��վԪ��0���ظ��ϲ�һ�Ρ���Ϊ�ҵ�һ���������к󣬵���һ��Ԫ��С��
��ǰջ��Ԫ��ʱ����ʼ����ջ��Ԫ�ؿ��γɵ������Σ����Ҹ��ݵ�ǰ�±�ֵ����
���ο��ȣ�em��2 1 5 6 2 3,�� ��ջ��Ϊ��1 5 6ʱ����һ��Ԫ����2��
С����ջ��Ԫ��Ϊ�±��Ԫ�ص�ֵ��Ԫ��2��С��Ϊ4��ջ��ֵΪ3��Ԫ��6���±꣬
maxArea = max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));
��������Ĺ�ʽ��������������м��㣨iΪ����������һ��ֵ��С���������Ԫ��2��С��Ϊ4����
��ջ��Ϊ2ʱ������Ԫ��ֵ5�����������ǵ����ģ�����i��ֵ��Ԫ��5��С��3֮���ֵ���Դ���5��
���Թ�ʽ��������ʾ��
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