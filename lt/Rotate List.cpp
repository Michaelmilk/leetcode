#include <iostream>
#include <vector>
#include <algorithm>
#include<windows.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
	if (0 == k)
	{
		return head;
	}
	
	int size = 0;
	ListNode *pCur = head;
	while (pCur)
	{
		size++;
		if (NULL == pCur->next)
		{
			pCur->next = head;
			break;
		}
		pCur = pCur->next;
	}

	if (0 == size)
	{
		return head;
	}
	if (1 == size)
	{
		head->next = NULL;
		return head;
	}

	int t = k > size ? size - (k % size) : size - k;
	for (int i = 0; i < t; i++)
	{
		
		head = head->next;
	}

	pCur = head;
	int sum = 0;
	while (true)
	{
		pCur = pCur->next;
		sum++;
		if (sum == size - 1)
		{
			pCur->next = NULL;
			break;
		}
	}
	
	return head;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *ret = rotateRight(head, 0);
	while (ret)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}
	cout << 8 - 4 % 3 << endl;
	return 0;
}