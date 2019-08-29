#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int FindGreatestSumOfSubArray(vector<int> array)
{
	int res = array[0]; //记录当前所有子数组的和的最大值
	int max1 = array[0];   //包含array[i]的连续数组最大值
	for (int i = 1; i < array.size(); i++)
	{
		max1 = max(max1 + array[i], array[i]);
		res = max(max1, res);
	}
	return res;
}

int main()
{
	vector<int> vec{ 2,3,4,2,6,2,5,1 };//初始化序列
	//int val = FindGreatestSumOfSubArray(vec);

	return 0;
}