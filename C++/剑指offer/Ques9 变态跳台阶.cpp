#include  <iostream> 

using namespace std;

class Solution
{
	//f(0) = 1, f(1) = 1, f(2) = f(1) + f(0),
	//当n = 3 时，有三种跳的方式，第一次跳出一阶后，后面还有f(3-1)中跳法； 
	//第一次跳出二阶后，后面还有f(3-2)中跳法；
	//第一次跳出三阶后，后面还有f(3-3)中跳法
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