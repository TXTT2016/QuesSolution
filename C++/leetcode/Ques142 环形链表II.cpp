#include <iostream>

using namespace std;


  struct ListNode {
      int val;
	  ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
  };
 
//找到环的方法，假设在一个环形的足球场上有两个运动员在跑步，速度一快一慢，那么只要时间足够长，他们两个肯定会相遇
//相遇之后指针slow从相遇点c继续走，另一个指针start从链表头开始走，相遇点即为链表入口。（快指针速度定义为慢指针的两倍）
class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		ListNode * fast = head;
		ListNode * slow = head;
		ListNode * start = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				while (start != slow)
				{
					start = start->next;
					slow = slow->next;
				}
				return slow;
			}
		}
		return nullptr;
	}
};

