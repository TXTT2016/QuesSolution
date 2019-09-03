#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <stack>
#include <mutex>
#include <assert.h>
using namespace std;

//��������

//�Կ��ŵ��Ż������
//�Կ��Ž����Ż�����׼ֵ��ѡȡ������ѡҪ�����е���ǰ�������м�3���������
//��������Ϊ��׼ֵ������������Ч���Ϳ��ŵ�ʱ�临�Ӷȣ����Ƕ�����
//��ͬ���ݵĿ�����Ȼ����ʮ�����룬���Կ����ں����м��϶Դ�����ͬ���ݵ�
//������룬���о����ڿ��ŷ����㹻С�����ʹ����������ʽ�����ǿ�����
//���Ч��
template <class Elem>
void quick_Sort(Elem a[], int i, int j)
{
	if (i >= j) return;
	int first = i, last = j, flag = a[first];

	while (first < last)
	{
		while (first < last && a[last] >= flag)//����falg��ķ��ұ�
			--last;
		if (last > first) a[first] = a[last];
		while (first < last && a[first] <= flag)//����falgС�ķ����
			++first;
		if (first < last) a[last] = a[first];
	}
	a[first] = flag;
	quickSort(a, i, first - 1);//����߽��п���
	quickSort(a, first + 1, j);//���ұ߽��п���
}

void insert_Sort(vector<int>& vec, int start, int end);

void quick_Sort(vector<int>& vec, int start, int end)
{
	if (start >= end)
		return;
	int first = start, last = end, flag = vec[start];
	while (first < last)
	{
		while (first < last && vec[last] >= flag)
			--last;
		if (last > first) vec[first] = vec[last];
		while (first < last && vec[first] <= flag)
			++first;
		if (first < last) vec[last] = vec[first];
	}
	vec[first] = flag;
	quick_Sort(vec, start, first - 1);
	quick_Sort(vec, first + 1, end);
}

//���ѡȡ��־λ
int selectRandomPoint(vector<int>& vec, int start, int end)
{
	srand((unsigned)time(NULL));
	int pivotPos = rand() % (start - end);

	swap(vec[start], vec[pivotPos]);//����־λ�����λ����λ�ã�����ʹ��һ��Ŀ���
	return pivotPos;
}

//start, mid, end����ȥ�м�������־λ
int selectMedianOfThree(vector<int>& vec, int start, int end)
{
	int mid = ((end - start) >> 1) + start;

	if (vec[mid] > vec[end]) swap(vec[mid], vec[end]);
	if (vec[start] > vec[end]) swap(vec[start], vec[end]);
	if (vec[start] < vec[mid]) swap(vec[start], vec[mid]);
	//��ʱvec[mid] < vec[start] < vec[end]
	//ѡȡ�ı�־λ��Ȼ���ײ���������ó��ÿ����㷨
	return vec[start];
}

//�Ż�����

//1.�����������еĳ��ȷָһ����С����ò���������Ϊ���ں�С�Ͳ�����������飬���Ų������
//һ�㷶ΧΪ 5 - 20
void quick_Sort_2(vector<int>& vec, int start, int end)
{
	if (start >= end)
		return;
	if (end - start + 1 < 10)
	{
		insert_Sort(vec, start, end);
		return;
	}

	int first = start, last = end, flag = selectRandomPoint(vec, start, end);
	while (first < last)
	{
		while (first < last && vec[last] >= flag)
			--last;
		if (last > first) vec[first] = vec[last];
		while (first < last && vec[first] <= flag)
			++first;
		if (first < last) vec[last] = vec[first];
	}
	vec[first] = flag;
	quick_Sort(vec, start, first - 1);
	quick_Sort(vec, first + 1, end);
}
void insert_Sort(vector<int>& vec, int start, int end)
{
	for (int i = start + 1; i <= end; i++)
		for (int j = start; j < i; j++)
			if (vec[j] > vec[i])
				swap(vec[j], vec[i]);
}

//2.��ѡȡ�ı�־λԪ��������������ж��ظ��Ļ���������һ�κ󽫺�����ֵ��ͬ��Ԫ�طŵ������ܱ߼��ɡ�
//��������������������н�������Ԫ��ֵ��ͬ��Ԫ���ȷ����������ˣ�����һ�κ��ٷŵ�����Ԫ����Χ����

void quick_Sort_3(vector<int>& vec, int start, int end)
{
	if (start >= end)
		return;
	if (end - start + 1 < 10)
	{
		insert_Sort(vec, start, end);
		return;
	}
	int first = start, last = end, flag = selectMedianOfThree(vec, start, end);
	int rightLen = 0, leftLen = 0;//����len�ֱ��¼�������������еĺ�����Ԫ��ֵ��ͬ��Ԫ�صĸ���
	while(first < last)
	{
		while (first < last && vec[last] >= flag)
		{
			if (vec[last] == flag)
				swap(vec[end - (rightLen++)], vec[last]);
			--last;
		}
		if (vec[last] < flag)
			vec[first] = vec[last];
		while (first < last && vec[first] <= flag)
		{
			if (vec[first] == flag)
				swap(vec[start + (leftLen++)], vec[first]);
			++first;
		}
		if (vec[first] > flag)
			vec[last] = vec[first];
	}
	vec[first] = flag;

	//����ߺ��ұ�����ŵĺ�����Ԫ��ֵ��ȵ�Ԫ�طŵ��������
	for(int i=0; i<leftLen; i++)
		swap(vec[start + i], vec[first - i - 1]);
	for(int i=0; i<rightLen; i++)
		swap(vec[end - i], vec[first + i + 1]);
	//�ٴο���ʱֻ��Ҫ��������ֵ��ͬ�����߽������򼴿ɡ�
	quick_Sort_3(vec, start, first - leftLen - 1);
	quick_Sort_3(vec, first + rightLen + 1, end);
}

//3.ʹ�ö��̶߳������н�������

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34, 23, 54, 99, 7, 35, 56, 78, 23, 34, 44, 15, 17, 68 };
	//insert_Sort(vec, 0, vec.size() - 1);
	//quick_Sort(vec, 0, vec.size() - 1);
	//quick_Sort_2(vec, 0, vec.size() - 1);

	vector<int> vec2{ 1, 4, 6, 7, 6, 6, 7, 6, 8, 6 };
	//quick_Sort_3(vec2, 0, vec2.size() - 1);

	return 0;
}