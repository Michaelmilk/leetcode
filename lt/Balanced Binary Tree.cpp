#include <iostream>
#include <windows.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBlance = true;

int judge(TreeNode *root)
{
	if (!root)
	{
		return 0;
	}

	int leftSum = judge(root->left);
	int rightSum = judge(root->right) ;

	if (abs(leftSum - rightSum) > 1)
	{
		isBlance = false;
	}

	return max(leftSum, rightSum) + 1;
}

bool isBalanced(TreeNode *root)
{
	if (NULL == root)
	{
		return false;
	}

	judge(root);
	
	return isBlance;
}

int main()
{
	return 0;
}