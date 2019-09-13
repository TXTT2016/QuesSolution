#include <iostream>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

//解题思路，先将string内的单词按空格隔开顺序放入stack中，之后出栈顺序即为正常语句顺序。

//第二种思路，先将整个字符串反转，然后以空格作为区分将单个单词进行反转。

//经群友推荐，C++的istringtream用字符串构造对象默认按空格分割

class Solution
{
public:
	string ReverseSentence(string str)
	{
		stack<string> st;
		int start = 0;
		int number = 0;
		string s = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				s = str.substr(start, number);
				st.push(s);
				number = -1;
				start = i + 1;
			}
			number++;
		}
		st.push(str.substr(start, number));
		s = "";
		while (!st.empty())
		{
			s = s + st.top() + " ";
			st.pop();
		}
		s[s.length() - 1] = '\0';
		return s;
	}

	string ReverseSentence_2(string str)
	{
		reverse(str.begin(), str.end());
		string::iterator start = str.begin();
		string::iterator end = str.begin();
		while (end != str.end())
		{
			if (*end == ' ')
			{
				reverse(start, end);
				start = ++end;
			}
			end++;
		}
		reverse(start, end);
		return str;
	}

	string ReverseSentence_3(string str)
	{
		stack<string> st;
		istringstream is(str);
		string s;
		while (is >> s)
			st.push(s);
		
		s = "";
		while (!st.empty())
		{
			s = s + st.top() + " ";
			st.pop();
		}
		s[s.length() - 1] = '\0';
		return s;
	}
};

	string s = "";

	void getSequence(string s1, string s2, int len)
	{
		if (s1.empty())
			return;
		int rootIndex2 = len - 1;
		s += s2[rootIndex2];
		int rootIndex1 = 0;
		while (s1[rootIndex1] != s2[rootIndex2])
			rootIndex1++;
		string left1 = s1.substr(0, rootIndex1);
		string right1 = s1.substr(rootIndex1 + 1, len - rootIndex1 - 1);
		string left2 = s2.substr(0, rootIndex1);
		string right2 = s2.substr(rootIndex1, len - rootIndex1 - 1);

		getSequence(left1, left2, rootIndex1);
		getSequence(right1, right2, len - rootIndex1 - 1);
	}

	//int main()
	//{
	//	string s1, s2;
	//	cin >> s1 >> s2;

	//	getSequence(s1, s2, s2.length());

	//	cout << s;

	//	return 0;
	//}



