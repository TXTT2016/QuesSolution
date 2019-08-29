#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>& vec, int left, int mid, int right)
{// [left, mid] [mid+1, right]
	vector<int> temp(right-left+1);
	vector<int>::iterator it = temp.begin();
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (vec[i] < vec[j])
		{
			*it = vec[i];
			i++;
			it++;
		}
		else
		{
			*it = vec[j];
			j++;
			it++;
		}
	}
	while (i <= mid)
	{
		*it = vec[i++];
		it++;
	}
	while (j <= right)
	{
		*it = vec[j++];
		it++;
	}
	it = temp.begin();
	for (; it != temp.end(); it++)
		vec[left++] = *it;
	//vec.insert(vec.begin(), temp.begin(), temp.end());
}


void merge_sort(vector<int>& vec, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	merge_sort(vec, left, mid);
	merge_sort(vec, mid + 1, right);
	merge(vec, left, mid, right);
}




int main()
{
	int a[] = { 23, 56, 45, 87, 22, 12, 56 };
	vector<int> vec;

	for (int i = 0; i < 7; i++)
		vec.push_back(a[i]);

	for (int i = 0; i < 7; i++)
		cout << vec[i] << " ";

	merge_sort(vec, 0, vec.size() - 1);

	cout << endl;
	for (int i = 0; i < 7; i++)
		cout << vec[i] << " ";

	return 0;
}