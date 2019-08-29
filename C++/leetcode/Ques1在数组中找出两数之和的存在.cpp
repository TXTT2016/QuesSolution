#include "iostream"
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (j == i)
					continue;
				if (nums[i] + nums[j] == target)
					return {i, j};
			}
		}

		return {};
	}
};

//int main()
//{
//	Solution s;
//	vector<int> vec = {0, 4, 3, 0};
//
//	vec = s.twoSum(vec, 0);
//
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec[i];
//	}
//
//	system("pause");
//
//	return 0;
//}