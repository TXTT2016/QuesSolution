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

//shell排序
template <class Elem>
void shellSort(Elem A[], int len)
{
	// 计算出最大的h值
	int h = 1;
	while (h <= len / 3) 
	{
		h = h * 3 + 1;
	}
	while (h > 0) 
	{
		for (int i = h; i < len; i += h) 
		{
			if (!Comp<Elem>::lt(A[i], A[i - h]))
			{
				int tmp = A[i];
				int j = i - h;
				while (j >= 0 && A[j] > tmp) 
				{
					A[j + h] = A[j];
					j -= h;
				}
				A[j + h] = tmp;
			}
		}
		// 计算出下一个h值
		h = (h - 1) / 3;
	}
}

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	

	return 0;
}