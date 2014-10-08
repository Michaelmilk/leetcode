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
����LRU���㷨ͦ�򵥵ġ�����

���Һ����ô�Ҳͦ��ģ��������õıȽϹ��һ��cache�㷨

������cacheֻ��4��ô�������кܶ�Ԫ��1, 2, 2, 4, 2, 5, 3

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

��ž���ô�����ӡ�����

�������˰ɣ��°�Ԫ��ʹ���ʣ������������ʹ�õķ���ǰ��

���cache�����������ķŵ�һ����������ˣ���cache����Ͱ������Ǹ��ŵ���һ����������ھ�ɾ�����һ����Ȼ�����Ԫ�طŵ�һ����
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
			//cacheMap[key] = cacheList.begin();//��Ϊʹ��splice������it����Žڵ�һ���ƶ�,�ڵ��ƶ�����λ�õ�ʱ����Ӧ��itҲ�����list.begin()
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
			//cacheMap[key] = cacheList.begin();//��Ϊʹ��splice������it����Žڵ�һ���ƶ�,�ڵ��ƶ�����λ�õ�ʱ����Ӧ��itҲ�����list.begin()
			nodeList.begin()->val = value;
		}
	}
};