#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int FindGreatestSumOfSubArray(vector<int> array)
{
	int res = array[0]; //��¼��ǰ����������ĺ͵����ֵ
	int max1 = array[0];   //����array[i]�������������ֵ
	for (int i = 1; i < array.size(); i++)
	{
		max1 = max(max1 + array[i], array[i]);
		res = max(max1, res);
	}
	return res;
}

int main()
{
	vector<int> vec{ 2,3,4,2,6,2,5,1 };//��ʼ������
	//int val = FindGreatestSumOfSubArray(vec);

	return 0;
}