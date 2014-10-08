#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode *insertionSortList(ListNode *head) 
{
	if (NULL == head)
	{
		return NULL; 
	}

	int size = 0;
	ListNode *pCur = head;
	while (pCur && pCur->next)
	{
		size++;
		if (pCur->val > pCur->next->val)
		{
			ListNode *pSt = head;
			for (int i = 0; i < size; i++)
			{
				ListNode *pTmp = pSt;
				if (pTmp->val >= pCur->next->val && pSt == head)//pTmp->val >= pCur->next->val(em:-3 2 -3)即有两个一样的最小值，由于没有插入所以pCur一直没变，所以死循环
				{
					ListNode *pBuf = pCur->next->next;
					head = pCur->next;
					pCur->next->next = pTmp;
					pCur->next = pBuf;
					break;
				}
				else if (pTmp->val < pCur->next->val && pTmp->next->val >= pCur->next->val)
				{
					ListNode *pBuf = pCur->next->next;
					pCur->next->next = pTmp->next;
					pTmp->next = pCur->next;
					pCur->next = pBuf;
					break;
				}
				pSt = pSt->next;
			}
		}
		else
		{
			pCur = pCur->next;
		}
	}

	return head;
}

int main()
{
	ListNode *head = new ListNode(2);
	ListNode *pCur = head;
	pCur->next = new ListNode(0);
	pCur = pCur->next;
	pCur->next = new ListNode(3);
	pCur = pCur->next;
	pCur->next = new ListNode(0);
	pCur = pCur->next;
	pCur->next = new ListNode(7);
	pCur = pCur->next;
	pCur->next = new ListNode(4);
	pCur = pCur->next;
	pCur->next = new ListNode(2);
	pCur = pCur->next;
	pCur->next = new ListNode(9);
	pCur = pCur->next;
	pCur = NULL;
	ListNode *p = insertionSortList(head);
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}