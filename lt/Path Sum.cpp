#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

bool isExist = false;
int cumsum;

void search(TreeNode *root, int sum)
{
	if (NULL == root)
	{
		return;
	}
	else
	{
		cumsum += root->val;
	}

	if (NULL == root->left && NULL == root->right)
	{
		if (cumsum == sum)
		{
			isExist = true;
		}
	}
	
	search(root->left, sum);
	if (root->left)
	{
		cumsum -= (root->left)->val;
	}
	search(root->right, sum);
	if (root->right)
	{
		cumsum -= (root->right)->val;
	}
}



bool hasPathSum(TreeNode *root, int sum)
{
	cumsum = 0;
	search(root, sum);

	if (isExist)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}