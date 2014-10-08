#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode *root, vector<int> &buf, vector<vector<int> > &v)
{
	if (NULL == root->left && NULL == root->right)
	{
		buf.push_back(root->val);
		v.push_back(buf);
		buf.pop_back();
		return;
	}

	buf.push_back(root->val);

	if (root->left)
	{
		//buf.push_back(root->left->val);
		solve(root->left, buf, v);
		//buf.pop_back();
	}

	if (root->right)
	{
		//buf.push_back(root->right->val);
		solve(root->right, buf, v);
		//buf.pop_back();
	}

	buf.pop_back();
}

int sumNumbers(TreeNode *root)
{
	int ans = 0;
	if (NULL == root)
	{
		return ans;
	}
	
	vector<vector<int> > v;
	vector<int> buf;
	solve(root, buf, v);

	int size = v.size();
	
	for (int i = 0; i < size; i++)
	{
		int s = v[i].size();
		int tmp = 0;
		for (int j = 0; j < s; j++)
		{
			tmp = tmp * 10 + v[i][j];
		}
		ans += tmp;
	}

	return ans;
}