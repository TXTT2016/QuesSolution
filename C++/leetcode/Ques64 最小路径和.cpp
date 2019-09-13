#include<vector>
#include<iostream>

using namespace std;
//解题思路1，采用DFS对二维矩阵进行遍历

//2.动态规划，第一种动态规划是存储一个同等大小的二维矩阵，从左上到右下或者从右下到左上都行
//只不过最后最小路径的值存储的位置不一样罢了。第二种是只存储一行，第三种就是直接在原数组上进行修改即可


#include<algorithm>
//这里我们采取的是直接在原数组上修改,推荐使用的是只存储一行
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