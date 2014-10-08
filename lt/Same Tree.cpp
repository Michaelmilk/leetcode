#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
	if (!(p || q))
	{
		return true;
	}
	
	if ((!p && q) || (p && !q))
	{
		return false;
	}

	if (p->val != q->val)
	{
		return false;
	}

	if (!isSameTree(p->left, q->left))
	{
		return false;
	}
	
	if (!isSameTree(p->right, q->right))
	{
		return false;
	}
	
	return true;
}

int main()
{
	// { 1, 2 }, { 1, #, 2 }
	TreeNode *p = new TreeNode(0);
	//p->left = new TreeNode(-5);

	TreeNode *q = new TreeNode(0);
	//q->left = new TreeNode(-8);
	//q->right = new TreeNode(2);

	cout << isSameTree(p, q) << endl;
	return 0;
}