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

//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
//���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�


//˼·������ԭ�е������ϸ��ƣ�ÿ���ڵ�ĸ����ڽڵ����
//Ȼ������һ�������Ը��ƵĽڵ��radomָ����и�ֵ
//�����������ֿ�
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
		RandomListNode* phead = pHead->next;//��������ͷ�ڵ�
		RandomListNode* H_flag = pHead;//ָ���Ƶ�����
		RandomListNode* h_flag = phead;//ԭ����
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