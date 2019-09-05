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
	//这种做法是先将链表倒转之后再输出
	vector<int> printListFromTailToHead(ListNode* head)
	{
		ListNode * pre = nullptr;
		ListNode * ord = head;//当前节点
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
	//可以考虑用栈直接遍历一遍链表即可，不会改变链表结构
	vector<int> printListFromTailToHead_2(ListNode* head)
	{
		ListNode * ord = head;//当前节点
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

	//考虑用递归
	vector<int> printListFromTailToHead_2(ListNode* head)
	{
		ListNode * ord = head;//当前节点
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