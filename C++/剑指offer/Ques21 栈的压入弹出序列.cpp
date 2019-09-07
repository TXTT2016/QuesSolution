#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
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