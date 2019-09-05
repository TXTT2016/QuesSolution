#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	//�������� = =!��֪��Ϊɶţ���ϲ����������������Ȼ���Ż��Ļ��ã������ǲ������ݵ������
	bool Find(int target, vector<vector<int> > array)
	{
		for (int i = 0; i < array.size(); i++)
			for (int j = 0; j < array[0].size() && j >= 0; )
			{
				if (array[i][j] < target)
					j++;
				else if (array[i][j] > target)
					break;
				else 
					return true;
			}
		return false;
	}
	//һ���Ż��������ǲ�ѯ���������»������Ͽ�ʼ��ѯ
	//ţ���ϲ��� 11 -- 13ms, �ڴ� 1300 -- 1500
	bool Find_2(int target, vector<vector<int> > array)
	{
		//�����¿�ʼ��ѯ
		int i = array.size() - 1;
		for (int j = 0; j < array[0].size() && j >= 0 && i >= 0; )
		{
			if (array[i][j] < target)
				j++;
			else if (array[i][j] > target)
				i--;
			else
				return true;
		}
		return false;
	}

	//������˼·����Ȼÿ������������ÿ�ε��������ö��ַ����в���
	//ţ���ϲ��� ƽ��ʱ��Ϊ 10ms, �ڴ� 1500
	bool Find_3(int target, vector<vector<int> > array)
	{
		int start, end, mid;
		for (int i = 0; i < array.size(); i++)
		{
			start = 0;
			end = array[i].size() - 1;
			while (start <= end)
			{
				mid = (start + end) / 2;
				if (array[i][mid] > target)
					end = mid - 1;
				else if (array[i][mid] < target)
					start = mid + 1;
				else
					return true;
			}
		}
		return false;
	}
};
