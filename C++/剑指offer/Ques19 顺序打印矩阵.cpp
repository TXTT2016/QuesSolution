#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> printMatrix(vector<vector<int> > matrix)
	{
		vector<int> vec;

		if (matrix.empty())
			return vec;

		int left = 0;
		int top = 0;
		int right = matrix[0].size() - 1;
		int bottem = matrix.size() - 1;

		while (left <= right && top <= bottem)
		{
			for (int i = left; i <= right; i++)
				vec.push_back(matrix[top][i]);
			if (top < bottem)
				for (int i = top + 1; i <= bottem; i++)
					vec.push_back(matrix[i][right]);
			if (top < bottem && left < right)
				for (int i = right - 1; i >= left; i--)
					vec.push_back(matrix[bottem][i]);
			if (top + 1 < bottem && left < right)//֮������top+1����Ϊ�������ҵĺ�������˵�һ�����󣬴����������Ҳ���������������������3�в���Ҫ���
				for (int i = bottem - 1; i > top; i--)
					vec.push_back(matrix[bottem][i]);
			left++; right--; top++; bottem--;
		}
		return vec;
	}
};