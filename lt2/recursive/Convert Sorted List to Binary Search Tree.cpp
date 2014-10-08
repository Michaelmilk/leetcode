#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *solve(int left, int right, vector<int> &v)
{
	if (left > right)
	{
		return NULL;
	}
	if (left == right)
	{
		return new TreeNode(v[left]);
	}

	int mid = (left + right) / 2;
	TreeNode *root = new TreeNode(v[mid]);
	root->left = solve(left, mid - 1, v);
	root->right = solve(mid + 1, right, v);

	return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
	TreeNode *ans = NULL;
	if (NULL == head)
	{
		return ans;
	}

	vector<int> v;
	ListNode *pCur = head;
	while (pCur)
	{
		v.push_back(pCur->val);
		pCur = pCur->next;
	}

	return solve(0, v.size() - 1, v);
}