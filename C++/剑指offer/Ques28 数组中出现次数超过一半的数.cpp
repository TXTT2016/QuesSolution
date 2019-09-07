#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

//思路是如果数组中有出现次数超过一半的数，那么它必定会出现在排序后的数组中间，遍历一遍数组即可
//而且由于数组已排序，那么那个数必定分布位于数组中间周围，所以实际遍历次数应该在一半左右

class Solution
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		sort(numbers.begin(), numbers.end());
		int len = numbers.size() / 2;
		int count = 1;
		
		for (int i = len + 1; i < numbers.size(); i++)
			if (numbers[len] == numbers[i])
				count++;
			else
				break;
		for (int i = len - 1; i > 0; i--)
			if (numbers[len] == numbers[i])
				count++;
			else
				break;
		
		if (count > len)
			return numbers[len];
		else
			return 0;
	}
};