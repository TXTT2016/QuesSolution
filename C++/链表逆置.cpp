#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
             val(x), next(NULL) {
        }
  };


class Solution {
public:
	//暴力一个一个逆置
	vector<int> printListFromTailToHead(ListNode* head) {
		ListNode * phead = head;
		ListNode * tmp = nullptr;
		vector<int> vec;

		while (phead != tmp)
		{
			while (phead->next != tmp)
				phead = phead->next;

			vec.push_back(phead->val);
			tmp = phead;
			phead = head;
		}
		return vec;
	}
	/*
	//先将整个链表逆置
	vector<int> printListFromTailToHead(ListNode* head) {
		ListNode * pre = nullptr;
		ListNode * ord = head;
		ListNode * nex = nullptr;
		vector<int> vec;

		if (head->next == nullptr)
			return;
		
		while (ord != nullptr)
		{
			nex = ord->next;
			ord->next = pre;
			pre = ord;
			ord = nex;
		}

		head = pre;

		while (pre->next != nullptr)
		{
			vec.push_back(pre->val);
			pre = pre->next;
		}

		return vec;
	}
	*/
};

//int main()
//{
//	
//
//	return 0;
//}