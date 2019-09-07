#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<string> Permutation(string str)
	{
		vector<string> vec;
		if (str.empty())    return vec;
		permutation(vec, str, 0);
		sort(vec.begin(), vec.end());
		return vec;
	}

	void permutation(vector<string>& vec, string str, int begin)//������beginλ�����п�����
	{
		if (begin == (str.size() - 1))//һ�α����Ľ�������
			vec.push_back(str);
		for (int i = begin; i < str.size(); i++)
		{
			if (i != begin && str[i] == str[begin])
				continue;//����beginλ�ظ����ַ��������н���������

			swap(str[i], str[begin]);
			//��i==beginʱ��ҲҪ���������������ַ�
			//��i!=beginʱ���Ƚ�����ʹ��beginλȡ����ͬ�Ŀ����ַ����ٱ���������ַ�
			permutation(vec, str, begin + 1);
			swap(str[i], str[begin]);//Ϊ�˷�ֹ�ظ������������Ҫ��begin����Ԫ�����»�����
		}
	}
};