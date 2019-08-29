#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <stack>
#include <mutex>
#include <assert.h>
#define LeftChild(i) (2 * i + 1)
using namespace std;


//Ԫ�����µ����ķ���
template <class Elem>
void percDown(Elem A[], int i, int len)
{
	int child;//�ӽڵ��������
	int temp;//�洢��ǰ���ڵ�Ԫ�ص���ʱ����
	for (temp = A[i]; LeftChild(i) < len; i = child)
	{
		child = LeftChild(i);
		//���������ӽڵ�Ľϴ���
		if ((child != len - 1) && (A[child + 1] > A[child]))
			child++;
		if (A[i] < A[child])
			swap(A[i], A[child]);
		else
			break;
	}

}
//������
template <class Elem>
void heapSort(Elem A[], int len)
{
	for (int i =len / 2 - 1; i >= 0; i--) 
		percDown(A, i, len);
	for (int j = len - 1; j > 0; j--) 
	{
		swap(A[0], A[j]);
		percDown(A, 0, j);
	}
}

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	

	return 0;
}