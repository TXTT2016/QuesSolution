#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

//˼·������������г��ִ�������һ���������ô���ض�������������������м䣬����һ�����鼴��
//��������������������ô�Ǹ����ض��ֲ�λ�������м���Χ������ʵ�ʱ�������Ӧ����һ������

class Solution
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		sort(numbers.begin(), numbers.end());
		int len = numbers.size() / 2;
		int count = 1;
		
		for (int i = len + 1; i < numbers.size(); i++)
			if (numbers[len] == numbers[i])
				count++;
			else
				break;
		for (int i = len - 1; i > 0; i--)
			if (numbers[len] == numbers[i])
				count++;
			else
				break;
		
		if (count > len)
			return numbers[len];
		else
			return 0;
	}
};