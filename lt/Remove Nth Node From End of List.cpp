#include <iostream>

using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
	ListNode *p = head;
	int len = 0;

	while (p)
	{
		len++;
		p = p->next;
	}

	/*if (1 == len)
	{
		return NULL;
	}
	*/
	int target = len - n + 1;
	
	//p = head;
	ListNode *l = new ListNode(0);
	l->next = head;
	int count = 0;
	p = l;

	while (count < target - 1)
	{
		l = l->next;
		count++;
	}

	l->next = l->next->next;
	
	return p->next;
}

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *pNode = head;
	
	for (int i = 1; i <= 2; i++)
	{
		ListNode *tmpNode = new ListNode(i);
		pNode->next = tmpNode;
		pNode = tmpNode;
	}
	ListNode *ret = removeNthFromEnd(head->next, 1);

	while (ret)
	{
		cout << ret->val << endl;
		ret = ret->next;
	}
	
	return 0;
}