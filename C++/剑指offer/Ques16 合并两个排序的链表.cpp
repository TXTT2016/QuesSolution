#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL)
	{}
};

class Solution
{
public:
	//STL容器单链表slist，简单，跳过
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* ptemp1 = pHead1;
		ListNode* ptemp2 = pHead2;
		ListNode* temp = nullptr;
		ListNode* Head = nullptr;

		if (ptemp1->val > ptemp2->val)
		{
			temp = ptemp2;
			ptemp2 = ptemp2->next;
		}
		else
		{
			temp = ptemp1;
			ptemp1 = ptemp1->next;
		}
		Head = temp;
		while (ptemp1 != nullptr && ptemp2 != nullptr)
		{
			if (ptemp1->val >= ptemp2->val)
			{
				temp->next = ptemp2;
				temp = temp->next;
				ptemp2 = ptemp2->next;
			}
			else
			{
				temp->next = ptemp1;
				temp = temp->next;
				ptemp1 = ptemp1->next;
			}
		}

		if (ptemp1 == nullptr)
			temp->next = ptemp2;

		if (ptemp2 == nullptr)
			temp->next = ptemp1;


		return Head;
	}
};