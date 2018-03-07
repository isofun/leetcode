#include"head.h"

TreeNode* Solution::sortedArrayToBST(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return NULL;
	}
	int mid = nums.size() / 2;
	int root_val = nums[mid];
	TreeNode* root = new TreeNode(root_val);
	vector<int> vec_left, vec_right;
	for (int i = 0; i < mid; i++)
	{
		vec_left.push_back(nums[i]);
	}
	for (int i = mid + 1; i < nums.size(); i++)
	{
		vec_right.push_back(nums[i]);
	}
	if (vec_left.size() > 0) 
	{
		root->left = sortedArrayToBST(vec_left);

	}
	if (vec_right.size() > 0)
	{
		root->right = sortedArrayToBST(vec_right);
	}
	return root;
}

void Solution::printTree(TreeNode* root)
{
	queue < TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* temp = q.front();
		cout <<temp->val << ' ';
		q.pop();
		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
		delete temp;
	}
	cout << endl;
}

int main()
{
	int nums[] = { 10, 3, 0, 5, 9 };
	vector<int> vec_nums(nums, nums + sizeof(nums) / sizeof(int));
	Solution solution;
	TreeNode* root = solution.sortedArrayToBST(vec_nums);
	solution.printTree(root);
	return 0;
}