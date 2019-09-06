#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	//无难度，跳过
	//优化想法是二分法，mid = ( start + end ) / 2, vec[start]和vec[mid]比大小，这个不难，应该随便能写出，跳过
	//如果考虑到相同元素，加条件即可
	int minNumberInRotateArray(vector<int> rotateArray)
	{
		if (rotateArray.size() == 0)
			return 0;

		int val = rotateArray[0];
		for (int i = 1; i < rotateArray.size(); i++)
			if (val > rotateArray[i])
			{
				val = rotateArray[i];
			}
		return val;
	}
};