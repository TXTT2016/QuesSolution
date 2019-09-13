#include<vector>
#include<iostream>

using namespace std;
//����˼·1������DFS�Զ�ά������б���

//2.��̬�滮����һ�ֶ�̬�滮�Ǵ洢һ��ͬ�ȴ�С�Ķ�ά���󣬴����ϵ����»��ߴ����µ����϶���
//ֻ���������С·����ֵ�洢��λ�ò�һ�����ˡ��ڶ�����ֻ�洢һ�У������־���ֱ����ԭ�����Ͻ����޸ļ���


#include<algorithm>
//�������ǲ�ȡ����ֱ����ԭ�������޸�,�Ƽ�ʹ�õ���ֻ�洢һ��
class Solution
{
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		int i = 0, j = 0;
		for (; i < grid.size(); i++)
		{
			for (j = 0; j < grid[i].size(); j++)
			{
				if (i == 0 && j != 0)
					grid[i][j] = grid[i][j] + grid[i][j - 1];
				else if (i != 0 && j == 0)
					grid[i][j] = grid[i][j] + grid[i - 1][j];
				else if (i != 0 && j != 0)
					grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[i - 1][j - 1];
	}
};