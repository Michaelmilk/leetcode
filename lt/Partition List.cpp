#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode *partition(ListNode *head, int x)
{
	ListNode *pGCur = NULL;
	ListNode *pGFirst = NULL;
	ListNode *pLCur = NULL;
	ListNode *pLFirst = NULL;
	ListNode *pCur = head;

	while (pCur)
	{
		if (pCur->val < x)
		{
			if (NULL == pLCur)//5-4-3-2-1|| 1-2-3
			{
				pLFirst = pCur;
				pLCur = pCur;
				if (pGCur)//1-2-3
				{
					pGCur->next = pLCur->next;
					pLCur->next = pGFirst;
				}
			}
			else
			{
				if (NULL == pGCur)//1-2-3
				{
					pLCur = pCur;
				}
				else//1-4-3-3
				{
					pGCur->next = pCur->next;
					pCur->next = pLCur->next;
					pLCur->next = pCur;
					pLCur = pCur;
				}
			}
			pCur = pGCur->next;
		}
		else
		{
			if (NULL == pGCur)
			{
				pGFirst = pCur;
				pGCur = pCur;
				//pCur = pCur->next;
			}
			else
			{
				pGCur = pCur;
				//pCur = pCur->next;
			}
			pCur = pCur->next;
		}
	}

	if (NULL == pLFirst)
	{
		return pGFirst;
	}
	
	return pLFirst;
}