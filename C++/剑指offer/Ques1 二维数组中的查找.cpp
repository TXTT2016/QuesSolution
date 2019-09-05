#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	//暴力方法 = =!不知道为啥牛客上测试这个暴力方法竟然比优化的还好，可能是测试数据的问题吧
	bool Find(int target, vector<vector<int> > array)
	{
		for (int i = 0; i < array.size(); i++)
			for (int j = 0; j < array[0].size() && j >= 0; )
			{
				if (array[i][j] < target)
					j++;
				else if (array[i][j] > target)
					break;
				else 
					return true;
			}
		return false;
	}
	//一种优化方法就是查询条件从左下或者右上开始查询
	//牛客上测试 11 -- 13ms, 内存 1300 -- 1500
	bool Find_2(int target, vector<vector<int> > array)
	{
		//从左下开始查询
		int i = array.size() - 1;
		for (int j = 0; j < array[0].size() && j >= 0 && i >= 0; )
		{
			if (array[i][j] < target)
				j++;
			else if (array[i][j] > target)
				i--;
			else
				return true;
		}
		return false;
	}

	//第三种思路，仍然每行搜索，不过每次的搜索采用二分法进行查找
	//牛客上测试 平均时间为 10ms, 内存 1500
	bool Find_3(int target, vector<vector<int> > array)
	{
		int start, end, mid;
		for (int i = 0; i < array.size(); i++)
		{
			start = 0;
			end = array[i].size() - 1;
			while (start <= end)
			{
				mid = (start + end) / 2;
				if (array[i][mid] > target)
					end = mid - 1;
				else if (array[i][mid] < target)
					start = mid + 1;
				else
					return true;
			}
		}
		return false;
	}
};
