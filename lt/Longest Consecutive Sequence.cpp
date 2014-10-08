#include <iostream>
#include <vector>
#include <map>
using namespace std;

enum OrderBy
{
	ASCENDING,
	DECENGING
};

//��Ҫ��ʱ�临�Ӷȶ��˷����������������ˡ�
//��ô�ܼ������������е�ʱ�临�Ӷȣ������۲����ǿ��Է��֣�
//4������к�3��2��1���������ʵ��һ���ġ�
//�ҹ���4֮����ʵ������3�������������ˡ�
map<int, int> mp;

int countConsecutiveNum(OrderBy orderBy, int value)
{
	int maxLen = 0;

	while (mp.find(value) != mp.end() && mp[value] == 1)
	{
		maxLen++;

		mp[value] = 0;//����Ѿ����ҹ��ˣ��Ͳ��������ˣ�

		if (orderBy == ASCENDING)
		{
			value++;
		} 
		else
		{
			value--;
		}
	}

	return maxLen;
}

int longestConsecutive(vector<int> &num)
{
	int size = num.size();

	for (int i = 0; i < size; i++)
	{
		mp[num[i]] = 1;
	}

	int maxLen = 0;

	for (int i = 0; i < size; i++)
	{
		int ascendLen = countConsecutiveNum(ASCENDING, num[i]);//���ұȵ�ǰԪ�ش����������
		int descendLen = countConsecutiveNum(DECENGING, num[i] - 1);//���ұȵ�ǰԪ��С����������

		if (ascendLen + descendLen > maxLen)
		{
			maxLen = ascendLen + descendLen;
		}
	}
	
	return maxLen;
}


int main()
{
	vector<int> v = { 100, 4, 200, 1, 3, 2 };
	cout << longestConsecutive(v) << endl;
	return 0;
}