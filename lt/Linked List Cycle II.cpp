#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

/*˼·������������������Ϊn��ѭ��ͷ��ͷ���֮��ľ���Ϊk��

1. ������ָ��ͬʱ����������һ������Ϊ1����һ������Ϊ2

2. ������ָ������ʱӦ�����������

i��2s1 = s2����ͬʱ���£�·�����ٶȳ����ȣ�

ii��s2 - s1 = (n - k)�ı���

�ۺ������ó���s1 = (n - k) �ı�����

3. ��һ��������������ָ������ n - k ��֮����ʱ��������ָ��ص�ͷ����λ�ã�

��Ľ�㱣���������Ľ�㣬���Ǿ���ѭ��ͷ�ľ��붼Ϊ k (��Ϊ��n���϶��ܹ��ߵ�ѭ����ʼ�㣬�������n-k��������k������������n��������ѭ����ʼ��)��

Ȼ���������Բ���Ϊ1����ͬ�ٶȱ������������Ǿͻ���ѭ��ͷ������
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