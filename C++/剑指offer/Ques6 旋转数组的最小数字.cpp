#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	//���Ѷȣ�����
	//�Ż��뷨�Ƕ��ַ���mid = ( start + end ) / 2, vec[start]��vec[mid]�ȴ�С��������ѣ�Ӧ�������д��������
	//������ǵ���ͬԪ�أ�����������
	int minNumberInRotateArray(vector<int> rotateArray)
	{
		if (rotateArray.size() == 0)
			return 0;

		int val = rotateArray[0];
		for (int i = 1; i < rotateArray.size(); i++)
			if (val > rotateArray[i])
			{
				val = rotateArray[i];
			}
		return val;
	}
};