#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	//一个栈用来入队，一个栈用来出队，出队栈为空时将入队栈的元素全部转移到出对栈
	void push(int val)
	{
		in.push(val);
	}
	int pop()
	{
		int tmp;
		if (out.empty())
		{
			while (!in.empty())
			{
				out.push(in.top());
				in.pop();
			}
		}
		tmp = out.top();
		out.pop();
		return tmp;
	}
private:
	stack<int> in;
	stack<int> out;
};