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

//冒泡排序
template <class Elem>
void bubsort(Elem A[], int len)
{
	
	int i, j;
	 for (i = 0; i < len - 1; i++)
		 for (j = 0; j < len - 1 - i; j++)
			 if (Comp<Elem>::lt(A[j], A[j + 1]))
			swap(A[j], A[j + 1]);
}

void bub_Sort(vector<int>& vec, int len)
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - i; j++)
			if (vec[j] > vec[j + 1])
				swap(vec[j], vec[j + 1]);
}

//优化方案

//1.设置一个标志位，表示在一次排序中是否有交换元素,在一次排序中如果未发生元素交换说明数组已有序
//该种优化只能针对数组开头有序而后序无序的情况
void bub_Sort_2(vector<int>& vec, int len)
{
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		flag = 0;
		for (int j = 0; j < len - i; j++)
			if (vec[j] > vec[j + 1])
			{
				swap(vec[j], vec[j + 1]);
				flag = 1;
			}
		if (flag == 0)
			return;
	}
}

//2.在最后一次进行交换位置的地方设置标记，下次只用比较到那即可。
void bub_Sort_3(vector<int>& vec, int len)
{
	int pos = 0, right = len;
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		flag = 0;
		for (int j = 0; j < right; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				swap(vec[j], vec[j + 1]);
				pos = j;
				flag = 1;
			}
		}
		if (flag == 0)
			return;
		right = pos;
	}
}

//3.定义两个方向的扫描，正向扫描到最大值，反向扫描到最小值,分别记录两次扫描最后交换的位置。
void bub_Sort_4(vector<int>& vec, int len)
{
	int pos = 0, right = len, left = 0;
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		flag = 0;
		for (int j = left; j < right; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				swap(vec[j], vec[j + 1]);
				pos = j;
				flag = 1;
			}
		}
		if (flag == 0)
			return;
		right = pos;

		for (int k = right; k > left; k--)
		{
			if (vec[k] < vec[k - 1])
			{
				swap(vec[k], vec[k - 1]);
				pos = k;
				flag = 1;
			}
		}
		if (flag == 0)
			return;
		left = pos;
	}
}

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	
	bub_Sort_4(vec, vec.size() - 1);

	return 0;
}