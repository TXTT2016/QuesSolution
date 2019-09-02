#include <iostream>
#include <vector>
using namespace std;



class Solution
{
public:
	//从前往后遍历遇到一个数就把这个数和所有子集生成新子集，遍历完就是所有子集
	static vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int> > res;
		res.push_back({});
		for (int i = 0; i < nums.size(); i++)
		{
			int len = res.size();
			for (int j = 0; j < len; j++)
			{
				vector<int> temp;
				for (int k = 0; k < res[j].size(); k++)
				{
					temp.push_back(res[j][k]);
				}
				temp.push_back(nums[i]);
				res.push_back(temp);
			}
			
		}
		return res;
	}
	//二进制和位运算结合，每个位都有选和不选
	static vector<vector<int>> subsets_2(vector<int>& nums)
	{
		vector<vector<int> > res;
		for (int i = 0; i < ( 1 << nums.size() ); i++)//i代表总共有多少种子集 000 - 111
		{
			vector<int> temp;
			for (int j = 0; j < nums.size(); j++)//每次放入temp中的元素顺序，000, 001, 010, 011, 100, 101, 110, 111
			{
				if ( ((i >> j) & 1) == 1)
					temp.push_back(nums[j]);
			}
			res.push_back(temp);
		}
		return res;
	}
};

int main()
{
	vector<int> vec{ 1,2,3 };

	vector<vector<int> > res = Solution::subsets_2(vec);

	return 0;
}