#include<vector>
#include<algorithm>
#include<iostream>
#include<sstream>
#include"main.h"
using namespace std;

vector<int> solution::twoSum(vector<int>& nums, int target) 
{
	sort(nums.begin(), nums.end());
	int low = 0;
	int high = nums.size() - 1;
	while ((nums[low] + nums[high]) != target)
	{
		if ((nums[low] + nums[high]) > target)
			high = high - 1;
		else if ((nums[low] + nums[high]) < target)
			low = low + 1;
	}
	vector<int> ret;
	ret.push_back(low);
	ret.push_back(high);
	return ret;
}

int main()
{
	cout << "input the vector: ";
	string line;
	int number;
	getline(cin, line);
	istringstream stream(line);
	vector<int> numbers;
	while (stream >> number)
		numbers.push_back(number);
	int target;
	cout << "input the target number: ";
	cin >> target;
	solution s;
	vector<int> v = s.twoSum(numbers, target);
	cout << v[0] << " " << v[1] << endl;
	return 0;
}