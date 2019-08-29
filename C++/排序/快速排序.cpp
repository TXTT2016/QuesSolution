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
void quickSort(Elem a[], int i, int j)
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

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	quick_sort(vec, 0, vec.size() - 1);

	return 0;
}