#include <iostream>
#include <windows.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int ans = INT_MIN;

int maxPathSumSolve(TreeNode *root)
{
	if (NULL == root)
	{
		return 0;
	}

	int rtVal = root->val;
	int lMax = 0;
	int rMax = 0;

	if (root->left)
	{
		lMax = maxPathSumSolve(root->left);//ͳ�������������ֵ
		if (lMax > 0)//���������ֵС��0��ôֻ��Խ��Խ�٣�������һ��ɸѡ
		{
			rtVal += lMax;
		}
	}
	
	if (root->right)
	{
		rMax = maxPathSumSolve(root->right);
		if (rMax > 0)
		{
			rtVal += rMax;
		}
	}
	
	ans = ans > rtVal ? ans : rtVal;//ͳ��ÿ���������·��ֵ

	return max(root->val, max(root->val + lMax, root->val + rMax));
}

int maxPathSum(TreeNode *root) {

	if (NULL == root)
	{
		return NULL;
	}

	maxPathSumSolve(root);
	
	return ans;
}