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
TreeNode *head = NULL;

void solve(TreeNode * &root/ *±ØÐëÎª&root* /, vector<int> &num, int left, int right)
{
	if (left > right)
	{
		return;
	}
	
	int m = (left + right) / 2;
	root = new TreeNode(num[m]);
	solve(root->left, num, left, m - 1);
	solve(root->right, num, m + 1, right);
}

TreeNode *sortedArrayToBST(vector<int> &num)
{
	int size = num.size();
	if (0 != size)
	{
		solve(head, num, 0, size - 1);
	}

	return head;
}*/

TreeNode *solve(vector<int> &num, int left, int right)
{
	if (left > right)
	{
		return NULL;
	}

	int m = (left + right) / 2;
	TreeNode *root = new TreeNode(num[m]);
	root->left = solve(num, left, m - 1);
	root->right = solve(num, m + 1, right);
	return root;
}

TreeNode *sortedArrayToBST(vector<int> &num)
{
	int size = num.size();
	TreeNode *head = NULL;
	if (0 != size)
	{
		head = solve(num, 0, size - 1);
	}

	return head;
}