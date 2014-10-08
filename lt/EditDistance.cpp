#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2)
{
	int len1 = word1.length() + 1;
	int len2 = word2.length() + 1;

	vector < vector <int> > dis(len1, vector<int>(len2));
	//int distance[len1][len2];

	for (int i = 0; i < len1; i ++)
	{
		dis[0][i] = i;
	}

	for (int j = 0; j < len2; j ++)
	{
		dis[j][0] = j;
	}

	for (int i = 1; i < len1; i ++)
	{
		for (int j = 1; j < len2; j ++)
		{
			if (word1[i - 1] == word2[j - 1])
			{
				dis[i][j] = dis[i - 1][j - 1];
			}
			else
			{
				dis[i][j] = min(dis[i - 1][j - 1] + 1, min(dis[i][j-1] + 1, dis[i-1][j] + 1));
			}
		}
	}

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	return dis[len1 - 1][len2 - 1];
	
}

int main()
{
	int dis;
	string str1, str2;

	cout << "input two strings: " << endl;
	cin >> str1 >> str2;

	dis = minDistance(str1, str2);
	cout << dis << endl;
	return 0;
}