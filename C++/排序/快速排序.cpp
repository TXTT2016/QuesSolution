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
void quickSort(Elem a[], int i, int j)
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

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	quick_sort(vec, 0, vec.size() - 1);

	return 0;
}