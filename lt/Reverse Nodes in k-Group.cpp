#include<iostream>
#include<string>
using namespace::std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/*ListNode *reverseKGroup(ListNode *head, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (k == 0 || k == 1)
			return head;
		int size = 0, multi = 0;
		ListNode *tmp, *preTail, *curHead, *cur, *pre, *curTail;
		preTail = NULL;
		curTail = NULL;
		curHead = NULL;
		tmp = head;
		while (tmp != 0)
		{
			size++;
			tmp = tmp->next;
		}
		multi = size / k;
		if (multi == 0)
			return head;


		cur = head;

		for (int j = 0; j < multi; j++)
		{
			pre = NULL;
			for (int i = 0; i < k; i++)
			{
				//if (cur != NULL)
				//{
					tmp = cur->next;
					cur->next = pre;
					pre = cur;
				//}
				if (i == 0)
					curTail = cur;
				if (i == (k - 1))
					curHead = cur;
				cur = tmp;
			}
			/ *			if(preTail != NULL)
			{
			preTail->next = curHead;
			}
			* /
			if (preTail == NULL)
			{
				head = curHead;
			}
			else
			{
				preTail->next = curHead;//连接多组字符串
			}
			preTail = curTail;

		}
		//curTail->next = cur;
		preTail->next = cur;//连接分组后剩余的字符串
		return head;
	}*/

	ListNode *reverseKGroup(ListNode *head, int k) {
		if (k <= 1)
		{
			return head;
		}

		int size = 0;
		ListNode *tmp = head;
		while (tmp)
		{
			size++;
			tmp = tmp->next;
		}

		int round = size / k;
		if (!round)
		{
			return head;
		}

		ListNode *cur, *curHead, *curTail, *pre, *preTail;
		cur = head;
		curHead = NULL;
		curTail = NULL;
		preTail = NULL;

		for (int i = 0; i < round; i++)
		{
			pre = NULL;
			for (int j = 0; j < k; j++)
			{
				tmp = cur->next;
				cur->next = pre;
				pre = cur;

				if (0 == j)
				{
					curTail = cur;
				}
				
				if (k - 1 == j)
				{
					curHead = cur;
				}

				cur = tmp;
			}

			if (!preTail)
			{
				head = curHead;
			}
			else
			{
				preTail->next = curHead;
			}
			preTail = curTail;
		}
		preTail->next = cur;
				
		return head;
	}
};



int main()
{
	ListNode first(1), second(2), third(3), fourth(4), fifth(5), sixth(6), seventh(7), eighth(8), *head;
	first.next = &second;
	second.next = &third;
	third.next = &fourth;
	fourth.next = &fifth;
	fifth.next = &sixth;
	sixth.next = &seventh;
	seventh.next = &eighth;
	//first.next = NULL;
	head = &first;
	Solution ss;
	head = ss.reverseKGroup(&first, 2);
	while (head != NULL)
	{
		cout << head->val;
		head = head->next;
		if (head)
		{
			cout << "->";
		}
		
	}
	cout << endl;
}