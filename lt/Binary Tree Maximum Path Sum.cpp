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
		lMax = maxPathSumSolve(root->left);//统计左子树的最大值
		if (lMax > 0)//如果子树的值小于0那么只会越加越少，所以做一个筛选
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
	
	ans = ans > rtVal ? ans : rtVal;//统计每颗树的最大路径值

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