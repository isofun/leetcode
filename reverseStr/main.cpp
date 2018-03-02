#include"head.h"

string Solution::reverseStr(string s, int k)
{
	if (s == "")
		return "";
	string new_s = s;
	int length = s.length();
	for (int i = 0; i < length / (2 * k); i++)
	{
		for (int j = 0; j < k; j++)
		{
			new_s[i * 2 * k + j] = s[i * 2 * k + k - j - 1];
		}
	}
	if (length % (2 * k) == 0)
		return new_s;
	int end = length > (length / 2 / k * 2 * k + k) ? (length / 2 / k * 2 * k + k) : length;
	for (int i = 0; (i + length / 2 / k * 2 * k )< end; i++)
	{
		new_s[i + length / 2 / k * 2 * k] = s[end - i - 1];
	}
	return new_s;
}

int main()
{
	string s = "";
	int k = 2;
	Solution solution;
	string new_s = solution.reverseStr(s, k);
	cout << new_s << endl;
}