#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void reOrderArray(vector<int> &array)
	{
		vector<int> vec1;
		vector<int> vec2;
		vector<int>::iterator it = array.begin();
		for (; it != array.end(); it++)
		{
			if (*it % 2 == 1)
				vec1.push_back(*it);
			else
				vec2.push_back(*it);
		}
		array.clear();
		array.insert(array.begin(), vec1.begin(), vec1.end());
		array.insert(array.end(), vec2.begin(), vec2.end());
	}
};

//int main()
//{
//	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7 };
//	Solution().reOrderArray(vec);
//	return 0;
//}