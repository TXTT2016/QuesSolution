#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��


class Solution
{
public:
	//STL�Դ���sort�����ٶȴ�ŵ��ڿ���+����ȡ��+����+ɸѡ�ظ�λ���Ż��汾
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		sort(input.begin(), input.end());
		vector<int> vec;
		vector<int>::iterator it = input.begin();
		if (k > input.size())
			return vec;
		while (k--)
		{
			vec.push_back(*it);
			it++;
		}
		return vec;
	}
};