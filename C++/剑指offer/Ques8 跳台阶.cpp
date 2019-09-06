#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	//假设第一次跳了一级，那么剩下的n-1个台阶的跳法是f(n-1)，第一次条两级同理
	int jumpFloor(int number)
	{
		if (number <= 2) return number;
		int a1 = 1, a2 = 2;
		int tmp = 0;
		for (int i = 3; i < number; i++)
		{
			tmp = a1 + a2;
			a1 = a2;
			a2 = tmp;
		}
		return tmp;
	}
};