

//class Solution
//{
//public:
//	//�����ַ�����ѭ�������ַ����������ƴ���lengthλ���ԭ��һ��������������Ҫ���Ƶ���n % str.length()λ
//	string LeftRotateString(string str, int n)
//	{
//		int len = str.length();
//		int trueSet = n % len;
//		if (n == 0 || len <= 1)//�մ��͵��ַ�������������
//			return str;
//		return str.substr(n) + str.substr(0, n);
//	}
//};