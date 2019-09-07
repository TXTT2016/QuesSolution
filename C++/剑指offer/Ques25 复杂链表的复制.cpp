#include <iostream>

using namespace std;

struct RandomListNode
{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL)
	{}
};

//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
//返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）


//思路是先在原有的链表上复制，每个节点的复制在节点后面
//然后再用一个函数对复制的节点的radom指针进行赋值
//最后将两个链表分开
class Solution
{
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (!pHead) return NULL;
		cloneList(pHead);
		rePoint(pHead);
		return clone(pHead);
	}

	RandomListNode* clone(RandomListNode* pHead)
	{
		RandomListNode* phead = pHead->next;//复制链表头节点
		RandomListNode* H_flag = pHead;//指向复制的链表
		RandomListNode* h_flag = phead;//原链表
		int val = 0;
		while (h_flag->next != NULL)
		{
			if (val % 2 == 0)
			{
				H_flag->next = h_flag->next;
				H_flag = H_flag->next;
				val++;
			}
			else
			{
				h_flag->next = H_flag->next;
				h_flag = h_flag->next;
				val++;
			}
		}
		H_flag->next = nullptr;
		return phead;
	}

	void rePoint(RandomListNode *pHead)
	{
		int val = 0;
		RandomListNode * flag = pHead;
		while (flag != NULL)
		{
			if (val % 2 == 0 && flag->random != nullptr)
				flag->next->random = flag->random->next;
			val++;
			flag = flag->next;
		}
	}

	void cloneList(RandomListNode *pHead)
	{
		RandomListNode * flag = pHead;
		RandomListNode * temp;
		while (flag != NULL)
		{
			temp = new RandomListNode(flag->label);
			temp->next = flag->next;
			flag->next = temp;
			flag = temp->next;
		}
	}

};