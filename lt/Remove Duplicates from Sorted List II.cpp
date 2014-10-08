#include <iostream>

using namespace std;;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
	ListNode *pCur = head;
	head = new ListNode(0);
	ListNode *pPrev = head;

	int flag = false;

	while (pCur)
	{
		if (pCur->next && pCur->val == pCur->next->val)
		{
			pCur = pCur->next;
			flag = true;
		}
		else
		{
			if (!flag)
			{
				pPrev->next = pCur;
				pPrev = pPrev->next;
				if (pCur)
				{
					pCur = pCur->next;
				}
			}
			else
			{
				flag = false;
				pCur = pCur->next;
				if (!pCur)
				{
					pPrev->next = pCur;
				}

			}

		}

	}

	return head->next;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *pRet = deleteDuplicates(head);

	while (pRet)
	{
		cout << pRet->val << endl;
		pRet = pRet->next;
	}
	
}