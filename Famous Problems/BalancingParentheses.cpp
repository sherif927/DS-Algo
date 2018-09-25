#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool IsMatching(char c1,char c2)
{
	return (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']') || (c1 == '(' && c2 == ')');
}

bool IsBalancedExp(string exp){

	stack<char> stack;

	for(int i = 0; i < exp.size(); i++)
	{
		if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
		{
			stack.push(exp[i]);
		}
		else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if(!stack.empty() && IsMatching(stack.top(), exp[i]))
			{
				stack.pop();
			}
			else
			{
				return false;
			}
		}
	} return (stack.empty());
}

int main()
{
	string exp;
	cin >> exp;
	cout<<IsBalancedExp(exp)<<endl;
	system("pause");
}

