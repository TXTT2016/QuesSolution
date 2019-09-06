#include <iostream>

using namespace std;

class Solution
{
	//���ǵ�base����Ϊ0�Ļ���Ҫ���ж�����
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