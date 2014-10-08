#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode *buildSubTree(vector<int> &inorder, int iBeg, int iEnd, vector<int> &postorder, int pBeg, int pEnd)
{
	if (iBeg > iEnd)
	{
		return NULL;
	}
	
	int root = postorder[pEnd];

	int idx;
	for (int i = iBeg; i <= iEnd; i++)
	{
		if (inorder[i] == root)
		{
			idx = i;
			break;
		}
	}
	
	int len = idx - iBeg;
	TreeNode *leftTree = buildSubTree(inorder, iBeg, len - 1, postorder, pBeg, pBeg + len - 1);//idx - 1为什么不能用len-1代替？
	TreeNode *rightTree = buildSubTree(inorder, idx + 1, iEnd, postorder, pBeg + len, pEnd - 1);//idx + 1为什么不能用len-1代替？

	TreeNode *node = new TreeNode(root);
	node->left = leftTree;
	node->right = rightTree;

	return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
	int size = inorder.size();
	if (0 == size)
	{
		return NULL;
	}
	
	TreeNode *head = buildSubTree(inorder, 0, size - 1, postorder, 0, size - 1);

	return head;
}

int main()
{
	vector<int> v1 = { 1, 2, 3, 4 };
	vector<int> v2 = { 2, 3, 4, 1 };
	TreeNode *head = buildTree(v1, v2);
	
	return 0;
}