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

TreeNode *solve(int iBeg, int iEnd, vector<int> &inorder, int pBeg, int pEnd, vector<int> &postorder)
{
	TreeNode *ans;
	if (iBeg > iEnd || pBeg > pEnd)
	{
		return NULL;
	}

	if (iBeg == iEnd)
	{
		return ans = new TreeNode(postorder[pEnd]);
	}

	ans = new TreeNode(postorder[pEnd]);
	vector<int>::iterator it = find(inorder.begin(), inorder.end(), postorder[pEnd]);
	int c = it - inorder.begin();
	c -= iBeg;//相对位置是根据iBeg来确定的

	ans->left = solve(iBeg, iBeg + c - 1, inorder, pBeg, pBeg + c - 1, postorder);
	
	ans->right = solve(iBeg + c + 1, iEnd, inorder, pBeg + c, pEnd - 1, postorder);
	return ans;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
	int size = inorder.size();
	if (0 == size)
	{
		return NULL;
	}

	return solve(0, size - 1, inorder, 0, size - 1, postorder);
}

int main()
{
	vector<int> v1 = { 1, 3, 2 };
	vector<int> v2 = { 3, 2, 1 };
	TreeNode *p = buildTree(v1, v2);
	return 0;
}