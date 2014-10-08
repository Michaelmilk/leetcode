#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int evalRPN(vector<string> &tokens) 
{
	int ans = 0;
	stack<int> stk;
	int size = tokens.size();

	for (int i = 0; i < size; i++)
	{
		if ("+" == tokens[i])
		{
			int op1 = stk.top();
			stk.pop();
			int op2 = stk.top();
			stk.pop();
			stk.push(op2 + op1);
		}
		else if ("-" == tokens[i])
		{
			int op1 = stk.top();
			stk.pop();
			int op2 = stk.top();
			stk.pop();
			stk.push(op2 - op1);
		}
		else if ("*" == tokens[i])
		{
			int op1 = stk.top();
			stk.pop();
			int op2 = stk.top();
			stk.pop();
			stk.push(op2 * op1);
		}
		else if ("/" == tokens[i])
		{
			int op1 = stk.top();
			stk.pop();
			int op2 = stk.top();
			stk.pop();
			stk.push(op2 / op1);
		}
		else
		{
			int op = atoi(tokens[i].c_str());
			stk.push(op);
		}
	}

	ans = stk.top();
	return ans;
}

int main()
{
// 	string s = "3";
// 	cout << (int)*(s.c_str()) << endl;
// 	cout << atoi(s.c_str()) << endl;
	//vector<string> tokens = { "2", "1", "+", "3", "*" };
	vector<string> tokens = { "4", "13", "5", "/", "+" };
	cout << evalRPN(tokens) << endl;
}