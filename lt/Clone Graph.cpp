#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if (NULL == node)
	{
		return NULL;
	}

	queue<UndirectedGraphNode*> que;
	map<int, UndirectedGraphNode*> mp;

	UndirectedGraphNode *pRoot = NULL;
	bool sign = true;
	//mp[node->label] = node;
	que.push(node);

	while (!que.empty())
	{
		UndirectedGraphNode *pNode = que.front();
		UndirectedGraphNode *pNewNode;
		if (mp.find(pNode->label) == mp.end())//如果mp中有，那么使用p中的节点，不然会丢失邻居信息
		{
			pNewNode = new UndirectedGraphNode(pNode->label);
		}
		else
		{
			pNewNode = mp[pNode->label];
		}
		if (sign)
		{
			mp[pNode->label] = pNewNode;
			pRoot = pNewNode;
			sign = false;
		}
		que.pop();
		//mp[pNode->label] = pNewNode;
		int size = (pNode->neighbors).size();
		for (int i = 0; i < size; i++)
		{
			int label = (pNode->neighbors[i])->label;
			UndirectedGraphNode *pNewNgebNode;
			if (mp.find(label) == mp.end())
			{
				pNewNgebNode = new UndirectedGraphNode(label);
				mp[label] = pNewNgebNode;
				que.push(pNode->neighbors[i]);
			}
			else
			{
				pNewNgebNode =mp[label];
			}

			(pNewNode->neighbors).push_back(pNewNgebNode);
			//mp[label] = pNewNgebNode;
		}
	}
	
	return pRoot;
}

int main()
{
	UndirectedGraphNode *pNewNode = new UndirectedGraphNode(-1);
	UndirectedGraphNode *pNewNode1 = new UndirectedGraphNode(1);
	UndirectedGraphNode *pNewNode2 = new UndirectedGraphNode(2);
	pNewNode->neighbors.push_back(pNewNode1);
	pNewNode1->neighbors.push_back(pNewNode2);
	pNewNode2->neighbors.push_back(pNewNode2);
	//pNewNode->neighbors.push_back(pNewNode);
	/*UndirectedGraphNode *pNewNode = new UndirectedGraphNode(0);
	pNewNode->neighbors.push_back(pNewNode);
	pNewNode->neighbors.push_back(pNewNode);*/
	UndirectedGraphNode *p = cloneGraph(pNewNode);
	cout << p->label << endl;
	return 0;
}