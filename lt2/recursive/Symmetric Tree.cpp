#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkSymmetric(TreeNode *leftTree, TreeNode *rightTree)
{
	if (leftTree == NULL && rightTree == NULL)
	{
		return true;
	}

	if (leftTree == NULL || rightTree == NULL)
	{
		return false;
	}

	if (leftTree->val == rightTree->val)
	{
		return checkSymmetric(leftTree->left, rightTree->right) &&
			checkSymmetric(leftTree->right, rightTree->left);
	}
	else
	{
		return false;
	}
}

bool isSymmetric(TreeNode *root)
{
	if (NULL == root)
	{
		return true;
	}

	return checkSymmetric(root->left, root->right);
}