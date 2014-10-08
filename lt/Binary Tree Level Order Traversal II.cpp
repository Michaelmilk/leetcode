#include <iostream>
#include <vector>

using namespace  std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

vector<int> ret[1000];
int deep = 0;
void solve(int dep, TreeNode *root)
{
	if (NULL == root)
	{
		return;
	}

	deep = deep > dep ? deep : dep;
	ret[dep].push_back(root->val);
	
	if (root->left)
	{
		solve(dep + 1, root->left);
	}
	
	if (root->right)
	{
		solve(dep + 1, root->right);
	}
	
}

vector<vector<int> > levelOrderBottom(TreeNode *root)
{
	vector<vector<int> > ans;

	if (NULL == root)
	{
		return ans;
	}
	
	solve(0, root);

	for (int i = deep; i >= 0; i--)
	{
		ans.push_back(ret[i]);
	}
	
	return ans;
}