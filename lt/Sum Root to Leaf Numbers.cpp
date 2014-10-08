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
int sum = 0;

void traversal(TreeNode *root)
{
	if (NULL == root)
	{
		return;
	}

	if (!root->left && !root->right)
	{
		sum *= 10;
		sum += root->val;

		ret.push_back(sum);

		return;
	}

	sum *= 10;
	sum += root->val;
	
	traversal(root->left);
	if (root->left)//左边为空的时候，不应该除以10
	{
		sum /= 10;
	}

	traversal(root->right);
	if (root->right)//右边为空的时候，不应该除以10
	{
		sum /= 10;
	}
}

int sumNumbers(TreeNode *root)
{
	traversal(root);

	int size = ret.size();
	int ans = 0;

	for (int i = 0; i < size; i++)
	{
		ans += ret[i];
	}
	
	return ans;
}

int main()
{
	TreeNode *p = new TreeNode(4);
	p->left = new TreeNode(9);
	p->right = new TreeNode(0);
	p->left->right = new TreeNode(1);

	cout << sumNumbers(p) << endl;
}