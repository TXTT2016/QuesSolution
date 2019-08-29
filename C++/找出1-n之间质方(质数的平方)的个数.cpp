#include <iostream>
#include <vector>
#include <Algorithm>
#include <stack>
using namespace std;

int main()
{
	int n;
	int count = 0;//1-n之间质数的幂方个数
	cin >> n;
	vector<int> vec(n + 1, -1);

	for (int i = 2; i <= n; i++)
	{
		if (vec[i] != 0)
		{
			int j = i;
			while (j <= n)
			{
				vec[j] = 0;
				j *= i;
				count++;
			}
			j = i;
			while (j <= n)
			{
				if (vec[j] == 0)
				{
					j += i;
					continue;
				}
				vec[j] = 0;
				j += i;
			}
		}
	}

	//埃拉托色尼筛选法 floor向下取整 ceil向上取整
	for (int i = 2; i < floor(sqrt(n)); i++)
	{
		if (vec[i] != 0)
		{
			int j = i * i;
			while (j <= n)
			{
				vec[j] = 0;
				j += i;
			}
		}
	}

	vector<int> vec2;// 1-n之间所有的质数
	for (int i = 2; i <= n; i++)
		if (vec[i] != 0)
			vec2.push_back(i);
	for (auto it = vec2.begin(); it != vec2.end(); it++)
		cout << *it << endl;



	return 0;
}