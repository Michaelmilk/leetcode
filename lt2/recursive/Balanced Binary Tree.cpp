#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode *root)
{
	if (NULL == root)
	{
		return 0;
	}

	int left = solve(root->left);
	if (left == -1)
	{
		return -1;
	}

	int right = solve(root->right);
	if (right == -1)
	{
		return -1;
	}

	if (abs(left - right) > 1)
	{
		return -1;
	}
	else
	{
		return max(left, right) + 1;
	}
}

bool isBalanced(TreeNode *root)
{
	int ans = 0;
	if (NULL == root)
	{
		return ans;
	}

	ans = solve(root);

	if (ans == -1)
	{
		return false;
	}

	return true;
}