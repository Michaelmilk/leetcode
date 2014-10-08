#include <iostream>
#include <map>
#include <queue>
#include <list>

using namespace std;
/*TLE
class LRUCache{
private:
	int m_capacity;
	map<int, int> keyValMp;
	map<int, int> keyLRUMp;

public:
	LRUCache(int capacity) 
	{
		m_capacity = capacity;
	}

	int get(int key) 
	{
		if (keyValMp.find(key) != keyValMp.end())
		{
			keyLRUMp[key]++;
			return keyValMp[key];
		}
		return -1;
	}

	void set(int key, int value) 
	{
		if (keyValMp.find(key) == keyValMp.end())
		{
			if (0 == m_capacity)
			{
				int min = INT_MAX;
				int relKey;
				for (map<int, int>::iterator it = keyValMp.begin(); it != keyValMp.end(); it++)
				{
					if (it->second < min)
					{
						relKey = it->first;
						min = it->second;
					}
				}
				keyValMp.erase(relKey);
				keyLRUMp.erase(relKey);
				m_capacity++;

				keyValMp[key] = value;
				keyLRUMp[key] = 1; 
				
			}
			else
			{
				keyValMp[key] = value;
			}
			m_capacity--;
		}
		else if (keyValMp.find(key) != keyValMp.end())
		{
			if (keyValMp[key] != value)
			{
				keyValMp[key] = value;
				keyLRUMp[key] = 1;
			} 
			else
			{
				//keyLRUMp[key] = 1;
				keyLRUMp[key]++;
			}
			
		}	
	}
};
*/
/*
做个LRU，算法挺简单的。。。

而且好像用处也挺广的（？），用的比较广的一个cache算法

比如我cache只有4这么大，现在有很多元素1, 2, 2, 4, 2, 5, 3

cache                  income : 1

1

cache                  income : 2

2 1

cache                  income : 1

1 2

cache                  income : 4

4 1 2

cache                  income : 2

2 4 1

cache                  income : 5

5 2 4 1

cache                  income : 3

3 5 2 4

大概就这么个样子。。。

看出来了吧，新按元素使用率（？）排序，最后使用的放最前面

如果cache不满，新来的放第一个，如果满了，在cache里面就把里面那个放到第一个，如果不在就删除最后一个，然后把新元素放第一个。
*/

class LRUCache{
private:
	int m_capacity;
	struct CacheNode 
	{
		int key;
		int val;
		CacheNode(int k, int v) : key(k), val(v){}
	};
	list<CacheNode> nodeList;
	map<int, list<CacheNode>::iterator> cacheNodeMp;
	
public:
	LRUCache(int capacity)
	{
		m_capacity = capacity;
	}

	int get(int key)
	{
		if (cacheNodeMp.find(key) != cacheNodeMp.end())
		{
			auto it = cacheNodeMp[key];
			nodeList.splice(nodeList.begin(), nodeList, it);
			//cacheMap[key] = cacheList.begin();//因为使用splice迭代器it会跟着节点一起移动,节点移动到首位置的时候，相应的it也变成了list.begin()
			return cacheNodeMp[key]->val;
		}
		return -1;
	}

	void set(int key, int value)
	{
		if (cacheNodeMp.find(key) == cacheNodeMp.end())
		{
			if (nodeList.size() == m_capacity)
			{
				cacheNodeMp.erase(nodeList.back().key);
				nodeList.pop_back();
			}
			nodeList.push_front(CacheNode(key, value));
			cacheNodeMp[key] = nodeList.begin();
		}
		else
		{
			auto it = cacheNodeMp[key];
			nodeList.splice(nodeList.begin(), nodeList, it);
			//cacheMap[key] = cacheList.begin();//因为使用splice迭代器it会跟着节点一起移动,节点移动到首位置的时候，相应的it也变成了list.begin()
			nodeList.begin()->val = value;
		}
	}
};