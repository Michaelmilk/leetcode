#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

bool check(TreeNode *curNode, int left, int right)
{
	if (NULL == curNode)
	{
		return true;
	}

	return left < curNode->val && curNode->val < right &&
		check(curNode->left, left, curNode->val) &&
		check(curNode->right, curNode->val, right);
}

bool isValidBST(TreeNode *root)
{
	return check(root, INT_MIN, INT_MAX);
}