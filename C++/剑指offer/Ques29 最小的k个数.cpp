#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。


class Solution
{
public:
	//STL自带的sort函数速度大概等于快排+三数取中+插排+筛选重复位的优化版本
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		sort(input.begin(), input.end());
		vector<int> vec;
		vector<int>::iterator it = input.begin();
		if (k > input.size())
			return vec;
		while (k--)
		{
			vec.push_back(*it);
			it++;
		}
		return vec;
	}
};