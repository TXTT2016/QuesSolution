#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<string> Permutation(string str)
	{
		vector<string> vec;
		if (str.empty())    return vec;
		permutation(vec, str, 0);
		sort(vec.begin(), vec.end());
		return vec;
	}

	void permutation(vector<string>& vec, string str, int begin)//遍历第begin位的所有可能性
	{
		if (begin == (str.size() - 1))//一次遍历的结束条件
			vec.push_back(str);
		for (int i = begin; i < str.size(); i++)
		{
			if (i != begin && str[i] == str[begin])
				continue;//有与begin位重复的字符串不进行交换，跳过

			swap(str[i], str[begin]);
			//当i==begin时，也要遍历其后面的所有字符
			//当i!=begin时，先交换，使第begin位取到不同的可能字符，再遍历后面的字符
			permutation(vec, str, begin + 1);
			swap(str[i], str[begin]);//为了防止重复的情况，还需要将begin处的元素重新换回来
		}
	}
};