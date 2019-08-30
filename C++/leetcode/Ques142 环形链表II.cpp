#include <iostream>

using namespace std;


  struct ListNode {
      int val;
	  ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
  };
 
//�ҵ����ķ�����������һ�����ε��������������˶�Ա���ܲ����ٶ�һ��һ������ôֻҪʱ���㹻�������������϶�������
//����֮��ָ��slow��������c�����ߣ���һ��ָ��start������ͷ��ʼ�ߣ������㼴Ϊ������ڡ�����ָ���ٶȶ���Ϊ��ָ���������
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

