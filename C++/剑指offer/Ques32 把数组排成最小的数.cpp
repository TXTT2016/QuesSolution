#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	string PrintMinNumber(vector<int> numbers)
	{


		vector<string> vec(numbers.size());
		for (int i = 0; i < numbers.size(); i++)
			vec[i] = to_string(numbers[i]);
		sort(vec.begin(), vec.end(), [](string& a, string& b)
		{
			return (a + b) < (b + a);
		});
		string s;
		vector<string>::iterator it = vec.begin();
		while (it != vec.end())
			s += *it++;
		return s;
	}
};


