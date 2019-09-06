#include <iostream>

using namespace std;

class Solution
{
	//返回斐波那契数列的第n项,题目中要求返回的是int，所以代表int能存下
	int Fibonacci(int n)
	{
		if (n <= 2 && n>0) return 1;
		int a1 = 1, a2 = 1;
		int tmp = 0;
		for (int i = 3; i <= n; i++)
		{
			tmp = a1 + a2;
			a1 = a2;
			a2 = tmp;
		}
		return tmp;
	}
};