#include"head.h"

int get_val(char c)
{
	int val = 0;
	switch (c)
	{
	case '(': val = 1; break;
	case ')': val = 2; break;
	case '[': val = 3; break;
	case ']': val = 4; break;
	case '{': val = 5; break;
	case '}': val = 6;
	}
	return val;
}

bool Solution::isValid(string s) 
{
	stack<int> sta;
	for (int i = 0; i < s.length(); i++)
	{
		int val = get_val(s[i]);
		if (val % 2 != 0)
		{
			sta.push(val);
		}
		else 
		{
			if (sta.empty())
			{
				return false;
			}
			int top = sta.top();
			if (top == (val - 1))
			{
				sta.pop();
			}
			else
			{
				return false;
			}
		}
	}
	if (sta.empty())
	{
		return true;
	}
	return false;
}

int main()
{
	Solution solution;
	string s = "(])[{}";
	cout << solution.isValid(s) << endl;
	return 0;
}