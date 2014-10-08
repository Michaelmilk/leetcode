#include <iostream>
#include <windows.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root) 
{
	if (NULL == root)
	{
		return 0;
	}

	int leftSum = maxDepth(root->left);
	int rightSum = maxDepth(root->right);

	return max(leftSum, rightSum) + 1;
}

int main()
{
	return 0;
}