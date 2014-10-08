#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *solve(int iBeg, int iEnd, vector<int> &inorder, int pBeg, int pEnd, vector<int> &preorder)
{
	TreeNode *ans;
	if (iBeg > iEnd || pBeg > pEnd)
	{
		return NULL;
	}

	if (iBeg == iEnd)
	{
		return ans = new TreeNode(preorder[pBeg]);
	}

	ans = new TreeNode(preorder[pBeg]);
	vector<int>::iterator it = find(inorder.begin(), inorder.end(), preorder[pBeg]);
	int c = it - inorder.begin();
	c -= iBeg;//相对位置是根据iBeg来确定的

	ans->left = solve(iBeg, iBeg + c - 1, inorder, pBeg + 1, pBeg + c, preorder);

	ans->right = solve(iBeg + c + 1, iEnd, inorder, pBeg + c + 1, pEnd, preorder);
	return ans;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
	int size = inorder.size();
	if (0 == size)
	{
		return NULL;
	}

	return solve(0, size - 1, inorder, 0, size - 1, preorder);
}

int main()
{
	vector<int> v1 = { 1, 3, 2 };
	vector<int> v2 = { 3, 2, 1 };
	TreeNode *p = buildTree(v1, v2);
	return 0;
}