#include <iostream>
#include <vector>
#include <stack>
using namespace std;


 struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
 };

class Solution
{
public:
	//�����������Ƚ�����ת֮�������
	vector<int> printListFromTailToHead(ListNode* head)
	{
		ListNode * pre = nullptr;
		ListNode * ord = head;//��ǰ�ڵ�
		ListNode * nex = nullptr;
		vector<int> vec;

		while (ord)
		{
			nex = ord->next;
			ord->next = pre;
			pre = ord;
			ord = nex;
		}
		while (pre)
		{
			vec.push_back(pre->val);
			pre = pre->next;
		}
		return vec;
	}
	//���Կ�����ջֱ�ӱ���һ�������ɣ�����ı�����ṹ
	vector<int> printListFromTailToHead_2(ListNode* head)
	{
		ListNode * ord = head;//��ǰ�ڵ�
		stack<int> stk;

		while (ord)
		{
			stk.push(ord->val);
			ord = ord->next;
		}
		vector<int> vec;
		while (stk.top())
		{
			vec.push_back(stk.top());
			stk.pop();
		}
		return vec;
	}

	//�����õݹ�
	vector<int> printListFromTailToHead_2(ListNode* head)
	{
		ListNode * ord = head;//��ǰ�ڵ�
		vector<int> vec;
		push(head, vec);
		return vec;
	}
	
	void push(ListNode * node, vector<int>& vec)
	{
		if (node == nullptr)
			return;
		push(node->next, vec);
		vec.push_back(node->val);
	}
};