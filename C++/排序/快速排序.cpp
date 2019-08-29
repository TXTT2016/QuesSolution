#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <stack>
#include <mutex>
#include <assert.h>
using namespace std;

void quick_sort(vector<int>& vec, int left, int right)
{
	if (left >= right)
		return;
	int i = left;
	int j = right;
	int val = vec[i];
	while (i < j)
	{
		while (j > i && vec[j] >= val)
			j--;
		vec[i] = vec[j];
		while (i < j && vec[i] <= val)
			i++;
		vec[j] = vec[i];
	}
	vec[i] = val;
	quick_sort(vec, left, i);
	quick_sort(vec, i + 1, right);

}

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	quick_sort(vec, 0, vec.size() - 1);

	return 0;
}