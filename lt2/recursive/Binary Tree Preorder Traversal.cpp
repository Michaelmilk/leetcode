#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode *root, vector<int> &ans)
{
	if (NULL == root)
	{
		return;
	}

	ans.push_back(root->val);

	solve(root->left, ans);

	solve(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root)
{
	vector<int> ans;
	if (NULL == root)
	{
		return ans;
	}

	solve(root, ans);

	return ans;
}