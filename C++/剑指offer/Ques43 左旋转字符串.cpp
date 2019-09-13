

//class Solution
//{
//public:
//	//左旋字符串（循环左移字符串）：左移串长length位后和原来一样，所以正真需要左移的是n % str.length()位
//	string LeftRotateString(string str, int n)
//	{
//		int len = str.length();
//		int trueSet = n % len;
//		if (n == 0 || len <= 1)//空串和单字符串左移无意义
//			return str;
//		return str.substr(n) + str.substr(0, n);
//	}
//};