#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}    
};

vector<TreeNode *> solve(int left, int right)
{
	vector<TreeNode *> ans;
	if (left > right)
	{
		ans.push_back(NULL);
		return ans;
	}

	for (int i = left; i <= right; i++)
	{
		vector<TreeNode *> leftTree = solve(left, i - 1);
		vector<TreeNode *> rightTree = solve(i + 1, right);
		
		for (int j = 0; j < leftTree.size(); j++)
		{
			for (int k = 0; k < rightTree.size(); k++)
			{
				TreeNode *root = new TreeNode(i);
				root->left = leftTree[j];
				root->right = rightTree[k];
				ans.push_back(root);
			}
		}
	}
	return ans;
}

vector<TreeNode *> generateTrees(int n)
{
	return solve(1, n);
}