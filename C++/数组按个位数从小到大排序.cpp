#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//每行输入一个数字 0 < N < 10 0000, 输出0 - N之间的所有质数，并且质数按个位数从小到大排列，个位数相同的按实际大小排列

vector<long long> vec;//用来存放所有的质数

void getPrime(long long val)
{
	if (val < 2) return;
	if (val == 2)
	{
		vec.push_back(2);
		return;
	}
	for (int i = 2; i < val; i++)
	{
		int flag = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			vec.push_back(i);
			flag = true;
		}
	}
}

void getPrime_2(long long val, long long temp)
{
	for (int i = temp; i < val; i++)
	{
		int flag = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			vec.push_back(i);
			flag = true;
		}
	}
}

//对cmp函数进行重写然后调用系统sort函数，结果很不错。
bool cmp(long long a, long long b)
{
	if (a % 10 != b % 10)
		return a % 10 < b % 10;
	return a < b;
}

//目前是对找出来的质数进行排序花的时间比较多，有没有更好的办法？
void Sort_out(vector<long long>& val)
{
	sort(val.begin(), val.end(), cmp);
	vector<long long>::iterator it = val.begin();
	while (it != val.end())
	{
		cout << *it << endl;
		it++;
	}

	/*vector<vector<long long> > tmp = { {},{},{},{},{},{},{},{},{} };

	vector<long long>::iterator it = val.begin();

	while(it != val.end())
	{
		switch ((*it % 10))
		{
			case 1:
				tmp[0].push_back(*it);
				break;
			case 2:
				tmp[1].push_back(*it);
				break;
			case 3:
				tmp[2].push_back(*it);
				break;
			case 4:
				tmp[3].push_back(*it);
				break;
			case 5:
				tmp[4].push_back(*it);
				break;
			case 6:
				tmp[5].push_back(*it);
				break;
			case 7:
				tmp[6].push_back(*it);
				break;
			case 8:
				tmp[7].push_back(*it);
				break;
			case 9:
				tmp[8].push_back(*it);
				break;
		}
		it++;
	}

	vector<long long>::iterator head;
	for (int i = 0; i < 9; i++)
	{
		head = tmp[i].begin();
		while (head != tmp[i].end())
		{
			cout << *head << endl;
			head++;
		}
	}*/

	
}




//int main()
//{
//	long long val;
//	long long temp = 0;//存放上一个N
//
//	cin >> val;
//	getPrime(val);
//	temp = val;
//	
//	Sort_out(vec);
//
//	while (cin >> val)
//	{
//		if (val > temp)//如果新输入的N大于上一个则需要再次寻找更多的质数。
//		{
//			getPrime_2(val, temp);
//			temp = val;
//		}
//		else//否则删除多于的质数
//		{
//			while (vec.back() > val)
//				vec.pop_back();
//			temp = val;
//		}
//		Sort_out(vec);
//	}
//
//	return 0;
//}