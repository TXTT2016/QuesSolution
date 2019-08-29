#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int len =  s1.size() + s2.size();
	vector<int> m(len, 0);
	
	for (int i = 0; i < s1.length(); i++)
		for (int j = 0; j < s2.length(); j++)
			m[i + j] += (s1[i] - '0') * (s2[j] - '0');

	int carry = 0;
	for (int i = m.size() - 1; i >= 0; i--)
	{
		int t = m[i] + carry;
		m[i] = t % 10;
		carry = t / 10;
	}

	while (carry != 0) 
	{
		int t = carry % 10;
		carry /= 10;
		m.insert(m.begin(), t);
	}
	s1 = "";
	for (int i = 0; i < m.size() - 1; i++) {
		s1 = s1 + to_string(m[i]);
	}

	cout << s1;

	return 0;
}

*/