#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();

	if (len1 + len2 != len3)
	{
		return false;
	}
	/*dp[i][j]��ʾs3�е�ǰi+j�������ַ���s1��ǰi���ַ���s2�е�ǰj���ַ����*/
	bool dp[1000][1000];
	dp[0][0] = true;

	for (int i = 1; i <= len1; i++)
	{
		dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];//ȷ��S3��ǰn���ַ������ĸ��ִ���s1��s2����������Ӧ������λ��ֵ��Ϊtrue
	}

	for (int j = 1; j <= len2; j++)
	{
		dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];//ȷ��S3��ǰn���ַ������ĸ��ִ���s1��s2����������Ӧ������λ��ֵ��Ϊtrue
	}

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			/*
			dp[i][j]��ʾs3�е�ǰi+j�������ַ���s1��ǰi���ַ���s2�е�ǰj���ַ���ɣ�
				dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]��
				dp[i - 1][j] == true��ʾs3�е�ǰi+j-1�������ַ���s1��ǰi-1���ַ���s2�е�ǰj���ַ����
				����s1�ĵ�i���ַ�����s1[i-1]����s3�ĵ�i + j���ַ�����s3[i + j - 1]����ȡ�
				dp[i][j - 1] && s2[i - 1] == s3[i + j - 1]��
				dp[i][j - 1] == true��ʾs3�е�ǰi+j-1�������ַ���s1��ǰi���ַ���s2�е�ǰj-1���ַ����
				����s2�ĵ�j���ַ�����s2[j-1]����s3�ĵ�i + j���ַ�����s3[i + j - 1]����ȡ�
			*/
			dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
		}
	}

	return dp[len1][len2];
}