#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

bool hasCycle(ListNode *head)
{
// 	if (NULL == head)
// 	{
// 		return false;
// 	}

	// 	if (head->next == NULL && head->next == head)
	// 	{
	// 		return true;
	// 	}
	// 	
	//if (head->next->next != NULL && head->next->next == head)
		// 	{
		// 		return true;
		// 	
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}
	}

	return false;
}