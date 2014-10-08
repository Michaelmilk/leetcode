#include <iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

vector<vector<int> > ret;
vector<int> tmp;
bool isExist = false;
int cumsum;

void search(TreeNode *root, int sum)
{
	if (NULL == root)
	{
		return;
	}
	else
	{
		cumsum += root->val;
		tmp.push_back(root->val);
	}

	if (NULL == root->left && NULL == root->right)
	{
		if (cumsum == sum)
		{
			isExist = true;
			ret.push_back(tmp);
		}
	}

	search(root->left, sum);
	if (root->left)
	{
		cumsum -= (root->left)->val;
		tmp.pop_back();
	}
	search(root->right, sum);
	if (root->right)
	{
		cumsum -= (root->right)->val;
		tmp.pop_back();
	}
}



vector<vector<int> > pathSum(TreeNode *root, int sum)
{
	cumsum = 0;
	search(root, sum);

	if (isExist)
	{
		return ret;
	}
	else
	{
		return vector<vector<int> >();
	}

}