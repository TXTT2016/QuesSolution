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
			if (top + 1 < bottem && left < right)//之所以是top+1是因为从左往右的横向输出了第一行最左，从右往左横向也输出了最左，所以行数最少3行才需要输出
				for (int i = bottem - 1; i > top; i--)
					vec.push_back(matrix[bottem][i]);
			left++; right--; top++; bottem--;
		}
		return vec;
	}
};