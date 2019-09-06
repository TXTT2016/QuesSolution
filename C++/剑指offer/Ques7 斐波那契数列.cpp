#include <iostream>

using namespace std;

class Solution
{
	//����쳲��������еĵ�n��,��Ŀ��Ҫ�󷵻ص���int�����Դ���int�ܴ���
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