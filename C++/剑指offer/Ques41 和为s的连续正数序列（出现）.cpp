#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

	vector<int> generateSequence(int mid, int numbers)
	{
		vector<int> vec;
		if (numbers % 2 == 0)
		{
			int right = mid + 1;
			int left = mid;
			vec.push_back(left);
			vec.push_back(right);
			numbers -= 2;
			while (numbers > 0)
			{
				vec.push_back(++right);
				vec.push_back(--left);
				numbers -= 2;
			}
		}
		if (numbers % 2 == 1)
		{
			int left = mid;
			int right;
			vec.push_back(left);
			left = --left;
			right = ++mid;
			numbers--;
			while (numbers > 0)
			{
				vec.push_back(left--);
				vec.push_back(right++);
				numbers -= 2;
			}
		}
		sort(vec.begin(), vec.end());
		return move(vec);
	}

	vector<vector<int> > FindContinuousSequence(int sum)
	{

		vector<vector<int> >tp;

		for (int i = 2; i < sum; i++)
		{
			int mid = sum / i;
			if (mid - i / 2 < 0) break;
			//当序列个数为奇数的时候，mid必须为整数
			//当序列个数为偶数的时候，mid必须为整数.5
			if (((i % 2 == 1) && ((sum % i) == 0)) || ((i % 2 == 0) && ((sum % i) == (i / 2))))
				tp.push_back(generateSequence(mid, i));
		}
		reverse(tp.begin(), tp.end());//题目要求序列见按照大小顺序排列
		return tp;
	}
};

//int main()
//{
//	vector<vector<int> > vec = Solution().FindContinuousSequence(9);
//
//	return 0;
//}