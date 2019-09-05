#include <iostream>

using namespace std;

class Solution
{
public:
	//这种解法会浪费较多的内存空间
	void replaceSpace(char *str, int length)
	{
		string s = str;
		string::iterator it = s.begin();
		while (it != s.end())
		{

			if (*it == ' ')
			{
				it = s.erase(it);//erase删除当前元素后后面的元素会往前移，返回指向后一个元素往前移后的迭代器
				it = s.insert(it, '%') + 1;//insert插入到当前迭代器所指元素的前面并且返回插入元素位置的迭代器，所以要+1
				it = s.insert(it, '2') + 1;
				it = s.insert(it, '0');
			}
			it++;
		}
		s.copy(str, s.size(), 0);//这里在进行拷贝过去之后str的末尾并没有\0结束符，为什么？
		*(str + s.size()) = '\0';
	}
};

//int main()
//{
//	char s[] = "1234 3123 2312";
//	Solution().replaceSpace(s, 15);
//
//	return 0;
//}