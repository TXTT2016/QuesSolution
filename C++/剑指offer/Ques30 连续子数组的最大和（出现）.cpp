#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		vector<int>::const_iterator it = array.cbegin();
		int sum = *it;
		int max = sum;
		it++;
		while (it != array.end())
		{
			sum = getMax(sum + *it, *it);
			it++;
			if (sum > max)
				max = sum;
		}
		return max;
	}

	int getMax(int a, int b) { return a > b ? a : b; }
};