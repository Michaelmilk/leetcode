#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *solve(int left, int right, vector<int> &v)
{
	if (left > right)
	{
		return NULL;
	}
	if (left == right)
	{
		return new TreeNode(v[left]);
	}

	int mid = (left + right) / 2;
	TreeNode *root = new TreeNode(v[mid]);
	root->left = solve(left, mid - 1, v);
	root->right = solve(mid + 1, right, v);

	return root;
}

TreeNode *sortedArrayToBST(vector<int> &num)
{
	TreeNode *ans = NULL;
	int size = num.size();
	if (NULL == size)
	{
		return ans;
	}


	return solve(0, size - 1, num);
}