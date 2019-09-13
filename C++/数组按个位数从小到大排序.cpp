#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ÿ������һ������ 0 < N < 10 0000, ���0 - N֮�������������������������λ����С�������У���λ����ͬ�İ�ʵ�ʴ�С����

vector<long long> vec;//����������е�����

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

//��cmp����������дȻ�����ϵͳsort����������ܲ���
bool cmp(long long a, long long b)
{
	if (a % 10 != b % 10)
		return a % 10 < b % 10;
	return a < b;
}

//Ŀǰ�Ƕ��ҳ����������������򻨵�ʱ��Ƚ϶࣬��û�и��õİ취��
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
//	long long temp = 0;//�����һ��N
//
//	cin >> val;
//	getPrime(val);
//	temp = val;
//	
//	Sort_out(vec);
//
//	while (cin >> val)
//	{
//		if (val > temp)//����������N������һ������Ҫ�ٴ�Ѱ�Ҹ����������
//		{
//			getPrime_2(val, temp);
//			temp = val;
//		}
//		else//����ɾ�����ڵ�����
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