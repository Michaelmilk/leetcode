#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode *swapPairs(ListNode *head)
{
	int size = 0;
	ListNode *pS = head;
	while (pS)
	{
		size++;
		pS = pS->next;
	}

	if (1 == size)
	{
		return head;
	}

	int count = size / 2;
	ListNode *pCur = head;
	ListNode *newHead = NULL;
	ListNode *pNext = NULL;
	ListNode *pT = NULL;

	for (int i = 0; i < count; i++)
	{
		pNext = pCur->next;
		if (pNext->next && pNext->next->next)//pNext->next偶数个的时候 && pNext->next->next奇数个的时候只想最后一个数
		{
			pCur->next = pNext->next->next;
			pT = pNext->next;
		}
		else
		{
			pCur->next = pNext->next;
			pT = pNext->next;
		}
		
		pNext->next = pCur;
		pCur = pT;
		if (0 == i)
		{
			newHead = pNext;
		}
	}
	
	return newHead;
}

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *pNode = head;

	for (int i = 1; i <= 5; i++)
	{
		ListNode *tmpNode = new ListNode(i);
		pNode->next = tmpNode;
		pNode = tmpNode;
	}

	ListNode *ret = swapPairs(head->next);

	while (ret)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}
	return 0;
}