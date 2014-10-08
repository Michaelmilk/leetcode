#include <iostream>
#include <string>

using namespace std;

const string roman[4][10] = {
	{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
	{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
	{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
	{"", "M", "MM", "MMM", "", "", "", "", "", ""}

};

string intToRoman(int num)
{
	string ret = "";

	int idx = 0;
	while (num)
	{
		ret = roman[idx][num % 10] + ret;//����Ϊret += roman[idx][num % 10];��Ϊ�µ�ֵҪ����ǰ��
		num /= 10;
		idx++;
	}
	return ret;
}

int main()
{
	cout << intToRoman(999) << endl;
	return 0;
}