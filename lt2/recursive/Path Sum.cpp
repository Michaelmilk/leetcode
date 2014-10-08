#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(int count, int sum, bool &ans, TreeNode *root)
{
	if (root->left == NULL && root->right == NULL)
	{
		if (count + root->val == sum)
		{
			ans = true;
		}
		return;
	}

	if (root->left)
	{
		solve(count + root->val, sum, ans, root->left);
	}
	
	if (ans)
	{
		return;
	}

	if (root->right)
	{
		solve(count + root->val, sum, ans, root->right);
	}
}

bool hasPathSum(TreeNode *root, int sum)
{
	if (NULL == root)
	{
		return false;
	}

	bool ans = false;
	solve(0, sum, ans, root);
	return ans;
}

int main()
{

	return 0;
}