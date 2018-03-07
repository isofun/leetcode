#include"head.h"

TreeNode* Solution::convertBST(TreeNode* root)
{
	stack<TreeNode*> sback;
	vector<int> sval;
	TreeNode* p = root;
	do {
		while (p != NULL)
		{
			sback.push(p);
			p = p->right;
		}
		if (!sback.empty())
		{
			p = sback.top();
			sval.push_back(p->val);
			int sum = 0;
			for (int i = 0; i < sval.size() - 1; i++)
			{
				sum += sval[i];
			}
			p->val += sum;
			sback.pop();
			p = p->left;
		}
	} while (p != NULL || !sback.empty());
}