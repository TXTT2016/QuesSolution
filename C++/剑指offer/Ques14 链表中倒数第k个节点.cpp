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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		ListNode * first = pListHead;
		ListNode * second = pListHead;
		int flag = 0;

		while (first != nullptr)
		{
			if (flag >= k)
				second = second->next;
			first = first->next;
			flag++;
		}

		return flag < k ? nullptr : second;
	}
};