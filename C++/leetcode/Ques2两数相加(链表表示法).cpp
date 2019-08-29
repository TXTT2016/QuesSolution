#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution
{
public:
	/*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		bool flag = false;
		ListNode* l3 = new ListNode(NULL);
		ListNode* temp = l3;
		int val;
		while (true)
		{
			if (l2 != NULL)
			{
				if (flag)
				{
					val = l1->val + l2->val + 1;
				}
				else
				{
					val = l1->val + l2->val;
				}

				if (val > 9)
				{
					flag = true;
					temp->val = val - 10;
				}
				else
				{
					flag = false;
					temp->val = val;
				}
				l2 = l2->next;
			}
			else
			{
				if (flag)
				{
					val = l1->val + 1;
				}
				else
				{
					val = l1->val;
				}

				if (val > 9)
				{
					flag = true;
					temp->val = val - 10;
				}
				else
				{
					flag = false;
					temp->val = val;
				}
			}
			l1 = l1->next;
			if (l1 != NULL)
			{
				temp->next = new ListNode(NULL);
				temp = temp->next;
			}
			else
				break;
		}

		while (l2 != NULL)
		{
			temp->next = new ListNode(NULL);
			temp = temp->next;
			if (flag)
			{
				val = l2->val + 1;
			}
			else
			{
				val = l2->val;
			}

			if (val > 9)
			{
				flag = true;
				temp->val = val - 10;
			}
			else
			{
				flag = false;
				temp->val = val;
			}
			l2 = l2->next;
		}

		if (flag)
		{
			temp->next = new ListNode(1);
		}
		return l3;
	}*/

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* l3 = NULL;
		ListNode** val = &l3;//

		int sum = 0;
		while (l1 != NULL || l2 != NULL || sum != 0)
		{	
			if (l1 != NULL)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			*val = new ListNode(NULL);
			(*val)->val = sum % 10;
			sum = sum / 10;
			val = &((*val)->next);
		}
		return l3;
	}


};

//int main()
//{
//	ListNode* text;
//	ListNode* l1 = new ListNode(0);
//	//l1->next = new ListNode(4);
//	//l1->next->next = new ListNode(3);
//
//	ListNode* l2 = new ListNode(5);
//	l2->next = new ListNode(6);
//	l2->next->next = new ListNode(4);
//
//	text = Solution().addTwoNumbers(l1, l2);
//
//	return 0;
//}