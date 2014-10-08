#include <iostream>
#include <Windows.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode *root, int &maxVal)
{
	if (NULL == root->left && NULL == root)
	{
		return root->val;
	}

	int left = 0;
	if (root->left)
	{
		left = solve(root->left, maxVal);
		left = left > 0 ? left : 0;
	}

	int right = 0;
	if (root->right)
	{
		right = solve(root->right, maxVal);
		right = right > 0 ? right : 0;
	}
	

	//将包含当前节点的最佳路径与max 相比较，将较大的值复制给maxval
	maxVal = maxVal > max(root->val, root->val + left + right) ? maxVal : max(root->val, root->val + left + right);
	//将当前节点左侧或者右侧或者当前节点中最大的值返回给上一层节点进行计算
	int count = max(root->val, max((root->val + left), (root->val + right)));
	return count;
}

int maxPathSum(TreeNode *root)
{
	if (NULL == root)
	{
		return 0;
	}

	int maxVal = root->val;
	solve(root, maxVal);
	return maxVal;
}

