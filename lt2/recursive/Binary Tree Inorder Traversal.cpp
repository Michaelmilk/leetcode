#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode *root, vector<int> & ans)
{
	if (NULL == root->left && NULL == root->right)
	{
		ans.push_back(root->val);
		return;
	}

	if (root->left)
	{
		solve(root->left, ans);
	}

	ans.push_back(root->val);

	if (root->right)
	{
		solve(root->right, ans);
	}
}

vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> ans;
	if (NULL == root)
	{
		return ans;
	}

	solve(root, ans);

	return ans;
}