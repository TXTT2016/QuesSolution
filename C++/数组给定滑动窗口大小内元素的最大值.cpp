#include <iostream>
#include <vector>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> vec;
	int max_index = 0;
	int max = num[0];
	for (int i = 0; i < size; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			max_index = i;
		}
	}
	vec.push_back(max);
	for (int i = size; i < num.size(); i++)
	{
		if (max < num[i])
		{
			max_index = i;
			max = num[i];
			vec.push_back(max);
			continue;
		}
		if (max_index < (i - size + 1))
		{
			max = num[i];
			max_index = i;
			for (int j = i - size + 1; j <= i; j++)
			{
				if (max < num[j])
				{
					max_index = j;
					max = num[j];
				}
			}
			vec.push_back(max);
			continue;
		}
		vec.push_back(max);
	}
	return vec;
}

int main()
{
	vector<int> vec{ 2,3,4,2,6,2,5,1 };
	vec = maxInWindows(vec, 3);

	return 0;
}