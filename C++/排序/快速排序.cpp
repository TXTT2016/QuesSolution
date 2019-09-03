#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <stack>
#include <mutex>
#include <assert.h>
using namespace std;

//快速排序

//对快排的优化意见：
//对快排进行优化，标准值的选取，可以选要排序列的最前，最后和中间3个数排序后
//的中数作为标准值，这样可以有效降低快排的时间复杂度，但是对于有
//相同数据的快排仍然不是十分理想，所以可以在函数中加上对大量相同数据的
//处理代码，还有就是在快排分区足够小后可以使用其他排序方式而不是快排来
//提高效率
template <class Elem>
void quick_Sort(Elem a[], int i, int j)
{
	if (i >= j) return;
	int first = i, last = j, flag = a[first];

	while (first < last)
	{
		while (first < last && a[last] >= flag)//将比falg大的放右边
			--last;
		if (last > first) a[first] = a[last];
		while (first < last && a[first] <= flag)//将比falg小的放左边
			++first;
		if (first < last) a[last] = a[first];
	}
	a[first] = flag;
	quickSort(a, i, first - 1);//对左边进行快排
	quickSort(a, first + 1, j);//对右边进行快排
}

void insert_Sort(vector<int>& vec, int start, int end);

void quick_Sort(vector<int>& vec, int start, int end)
{
	if (start >= end)
		return;
	int first = start, last = end, flag = vec[start];
	while (first < last)
	{
		while (first < last && vec[last] >= flag)
			--last;
		if (last > first) vec[first] = vec[last];
		while (first < last && vec[first] <= flag)
			++first;
		if (first < last) vec[last] = vec[first];
	}
	vec[first] = flag;
	quick_Sort(vec, start, first - 1);
	quick_Sort(vec, first + 1, end);
}

//随机选取标志位
int selectRandomPoint(vector<int>& vec, int start, int end)
{
	srand((unsigned)time(NULL));
	int pivotPos = rand() % (start - end);

	swap(vec[start], vec[pivotPos]);//将标志位与最低位互换位置，方便使用一般的快排
	return pivotPos;
}

//start, mid, end三数去中间数做标志位
int selectMedianOfThree(vector<int>& vec, int start, int end)
{
	int mid = ((end - start) >> 1) + start;

	if (vec[mid] > vec[end]) swap(vec[mid], vec[end]);
	if (vec[start] > vec[end]) swap(vec[start], vec[end]);
	if (vec[start] < vec[mid]) swap(vec[start], vec[mid]);
	//此时vec[mid] < vec[start] < vec[end]
	//选取的标志位仍然是首部，方便调用常用快排算法
	return vec[start];
}

//优化方法

//1.当待排序序列的长度分割到一定大小后调用插入排序，因为对于很小和部分有序的数组，快排不如插排
//一般范围为 5 - 20
void quick_Sort_2(vector<int>& vec, int start, int end)
{
	if (start >= end)
		return;
	if (end - start + 1 < 10)
	{
		insert_Sort(vec, start, end);
		return;
	}

	int first = start, last = end, flag = selectRandomPoint(vec, start, end);
	while (first < last)
	{
		while (first < last && vec[last] >= flag)
			--last;
		if (last > first) vec[first] = vec[last];
		while (first < last && vec[first] <= flag)
			++first;
		if (first < last) vec[last] = vec[first];
	}
	vec[first] = flag;
	quick_Sort(vec, start, first - 1);
	quick_Sort(vec, first + 1, end);
}
void insert_Sort(vector<int>& vec, int start, int end)
{
	for (int i = start + 1; i <= end; i++)
		for (int j = start; j < i; j++)
			if (vec[j] > vec[i])
				swap(vec[j], vec[i]);
}

//2.当选取的标志位元素如果在数组内有多重复的话，在排序一次后将和枢轴值相同的元素放到枢轴周边即可。
//方法，可以在排序过程中将和枢轴元素值相同的元素先放在数组两端，排序一次后再放到枢轴元素周围即可

void quick_Sort_3(vector<int>& vec, int start, int end)
{
	if (start >= end)
		return;
	if (end - start + 1 < 10)
	{
		insert_Sort(vec, start, end);
		return;
	}
	int first = start, last = end, flag = selectMedianOfThree(vec, start, end);
	int rightLen = 0, leftLen = 0;//两个len分别记录左右两边所具有的和枢轴元素值相同的元素的个数
	while(first < last)
	{
		while (first < last && vec[last] >= flag)
		{
			if (vec[last] == flag)
				swap(vec[end - (rightLen++)], vec[last]);
			--last;
		}
		if (vec[last] < flag)
			vec[first] = vec[last];
		while (first < last && vec[first] <= flag)
		{
			if (vec[first] == flag)
				swap(vec[start + (leftLen++)], vec[first]);
			++first;
		}
		if (vec[first] > flag)
			vec[last] = vec[first];
	}
	vec[first] = flag;

	//将左边和右边所存放的和枢轴元素值相等的元素放到枢轴边上
	for(int i=0; i<leftLen; i++)
		swap(vec[start + i], vec[first - i - 1]);
	for(int i=0; i<rightLen; i++)
		swap(vec[end - i], vec[first + i + 1]);
	//再次快排时只需要对与枢轴值不同的两边进行排序即可。
	quick_Sort_3(vec, start, first - leftLen - 1);
	quick_Sort_3(vec, first + rightLen + 1, end);
}

//3.使用多线程对子序列进行排序

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34, 23, 54, 99, 7, 35, 56, 78, 23, 34, 44, 15, 17, 68 };
	//insert_Sort(vec, 0, vec.size() - 1);
	//quick_Sort(vec, 0, vec.size() - 1);
	//quick_Sort_2(vec, 0, vec.size() - 1);

	vector<int> vec2{ 1, 4, 6, 7, 6, 6, 7, 6, 8, 6 };
	//quick_Sort_3(vec2, 0, vec2.size() - 1);

	return 0;
}