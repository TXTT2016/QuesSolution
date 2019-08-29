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

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	

	return 0;
}