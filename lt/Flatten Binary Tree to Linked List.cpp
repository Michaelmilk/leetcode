#include <iostream>
#include <vector>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

/*accept
vector <TreeNode*> v;
void preorderTraversal(TreeNode *root)
{
	if (NULL == root)
	{
		return;
	}

	v.push_back(root);

	if (root->left)
	{
		preorderTraversal(root->left);
	}

	if (root->right)
	{
		preorderTraversal(root->right);
	}

}

void flatten(TreeNode *root)
{
	if (NULL == root)
	{
		return;
	}

	preorderTraversal(root);

	root->left = NULL;
	int size = v.size();
	TreeNode *pCur = root;
	int i = 1;

	while (i < size)
	{
		v[i]->left = NULL;
		v[i]->right = NULL;
		pCur->right = v[i];
		pCur = pCur->right;
		i++;
	}
}*/

vector <TreeNode*> v;
void preorderTraversal(TreeNode *root)
{
	if (NULL == root)
	{
		return;
	}
	v.push_back(new TreeNode(root->val));
	//v.push_back(root);
	
	if (root->left)
	{
		preorderTraversal(root->left);
	}

	if (root->right)
	{
		preorderTraversal(root->right);
	}
}

void flatten(TreeNode *root) 
{
	if (NULL == root)
	{
		return;
	}

	preorderTraversal(root);
	
	root->left = NULL;
	int size = v.size();
	TreeNode *pCur = root;
	int i = 1;

	while (i < size)
	{
		pCur->right = v[i++];
		pCur = pCur->right;
	}
}

int main()
{
	TreeNode *root = new TreeNode(1);
// 	root->left = NULL;
// 	root->right = new TreeNode(2);
// 	root->right->left = new TreeNode(3);
	root->left = new TreeNode(2);


	flatten(root);

	while (root)
	{
		cout << root->val << endl;
		root = root->right;
	}
	
	return 0;
}