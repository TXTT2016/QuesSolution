#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	//�����һ������һ������ôʣ�µ�n-1��̨�׵�������f(n-1)����һ��������ͬ��
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