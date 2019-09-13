#include <iostream>

using namespace std;

//求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
//为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
//但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
//可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

/*
在分析之前，首先需要知道一个规律：
从 1 至 10，在它们的个位数中，数字1出现了 1 次。
从 1 至 100，在它们的十位数中，数字1出现了 10 次。
从 1 至 1000，在它们的百位数中，数字1出现了 100 次。

https://www.cnblogs.com/wangkundentisy/p/8946858.html
*/
class Solution
{
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 0)
			return 0;
		int i = 1;//当前为个位
		int high = n;
		int cnt = 0;
		while (high != 0)
		{
			high = n / pow(10, i);//high表示当前位的高位
			int temp = n / pow(10, i - 1);
			int cur = temp % 10;//cur表示第i位上的值，从1开始计算
				
			int low = n % static_cast<int>(pow(10, i - 1));//low表示当前位的低位
			if (cur < 1)
			{
				cnt += high * pow(10, i - 1);
			}
			else if (cur > 1)
			{
				cnt += (high + 1) * pow(10, i - 1);

			}
			else
			{
				cnt += high * pow(10, i - 1);
				cnt += (low + 1);
			}
			i++;
		}
		return cnt;
	}
};