#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

void reOrderArray(vector<int> &array) 
{
	vector<int> vec1;
	vector<int> vec2;
	vector<int>::iterator it = array.begin();
	for (; it != array.end(); it++)
	{
		if (*it % 2 == 1)
			vec1.push_back(*it);
		else
			vec2.push_back(*it);
	}
	array.clear();
	array.insert(array.begin(), vec1.begin(), vec1.end());
	array.insert(array.end(), vec2.begin(), vec2.end());
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;

	ListNode* phead1 = pHead1;
	ListNode* phead2 = pHead2;
	ListNode* head = nullptr;
	ListNode* Head = nullptr;

	if (phead1->val > phead2->val)
	{
		head = phead2;
		phead2 = phead2->next;
	}
	else
	{
		head = phead1;
		phead1 = phead1->next;
	}
	Head = head;
	while (phead1 != nullptr && phead2 != nullptr)
	{
		if (phead1->val >= phead2->val)
		{
			head->next = phead2;
			head = head->next;
			phead2 = phead2->next;
		}
		else
		{
			head->next = phead1;
			head = head->next;
			phead1 = phead1->next;
		}
	}

	if (phead1 == nullptr)
		head->next = phead2;

	if (phead2 == nullptr)
		head->next = phead1;


	return Head;
}

//int main()
//{
//	ListNode * head1;
//	ListNode * head2;
//	head1 = new ListNode(1);
//	head1->next = new ListNode(3);
//	head1->next->next = new ListNode(5);
//	head2 = new ListNode(2);
//	head2->next = new ListNode(4);
//	head2->next->next = new ListNode(6);
//	ListNode* head3 = Merge(head1, head2);
//
//	return 0;
//}