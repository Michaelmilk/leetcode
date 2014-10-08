#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkSame(TreeNode *p, TreeNode *q)
{
	if (NULL == p && NULL == q)
	{
		return true;
	}

	if (NULL == p || NULL == q)
	{
		return false;
	}

	if (p->val == q->val)
	{
		return checkSame(p->left, q->left) && checkSame(p->right, q->right);
	}
	else
	{
		return false;
	}
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
	if (NULL == p && NULL == q)
	{
		return true;
	}

	return checkSame(p, q);
}