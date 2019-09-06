#include <iostream>

using namespace std;

class Solution
{
	int  NumberOf1(int n)
	{
		int cnt = 0;
		while (n != 0)
		{
			n = n & (n - 1);
			cnt++;
		}
		return cnt;
	}
};