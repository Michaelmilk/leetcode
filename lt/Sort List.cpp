#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTotal(ListNode *left, ListNode *right)
{
	ListNode *head = new ListNode(0);
	ListNode *pCur = head;
	while (left && right)
	{
		if (left->val < right->val)
		{
			pCur->next = left;
			left = left->next;
		}
		else
		{
			pCur->next = right;
			right = right->next;
		}
		pCur = pCur->next;
	}
	pCur->next = left != NULL ? left : right;
	pCur = head;
	head = head->next;
	delete pCur;
	return head;
}

ListNode* sortSubList(ListNode *head)
{
	if (NULL == head || NULL == head->next)
	{
		return head;
	}

	ListNode *pSlw = head, *pFst = head, *preSlw = NULL;
	while (pFst != NULL && pFst->next != NULL)//find the middle element
	{
		pFst = pFst->next->next;
		preSlw = pSlw;
		pSlw = pSlw->next;
	}
	preSlw->next = NULL;
	ListNode *left = sortSubList(head);
	ListNode *right = sortSubList(pSlw);

	return mergeTotal(left, right);
}

ListNode *sortList(ListNode *head)
{
	if (NULL == head || NULL == head->next)
	{
		return head;
	}
	
	return sortSubList(head);
}

int main()
{
	ListNode *head = new ListNode(2);
	head->next = new ListNode(1);
	ListNode *p = sortList(head);

	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}