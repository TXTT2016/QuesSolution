#include <iostream>

using namespace std;

class Solution
{
public:
	//���ֽⷨ���˷ѽ϶���ڴ�ռ�
	void replaceSpace(char *str, int length)
	{
		string s = str;
		string::iterator it = s.begin();
		while (it != s.end())
		{

			if (*it == ' ')
			{
				it = s.erase(it);//eraseɾ����ǰԪ�غ�����Ԫ�ػ���ǰ�ƣ�����ָ���һ��Ԫ����ǰ�ƺ�ĵ�����
				it = s.insert(it, '%') + 1;//insert���뵽��ǰ��������ָԪ�ص�ǰ�沢�ҷ��ز���Ԫ��λ�õĵ�����������Ҫ+1
				it = s.insert(it, '2') + 1;
				it = s.insert(it, '0');
			}
			it++;
		}
		s.copy(str, s.size(), 0);//�����ڽ��п�����ȥ֮��str��ĩβ��û��\0��������Ϊʲô��
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