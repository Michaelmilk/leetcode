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
		return ;
	}
	
	ret.push_back(root->val);
	traversal(root->left);
	traversal(root->right);
}

vector<int> preorderTraversal(TreeNode *root) 
{
	traversal(root);
	
	return ret;
}