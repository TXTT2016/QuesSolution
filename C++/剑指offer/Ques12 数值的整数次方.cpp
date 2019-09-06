#include <iostream>

using namespace std;

class Solution
{
	//考虑到base可能为0的话需要加判断条件
	double Power(double base, int exponent)
	{
		double flag = base;
		if (exponent > 0)
		{
			for (int i = 1; i < exponent; i++)
				base *= flag;
		}
		else if (exponent < 0)
		{
			base = 1 / base;
			flag = 1 / flag;
			for (int i = -1; i > exponent; i--)
				base *= flag;
		}
		else
			return 1;
		return base;
	}
};