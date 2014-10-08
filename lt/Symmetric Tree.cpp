#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

/*
bool ret = true;
vector<int> leftTree[100];
vector<int> rightTree[1000];
int deep = 0;
void solve(int deep, TreeNode *root)
{
	if (NULL == root || false == ret)
	{
		return;
	}


	if (root->left)
	{
		leftTree[deep].push_back(root->left->val);
	}

	if (root->right)
	{
		rightTree[deep].push_back(root->right->val);
	}

	solve(deep + 1, );
}


bool isSymmetric(TreeNode *root)
{
	if (NULL == root)
	{
		return ret;
	}

	leftTree[deep].push_back(root->val);
	rightTree[deep].push_back(root->val);

	solve(deep + 1, root);

	if (leftTree[deep - 1].size() == rightTree[deep - 1].size())
	{
		int size = rightTree[deep - 1].size();
		for (int i = 0, int j = size; i < size, j >= 0; i++, j--)
		{
			if (leftTree[deep - 1][i] != rightTree[deep - 1][j])
			{
				ret = false;
			}
		}
	}
	return ret;
}
*/

bool solve(TreeNode *leftTree, TreeNode *rightTree)
{
	if (NULL == leftTree && NULL == rightTree)
	{
		return true;
	}

	if (NULL == leftTree || NULL == rightTree)
	{
		return false;
	}
	
	if (leftTree->val == rightTree->val)
	{
		return solve(leftTree->left, rightTree->right) && solve(leftTree->right, rightTree->left);
	}
	else
	{
		return false;
	}

}

bool isSymmetric(TreeNode *root)
{
	if (NULL == root)
	{
		return true;
	}

	return solve(root->left, root->right);
}
