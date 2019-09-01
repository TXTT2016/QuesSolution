#include <iostream>
#include <vector>
using namespace std;

//普遍解决方法都是用的深度优先搜索
class Solution
{
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (dfsSearch(board, word, 0, i, j))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool dfsSearch(vector<vector<char> >& visited, string& word, int flag, int x, int y)
	{
		if (flag >= word.size())
			return true;
		if (x < 0 || x >= visited.size() || y < 0 || y >= visited[0].size() || visited[x][y] != word[flag]) return false;
		char source = visited[x][y];
		visited[x][y] = '\0';
		bool result = dfsSearch(visited, word, flag + 1, x - 1, y) || dfsSearch(visited, word, flag + 1, x + 1, y)
			|| dfsSearch(visited, word, flag + 1, x, y - 1) || dfsSearch(visited, word, flag + 1, x, y + 1);
		visited[x][y] = source;//出错点可能有时会在访问过后还原或者访问过后将其置为访问状态这，一开始是参考+256，但是好像不行（为什么？），所以试试置0，将原数据保存起来
		return result;
	}
};

int main()
{
	return 0;
}