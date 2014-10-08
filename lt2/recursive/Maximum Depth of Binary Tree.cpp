#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(int &maxDep, int tmp, TreeNode *root)
{
	if (NULL == root->left && NULL == root->right)
	{
		tmp += 1;
		maxDep = maxDep > tmp ? maxDep : tmp;
		return;
	}

	tmp += 1;

	if (root->left)
	{
		solve(maxDep, tmp, root->left);
	}

	if (root->right)
	{
		solve(maxDep, tmp, root->right);
	}
}

int maxDepth(TreeNode *root)
{
	int maxDep  = 0;
	if (NULL == root)
	{
		return maxDep;
	}

	solve(maxDep, 0, root);

	return maxDep;
}