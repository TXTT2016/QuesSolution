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
//插入排序
void inssort(Elem A[], int len)
{
	int i, j;
	for (i = 1; i < len; i++)//因为我们要对该待排序列的每一个元素都和前面的已排好序的序列进行插入，所以我们会对序列进行遍历 
		for (j = 0; j < i; j++) //第二层循环主要用于对已排好序的序列进行扫描，和要插入进来的数据进行逐一比较，然后决定插入到哪里 
			if (!Comp<Elem>::lt(A[i], A[j])) //从前往后对已排好序的元素和待插入元素进行大小比较，然后直到找到一个元素比被插入元素大，则交换位置 
				swap(A[i], A[j]);
}

void insert_Sort(vector<int>& vec, int len)
{
	for (int i = 1; i < len; i++)
		for (int j = 0; j < i; j++)
			if (vec[i] < vec[j])
				swap(vec[i], vec[j]);
}

//插入排序的每一次排位交换所花的时间比较多，一种优化方式就是将交换直接改成赋值，先将初始位的元素保存下来
//这样不需要交换位置，交换操作全部转换成赋值即可

//再加一步的优化则是减少比较次数，用折半查法能直接找到第一个比待比较元素小的元素，然后后面的赋值步骤之前则不需要进行大小的比较
void insert_Sort_2(vector<int>& vec, int len)
{
	int flag;
	for (int i = 1; i < len; i++)
	{
		flag = vec[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (vec[j] > flag)
				vec[j + 1] = vec[j];
			else
				break;
		}
		vec[j + 1] = flag;
	}
		
}


int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	insert_Sort_2(vec, vec.size());

	return 0;
}