#include <iostream>

using namespace std;

//���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
//Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,
//���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,
//���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������

/*
�ڷ���֮ǰ��������Ҫ֪��һ�����ɣ�
�� 1 �� 10�������ǵĸ�λ���У�����1������ 1 �Ρ�
�� 1 �� 100�������ǵ�ʮλ���У�����1������ 10 �Ρ�
�� 1 �� 1000�������ǵİ�λ���У�����1������ 100 �Ρ�

https://www.cnblogs.com/wangkundentisy/p/8946858.html
*/
class Solution
{
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 0)
			return 0;
		int i = 1;//��ǰΪ��λ
		int high = n;
		int cnt = 0;
		while (high != 0)
		{
			high = n / pow(10, i);//high��ʾ��ǰλ�ĸ�λ
			int temp = n / pow(10, i - 1);
			int cur = temp % 10;//cur��ʾ��iλ�ϵ�ֵ����1��ʼ����
				
			int low = n % static_cast<int>(pow(10, i - 1));//low��ʾ��ǰλ�ĵ�λ
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