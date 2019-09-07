#include <iostream>
#include <stack>
using namespace std;

//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

//解法是同时定义一个存储了当前最小值的stack，每次压栈比较最小值栈顶，看是否跟换压入的最小值
class Solution
{
private:
	stack<int> st, stmin;

	void push(int val)
	{
		st.push(val);
		if (!stmin.empty())
		{
			if (val < stmin.top())
				stmin.push(val);
			else
				stmin.push(stmin.top());
		}
		else
			stmin.push(val);
	}

	void pop()
	{
		if (st.empty())
			return;
		st.pop();
		stmin.pop();
	}

	int top()
	{
		if (!st.empty())
			return st.top();
		return 0;
	}

	int min()
	{
		return stmin.top();
	}
};