#include <iostream>

using namespace std;;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
ListNode *deleteDuplicates(ListNode *head)
{
	if (!head)
	{
		return NULL;
	}
	
	int prevVal = head->val;
	ListNode *pPrev = head;
	ListNode *pCur = pPrev->next;

	while (pCur)
	{
		if (prevVal == pCur->val)
		{
			pCur = pCur->next;
			if (!pCur)//全部数字都相同的情况
			{
				pPrev->next = pCur;
			}
			
		}
		else
		{
			pPrev->next = pCur;
			pPrev = pCur;
			prevVal = pPrev->val;
			pCur = pCur->next;
		}
	}
	return head;
}
*/

/*
ListNode *deleteDuplicates(ListNode *head)
{
	if (!head)
	{
		return NULL;
	}

	int prevVal = head->val;
	ListNode *pPrev = head;
	ListNode *pCur = pPrev->next;

	while (pCur)
	{
		if (prevVal == pCur->val)
		{
			pCur = pCur->next;
			pPrev->next = pCur;
		}
		else
		{
			pPrev->next = pCur;
			pPrev = pCur;
			prevVal = pPrev->val;
			pCur = pCur->next;
		}
	}
	return head;
}
*/

ListNode *deleteDuplicates(ListNode *head)
{
	if (!head)
	{
		return NULL;
	}

	ListNode *p = head;
		
	while (p)
	{
		if (p->next && p->val == (p->next)->val)
		{
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
		
	}
	return head;
}

int main()
{
	return 0;
}