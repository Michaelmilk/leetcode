#include<iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};

/*
int flag = false;
void connect(TreeLinkNode *root) {
	if (NULL == root || (!root->left && !root->right))
	{
		return;
	}

	if (root->left)
	{
		if (root->right){
			root->left->next = root->right;
		}
		else
		{
			TreeLinkNode *tmp = root->next;
			while (tmp)
			{
				if (tmp->left)
				{
					root->left->next = tmp->left;
					flag = true;
					break;
				} 
				else if (tmp->right)
				{
					root->left->next = tmp->right;
					flag = true;
					break;
				}
				else
				{
					tmp = tmp->next;
				}
			}
			if (!flag)
			{
				root->left->next = NULL;
			}
		}
	}
	
	flag = false;

	if (root->right)
	{
		TreeLinkNode *tmp = root->next;
		while (tmp)
		{
			if (tmp->left)
			{
				root->right->next = tmp->left;
				flag = true;
				break;
			}
			else if (tmp->right)
			{
				root->right->next = tmp->right;
				flag = true;
				break;
			}
			else
			{
				tmp = tmp->next;
			}
		}
		if (!flag)
		{
			root->right->next = NULL;
		}
	}
	
	//因为先连接左边的节点，当右边有节点空缺的时候会造成X->next无法便利到右边所有的节点
	if (root->right)
	{
	connect(root->right);
	}

	if (root->left)
	{
		connect(root->left);
	}

	
}*/


/*
void connect(TreeLinkNode *root)
{
	if (NULL == root || (!root->left && !root->right))
	{
		return;
	}

	TreeLinkNode *tmp = root->next;
	TreeLinkNode *p = NULL;

	while (tmp)
	{
		if (tmp->left)
		{
			p = tmp->left;
			break;
		}
		else if (tmp->right)
		{
			p = tmp->right;
			break;
		}
		tmp = tmp->next;
	}

	if (root->right)
	{
		root->right->next = p;
	}

	if (root->left)
	{
		root->left->next = root->right ? root->right : p;
	}

	//因为先连接左边的节点，当右边有节点空缺的时候会造成X->next无法便利到右边所有的节点
	if (root->right)
	{
		connect(root->right);
	}

	if (root->left)
	{
		connect(root->left);
	}
}*/

void connect(TreeLinkNode *root)
{
	if (NULL == root)
	{
		return;
	}

	queue<TreeLinkNode *> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{
		TreeLinkNode *p = q.front();
		q.pop();

		if (p != NULL)
		{
			if (p->left)
			{
				q.push(p->left);
			}
			if (p->right)
			{
				q.push(p->right);
			}
			p->next = q.front();
		} 
		else
		{
			if (q.empty())
			{
				break;
			}
			q.push(NULL);
		}
	}
}