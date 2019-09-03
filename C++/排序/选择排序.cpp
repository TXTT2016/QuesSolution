#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <stack>
#include <mutex>
#include <assert.h>
using namespace std;

template <class Elem>
class Comp {
public:
	static bool lt(Elem x, Elem y)
	{
		return x > y ? true : false;
	}
};

template <class Elem>
//选择排序
void selsort(Elem A[], int len)
{
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
			if (Comp<Elem>::lt(A[i], A[j]))
				swap(A[i], A[j]);
}

void select_Sort(vector<int>& vec, int len)
{
	int minPos = 0;
	for (int i = 0; i < len - 1;)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (vec[minPos] > vec[j])
				minPos = j;
		}
		swap(vec[i], vec[minPos]);
		minPos = ++i;
	}
}

//选择排序优化方法，在每一次的选择中选出最大和最小的两个元素的位置，比原本的选择排序减少了一半循环次数。
void select_Sort_2(vector<int>& vec, int len)
{
	int minPos = 0, maxPos = 0;
	int right = len;
	for (int i = 0; i < right - 1;)
	{
		for (int j = i + 1; j < right; j++)
		{
			if (vec[minPos] > vec[j])
				minPos = j;
			if (vec[maxPos] < vec[j])
				maxPos = j;
		}
		if (maxPos != right)
			swap(vec[maxPos], vec[right]);
		if (minPos == right)
			minPos = maxPos;
		if (minPos != i)
			swap(vec[minPos], vec[i]);
		minPos = ++i;
		maxPos = --right;
	}
}

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	select_Sort_2(vec, vec.size() - 1);

	return 0;
}