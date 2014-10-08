#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *re = new ListNode(0);
	ListNode *pCur = re;
	
	int c = 0;

	while (l1 || l2)
	{
		int v1 = l1 ? l1->val : 0;
		int v2 = l2 ? l2->val : 0;
		int temp =  v1 + v2 + c;
		c = 0;
		if (temp >= 10)
		{
			c = temp / 10;
			temp %= 10;
		}
		ListNode *pNode = new ListNode(temp);
		pCur->next = pNode;
		pCur = pNode;

		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}
	if (c > 0)
	{
		ListNode *pNode = new ListNode(c);
		pCur->next = pNode;
	}
	
	return re->next;
}

int main()
{
	ListNode *l1 = new ListNode(2);
	ListNode *pCur = l1;
	ListNode *pNode = new ListNode(4);
	pCur->next = pNode;
	pCur = pNode;
	pNode = new ListNode(5);
	pCur->next = pNode;

	ListNode *l2 = new ListNode(5);
	pCur = l2;
	pNode = new ListNode(6);
	pCur->next = pNode;
	pCur = pNode;
	pNode = new ListNode(5);
	pCur->next = pNode;

	pNode = addTwoNumbers(l1, l2);
	 while (pNode)
	 {
		 cout << pNode->val << endl;
		 pNode = pNode->next;
	 }
	 
	return 0;
}