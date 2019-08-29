#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	//根据入栈数组判断出栈数组
	bool static IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		stack<int> st;
		vector<int>::iterator it = pushV.begin();
		vector<int>::iterator it2 = popV.begin();
		while (true)
		{
			if (it != pushV.end())
			{
				st.push(*it);
				it++;
			}
			if (it == pushV.end() && it2 == popV.end())
				return true;
			while (*it2 == st.top())
			{
				it2++;
				st.pop();
				if (st.empty())
					break;
			}
			if (it == pushV.end() && it2 != popV.end())
				return false;
		}
	}

};

int main()
{
	cout << Solution::IsPopOrder({ 1, 2, 3, 4, 5 }, { 4, 5, 3, 2, 1 });

	return 0;
}

