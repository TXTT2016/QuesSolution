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
	ListNode* ReverseList(ListNode* pHead)
	{
		ListNode * left = nullptr;
		ListNode * mid = pHead;
		ListNode * right = nullptr;

		while (mid != nullptr)
		{
			right = mid->next;
			mid->next = left;
			left = mid;
			mid = right;
		}

		return left;
	}
};