#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

vector<int> ret;

void traversal(TreeNode *root)
{
	if (NULL == root)
	{
		return;
	}

	traversal(root->left);
	traversal(root->right);
	ret.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
	traversal(root);

	return ret;
}