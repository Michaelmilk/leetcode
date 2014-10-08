#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkValid(int left, int right, TreeNode *root)
{
	if (NULL == root)
	{
		return true;
	}

	if (left < root->val && root->val < right)
	{
		return checkValid(left, root->val, root->left) &&
			checkValid(root->val, right, root->right);
	}
	else
	{
		return false;
	}
}

bool isValidBST(TreeNode *root)
{
	if (NULL == root)
	{
		return true;
	}

	return checkValid(INT_MIN, INT_MAX, root);
}