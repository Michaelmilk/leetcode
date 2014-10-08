#include <iostream>
#include <vector>
#include <deque>
#include <algrithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int> > ans;
	if (NULL == root)
	{
		return ans;
	}

	vector<int> buf;
	deque<TreeNode*> que;
	que.push_back(root);
	que.push_back(NULL);

	while (!que.empty() && que.front())
	{
		while (que.front() != NULL)
		{
			TreeNode *pCur = que.front();
			que.pop_front();
			buf.push_back(pCur->val);
			if (pCur->left)
			{
				que.push_back(pCur->left);
			}

			if (pCur->right)
			{
				que.push_back(pCur->right);
			}
		}
		ans.push_back(buf);
		buf.clear();
		que.pop_front();
		que.push_back(NULL);
	}

	int size = ans.size();
	for (int i = 1; i < size; i += 2)
	{
		reverse(ans[i].begin(), ans[i].end());
	}
	return ans;
}