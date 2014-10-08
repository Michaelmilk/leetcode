#include <iostream>
#include <deque>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


void connect(TreeLinkNode *root)
{
	if (NULL == root)
	{
		return;
	}
	TreeLinkNode *pCur = root;
	deque<TreeLinkNode*> que;
	que.push_back(pCur);
	que.push_back(NULL);

	while (!que.empty() && NULL != que.front())
	{
		pCur = NULL;
		
		while (NULL != que.front())
		{
			pCur = que.front();
			que.pop_front();
			pCur->next = que.front();
			if (pCur->left && pCur->right)
			{
				que.push_back(pCur->left);
				que.push_back(pCur->right);
			}
		}
		que.pop_front();
		que.push_back(NULL);
	}
}

//recursive
void connect(TreeLinkNode *root)
{
	if (NULL == root)
	{
		return;
	}

	if (root->left)
	{
		root->left->next = root->right;
	}

	if (root->right)
	{
		root->right->next = root->next ? root->next->left : NULL;
	}

	connect(root->left);
	connect(root->right);

}