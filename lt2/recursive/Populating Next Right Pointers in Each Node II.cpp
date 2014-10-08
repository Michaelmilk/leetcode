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

	deque<TreeLinkNode*> que;
	que.push_back(root);
	que.push_back(NULL);
	TreeLinkNode *pCur = NULL;

	while (!que.empty() && que.front())
	{
		pCur = NULL;

		while (que.front())
		{
			pCur = que.front();
			que.pop_front();
			pCur->next = que.front();
			if (pCur->left)
			{
				que.push_back(pCur->left);
			}
			if (pCur->right)
			{
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

	TreeLinkNode *tmp = root->next;
	TreeLinkNode *pCur = NULL;

	while (tmp)
	{
		if (tmp->left)
		{
			pCur = tmp->left;
			break;
		}
		else if (tmp->right)
		{
			pCur = tmp->right;
			break;
		}
		else
		{
			tmp = tmp->next;
		}
	}

	if (root->right)
	{
		root->right->next = pCur;
	}

	if (root->left)
	{
		root->left->next = root->right ? root->right : pCur;
	}

	connect(root->right);
	connect(root->left);
}