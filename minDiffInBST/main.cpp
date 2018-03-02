#include"head.h"

int Solution::minDiffInBST(TreeNode* root)
{
	TreeNode *temp = root;
	stack<TreeNode *> s;
	vector<int> vec;
	while (true)
	{
		vec.push_back(temp->val);
		if (temp->right != NULL)
		{
			s.push(temp->right);
		}
		if (temp->left != NULL)
		{
			temp = temp->left;
		}
		else
		{
			temp = s.top();
			s.pop();
		}
		if (s.empty() && temp->left == NULL && temp->right == NULL)
		{
			vec.push_back(temp->val);
			break;
		}
	}
	sort(vec.begin(), vec.end());
	int min = INFINITY;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		min = min > (vec[i + 1] - vec[i]) ? (vec[i + 1] - vec[i]) : min;
	}
	return min;
}

int main()
{

}