#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
	ListNode *head = new ListNode(0);
	ListNode *pCur = head;

	int size = lists.size();
	int min = INT_MAX;
	bool flag = true;
	int num;
	while (true)
	{
		flag = true;
		min = INT_MAX;
		for (int i = 0; i < size; i++)
		{
			if (lists[i] && lists[i]->val < min)
			{
				min = lists[i]->val;
				num = i;
				flag = false;
			}
		}

		if (flag)
		{
			break;
		}

		lists[num] = lists[num]->next;
		ListNode *p = new ListNode(min);
		pCur->next = p;
		pCur = p;	
	}
	
	return head->next;
}

int main()
{
	vector<ListNode*> v;
	ListNode *head = new ListNode(0);
	ListNode *pNode = head;

	for (int i = 1; i <= 3; i++)
	{
		ListNode *tmpNode = new ListNode(i);
		pNode->next = tmpNode;
		pNode = tmpNode;
	}
	v.push_back(head->next);
 	ListNode *ret = mergeKLists(v);

	while (ret)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}
	return 0;
}