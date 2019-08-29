#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findMax(vector<int> num)
{
	if (num.size() == 0)
		return num;
	vector<int> res(num.size());
	int i = 0;
	stack<int> s;
	while (i < num.size())
	{
		if (s.empty() || num[s.top()] >= num[i])
		{
			s.push(i++);
		}
		else
		{
			res[s.top()] = num[i];
			s.pop();
		}
	}
	while (!s.empty())
	{
		res[s.top()] = INT_MAX;
		s.pop();
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	return res;
}

int main()
{
	vector<int> vec{ 2,3,4,2,6,2,5,1 };
	vec = findMax(vec);
	return 0;
}