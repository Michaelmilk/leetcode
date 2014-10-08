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

void solve(int count, int sum, vector<int> &buf, vector<vector<int> > &ans, TreeNode *root)
{
	if (root->left == NULL && root->right == NULL)
	{
		if (count + root->val == sum)
		{
			buf.push_back(root->val);
			ans.push_back(buf);
			buf.pop_back();
		}
		return;
	}

	if (root->left)
	{
		buf.push_back(root->val);
		solve(count + root->val, sum, buf, ans, root->left);
		buf.pop_back();
	}


	if (root->right)
	{
		buf.push_back(root->val);
		solve(count + root->val, sum, buf, ans, root->right);
		buf.pop_back();
	}
}

vector<vector<int> > pathSum(TreeNode *root, int sum)
{
	vector<vector<int> > ans;
	if (NULL == root)
	{
		return ans;
	}

	vector<int> buf;
	solve(0, sum, buf, ans, root);
	return ans;
}