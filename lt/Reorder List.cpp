#include <iosrteam>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

void reorderList(ListNode *head) 
{
	int size = 0;
	ListNode *pCur = head;
	vector<ListNode*> v;
	while (pCur)
	{
		size++;
		v.push_back(pCur);
		pCur = pCur->next;
	}

	if (2 >= size)
	{
		return;
	}

	int n = size % 2 == 0 ? (size / 2 - 1) : size / 2;
	for (int i = 0; i < n; i++)
	{
		v[size - 2 - i]->next = v[size - 1 - i]->next;
		v[size - 1 - i]->next = v[i + 1];
		v[i]->next = v[size - 1 - i];
	}
}