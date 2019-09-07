#include <iostream>
#include <stack>
using namespace std;

//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������

//�ⷨ��ͬʱ����һ���洢�˵�ǰ��Сֵ��stack��ÿ��ѹջ�Ƚ���Сֵջ�������Ƿ����ѹ�����Сֵ
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