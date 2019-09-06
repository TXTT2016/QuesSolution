#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	//һ��ջ������ӣ�һ��ջ�������ӣ�����ջΪ��ʱ�����ջ��Ԫ��ȫ��ת�Ƶ�����ջ
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