#include  <iostream> 

using namespace std;

class Solution
{
	//f(0) = 1, f(1) = 1, f(2) = f(1) + f(0),
	//��n = 3 ʱ�����������ķ�ʽ����һ������һ�׺󣬺��滹��f(3-1)�������� 
	//��һ���������׺󣬺��滹��f(3-2)��������
	//��һ���������׺󣬺��滹��f(3-3)������
	//f(3) = f(2) + f(1) + f(0)
	int jumpFloorII(int number)
	{
		if (number < 0) return 0;
		if (number <= 1) return 1;
		int j = 1;
		for (int i = 1; i < number; i++)
			j *= 2;
		return j;
	}
};