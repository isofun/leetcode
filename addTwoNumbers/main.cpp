#include"head.h"
#include<string>
#include<stack>
#include<sstream>
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *p1 = l1, *p2 = l2, *t1 = NULL, *t2 = NULL;
	int len1 = 0, len2 = 0;
	while (p1 != NULL)
	{
		if (p1->next == NULL)
			t1 = p1;
		p1 = p1->next;
		len1 += 1;
	}
	while (p2 != NULL)
	{
		if (p2->next == NULL)
			t2 = p2;
		len2 += 1;
		p2 = p2->next;
	}
	ListNode *p = NULL, *t = NULL;
	if (len1 >= len2)
	{
		p = l1;
		t = t1;
		p1 = l1;
		p2 = l2;
	}
	else
	{
		p = l2;
		t = t2;
		p1 = l2;
		p2 = l1;
	}
	int carry = 0, num = 0;
	while (p1 != NULL)
	{
		if (p2 != NULL)
		{
			num = p1->val + p2->val + carry;
			p1->val = num % 10;
			carry = num / 10;
			p2 = p2->next;
		}
		else
		{
			num = p1->val + carry;
			p1->val = num % 10;
			carry = num / 10;
		}
		p1 = p1->next;
	}
	if (carry != 0)
	{
		t->next = new ListNode(carry);
	}
	return p;
}
int main()
{
	cout << "input the first number: ";
	string line;
	getline(cin, line);
	istringstream stream(line);
	int num = 0;
	ListNode *head1 = new ListNode(0), *head2 = new ListNode(0);
	ListNode *p1 = head1, *p2 = head2;
	while (stream >> num)
	{
		ListNode *node = new ListNode(num);
		p1->next = node;
		p1 = node;
	}
	cout << "input the second number: ";
	getline(cin, line);
	stream = istringstream(line);
	while (stream >> num)
	{
		ListNode *node = new ListNode(num);
		p2->next = node;
		p2 = node;
	}
	Solution solution;
	ListNode* ret = solution.addTwoNumbers(head1->next, head2->next);
	while(ret != NULL)
	{
		cout << ret->val << " ";
		ret = ret->next;
	}
	cout << endl;
	p1 = head1->next, p2 = head2->next;
	while (p1 != NULL)
	{
		delete head1;
		head1 = p1;
		p1 = p1->next;
	}
	delete head1;
	while (p2 != NULL)
	{
		delete head2;
		head2 = p2;
		p2 = p2->next;
	}
	delete head2;
	return 0;
}