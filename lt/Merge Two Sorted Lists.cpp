#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode *head = new ListNode(0);
	ListNode *pCur = head;
	while (l1 || l2)
	{
		if (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				ListNode *tmp = new ListNode(l1->val);
				pCur->next = tmp;
				pCur = pCur->next;
				l1 = l1->next;
			}
			else
			{
				ListNode *tmp = new ListNode(l2->val);
				pCur->next = tmp;
				pCur = pCur->next;
				l2 = l2->next;
			}
		}
		else
		{
			if (l1)
			{
				ListNode *tmp = new ListNode(l1->val);
				pCur->next = tmp;
				pCur = pCur->next;
				l1 = l1->next;
			}

			if (l2)
			{
				ListNode *tmp = new ListNode(l2->val);
				pCur->next = tmp;
				pCur = pCur->next;
				l2 = l2->next;
			}
		}
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
	return 0;
}