#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

/*思路分析：假设链表长度为n，循环头与头结点之间的距离为k。

1. 让两个指针同时遍历链表，一个步伐为1，另一个步伐为2

2. 这两个指针相遇时应满足的条件：

i）2s1 = s2（相同时间下，路程与速度成正比）

ii）s2 - s1 = (n - k)的倍数

综合起来得出：s1 = (n - k) 的倍数。

3. 第一次相遇是在慢的指针走了 n - k 步之后，这时，让慢的指针回到头结点的位置，

快的结点保持在相遇的结点，它们距离循环头的距离都为 k (因为走n步肯定能够走到循环起始点，快点走了n-k步，再走k步，就是走了n步，到达循环起始点)，

然后让它们以步伐为1的相同速度遍历链表，它们就会在循环头相遇。
*/
ListNode *detectCycle(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}

	slow = head;

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}