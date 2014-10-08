#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	
};

//TLE
//RandomListNode *copyRandomList(RandomListNode *head) 
//{
//	if (NULL == head)
//	{
//		return NULL;
//	}
//	RandomListNode *ans = new RandomListNode(0);
//	RandomListNode *pCur = head;
//	RandomListNode *pNewCur = ans;
//	while (pCur)
//	{
//		int label = pCur->label;
//		//RandomListNode *next = pCur->next;
//		pNewCur->next = new RandomListNode(label);
//		pCur = pCur->next;
//		pNewCur = pNewCur->next;
//	}
//	
//	pCur = head;
//	pNewCur = ans->next;
//	while (pCur)
//	{
//		if (pCur->random != NULL)
//		{
//			RandomListNode *pRan = pCur->random;
//			RandomListNode *pTmp = head;
//			int size = 0;
//			while (pTmp)
//			{
//				size++;
//				if (pTmp == pRan)
//				{
//					break;
//				}
//				pTmp = pTmp->next;
//			}
//
//			RandomListNode *pTmp2 = ans;
//			while (size--)
//			{
//				pTmp2 = pTmp2->next;
//			}
//			pNewCur->random = pTmp2;
//		}
//		pCur = pCur->next;
//		pNewCur = pNewCur->next;
//	}
//	
//	return ans->next;
//}


//该算法更为巧妙，不用保存原始链表的映射关系，构建新节点时，指针做如下变化，即把新节点插入到相应的旧节点后面
RandomListNode *copyRandomList(RandomListNode *head)
{
	if (NULL == head)
	{
		return NULL;
	}
	RandomListNode *p1 = head;
	RandomListNode *p2 = head->next;
	while (p1 != NULL)
	{
		p1->next = new RandomListNode(p1->label);
		p1->next->next = p2;
		p1 = p2;
		if (p2 != NULL)
		{
			p2 = p2->next;
		}
	}
	p1 = head;
	p2 = head->next;
	while (p1 != NULL)
	{
		if (p1->random != NULL)
		{
			p2->random = p1->random->next;
		}
		p1 = p1->next->next;
		if (p2->next != NULL)
		{
			p2 = p2->next->next;
		}
	}

	RandomListNode *pAns = head->next;
	p1 = head;
	p2 = head->next;
	while (p1->next->next != NULL)
	{
		p1->next = p1->next->next;
		p2->next = p2->next->next;
		p1 = p1->next;
		p2 = p2->next;
	}
	p1->next = NULL;//断开两个list的的最后相连处

	return pAns;
}
