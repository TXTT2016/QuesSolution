#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int val = 0;

	void merge(vector<int>&vec, int left, int mid, int right)
	{
		vector<int> temp(right - left + 1);
		vector<int>::iterator it = temp.end() - 1;
		int i = mid;
		int j = right;
		while (i >= left && j >= mid + 1)
		{
			if (vec[i] > vec[j])
			{
				val += (j - mid);
				if (val >= 1000000007)
					val %= 1000000007;
				*it = vec[i--];
				it--;
			}
			else
			{
				*it = vec[j--];
				it--;
			}
		}
		while (i >= left)
		{
			*it = vec[i--];
			it--;
		}
		while (j >= mid + 1)
		{
			*it = vec[j--];
			it--;
		}
		it = temp.begin();
		for (; it != temp.end(); it++)
			vec[left++] = *it;
	}

	void merge_sort(vector<int>& vec, int left, int right)
	{
		if (left >= right)
			return;

		int mid = (left + right) / 2;
		merge_sort(vec, left, mid);
		merge_sort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}

	int InversePairs(vector<int> data)
	{
		if (data.empty())
			return -1;
		merge_sort(data, 0, data.size() - 1);
		return val;
	}
};