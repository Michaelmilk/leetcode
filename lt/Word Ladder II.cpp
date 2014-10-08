#include <iostream>
#include <string>
#include <queue>
//#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

/*
void findLaddersSolve(string start, string end, unordered_set<string> &dict, 
	vector<string> tmp, deque<string> &que, vector<vector<string> > &ans)
{
	while (!que.empty())
	{
		string elemPair = que.front();
		que.pop_front();

		if (elemPair == end)
		{
			//ans = elemPair.second;
			ans.push_back(tmp);
			return;
		}

		string s = elemPair;
		int len = s.length();
		vector<string> v;
		for (int i = 0; i < len; i++)
		{
			for (char ch = 'a'; ch <= 'z'; ch++)
			{
				if (s[i] == ch)
				{
					continue;
				}
				char t = s[i];
				s[i] = ch;
				if (dict.find(s) != dict.end())
				{
					v.push_back(s);
					dict.erase(s);
				}
				s[i] = t;//回复原来的字符串，进行下一次检索，因为与该字串相差一个字符的字串可能不只一个
			}
			int size = v.size();
			for (int k = 0; k < size; k++)
			{
				que.push_back(v[k]);
				tmp.push_back(v[k]);
				findLaddersSolve(start, end, dict, tmp, que, ans);
				tmp.pop_back();
				que.pop_back();
			}
			for (int k = 0; k < size; k++)
			{
				dict.insert(v[k]);
			}
		}
	}
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
{
	vector<vector<string> > ans;
	dict.insert(end);
	deque<string> que;
	que.push_back(start);
	vector<string> v;
	v.push_back(start);
	findLaddersSolve(start, end, dict, v, que, ans);
	return ans;
}*/

/*

vector<vector<string> > result_;
void GeneratePath(unordered_map<string, vector<string>> &prevMap, vector<string>& path, const string& word)
{
	if (prevMap[word].size() == 0)
	{
		path.push_back(word);
		vector<string> curPath = path;
		reverse(curPath.begin(), curPath.end());
		result_.push_back(curPath);
		path.pop_back();
		return;
	}
	path.push_back(word);
	for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter)
		GeneratePath(prevMap, path, *iter);
	path.pop_back();
}


vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
{
	result_.clear();
	//dict.insert(start);
	dict.insert(end);
	unordered_map<string, vector<string>> prevMap;
	for (auto iter = dict.begin(); iter != dict.end(); ++iter)
		prevMap[*iter] = vector<string>();
	vector<unordered_set<string>> candidates(2);
	int current = 0;
	int previous = 1;
	candidates[current].insert(start);
	while (true)
	{
		current = !current;
		previous = !previous;
		for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
			dict.erase(*iter);
		candidates[current].clear();

		for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
		{
			for (size_t pos = 0; pos < iter->size(); ++pos)
			{
				string word = *iter;
				for (int i = 'a'; i <= 'z'; ++i)
				{
					if (word[pos] == i)continue;
					word[pos] = i;
					if (dict.count(word) > 0)
					{
						prevMap[word].push_back(*iter);
						candidates[current].insert(word);
					}
				}
			}
		}
		if (candidates[current].size() == 0)
			return result_;
		if (candidates[current].count(end)) break;
	}
	vector<string> path;
	GeneratePath(prevMap, path, end);
	return result_;
}
*/


vector<vector<string> > ans;

void generatePath(map<string, vector<string> > &preMp, vector<string> path, string end)
{
	if (0 == preMp[end].size())
	{
		path.push_back(end);
		vector<string> cPath = path;
		reverse(cPath.begin(), cPath.end());
		ans.push_back(cPath);
		path.pop_back();
		return;
	}
	path.push_back(end);
	for (auto it = preMp[end].begin(); it != preMp[end].end(); it++)
	{
		generatePath(preMp, path, *it);
	}
	path.pop_back();//将当前递归层的end除去
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
{
	dict.insert(end);
	map<string, vector<string> > preMp;
	vector<unordered_set<string> > count(2);//因为vector<vector<string> >中的vector没有count和find函数
	int cur = 0;
	int pre = 1;

	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		preMp[*it] = vector<string>();
	}

	count[cur].insert(start);

	while (true)
	{
		cur = !cur;
		pre = !pre;

		for (auto it = count[pre].begin(); it != count[pre].end(); it++)
		{
			dict.erase(*it);
		}

		count[cur].clear();

		for (auto it = count[pre].begin(); it != count[pre].end(); it++)
		{
			int len = it->length();
			for (int j = 0; j < len; j++)
			{
				string word = *it;
				for (int ch = 'a'; ch <= 'z'; ch++)
				{
					if (word[j] == ch)
					{
						continue;
					}
					word[j] = ch;
					if (dict.count(word) > 0)
					{
						preMp[word].push_back(*it);
						count[cur].insert(word);
					}
				}
			}
		}
		if (count[cur].size() == 0)
		{
			return ans;
		}
		if (count[cur].count(end) > 0)
		{
			break;
		}
	}
	generatePath(preMp, vector<string>(), end);
	return ans;
}

int fun(int k)
{
	return k;
}
int main()
{
	/*string start = "hit";
	string end = "cog";
	unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
	vector<vector<string> > v = findLadders(start, end, dict);

	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		copy(v[i].begin(), v[i].end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}*/

	int i = 0;
	cout << fun(1) << endl;
	return 0;
}