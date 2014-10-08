#include <iostream>
#include <windows.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root)
{
	if (NULL == root)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	
	int leftSum = minDepth(root->left);
	int rightSum = minDepth(root->right);

	if (0 == leftSum)
	{
		return rightSum + 1;
	}
	else if (0 == rightSum)
	{
		return leftSum + 1;
	}
	else
	{
		return max(leftSum, rightSum) + 1;
	}
}