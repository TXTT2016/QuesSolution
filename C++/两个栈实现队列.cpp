#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Solution
{
public:
	void push(T node)
	{
		stack1.push(node);
	}

	T pop()
	{
		T tmp;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				tmp = stack1.top();
				stack2.push(tmp);
				stack1.pop();
			}
		}
		tmp = stack2.top();
		stack2.pop();
		return tmp;
	}

private:
	stack<T> stack1;
	stack<T> stack2;
};

//int main()
//{
//	return 0;
//}