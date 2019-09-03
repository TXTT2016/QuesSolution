#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <stack>
#include <mutex>
#include <assert.h>
using namespace std;

template <class Elem>
class Comp {
public:
	static bool lt(Elem x, Elem y)
	{
		return x > y ? true : false;
	}
};

template <class Elem>
//��������
void inssort(Elem A[], int len)
{
	int i, j;
	for (i = 1; i < len; i++)//��Ϊ����Ҫ�Ըô������е�ÿһ��Ԫ�ض���ǰ������ź�������н��в��룬�������ǻ�����н��б��� 
		for (j = 0; j < i; j++) //�ڶ���ѭ����Ҫ���ڶ����ź�������н���ɨ�裬��Ҫ������������ݽ�����һ�Ƚϣ�Ȼ��������뵽���� 
			if (!Comp<Elem>::lt(A[i], A[j])) //��ǰ��������ź����Ԫ�غʹ�����Ԫ�ؽ��д�С�Ƚϣ�Ȼ��ֱ���ҵ�һ��Ԫ�رȱ�����Ԫ�ش��򽻻�λ�� 
				swap(A[i], A[j]);
}

void insert_Sort(vector<int>& vec, int len)
{
	for (int i = 1; i < len; i++)
		for (int j = 0; j < i; j++)
			if (vec[i] < vec[j])
				swap(vec[i], vec[j]);
}

//���������ÿһ����λ����������ʱ��Ƚ϶࣬һ���Ż���ʽ���ǽ�����ֱ�Ӹĳɸ�ֵ���Ƚ���ʼλ��Ԫ�ر�������
//��������Ҫ����λ�ã���������ȫ��ת���ɸ�ֵ����

//�ټ�һ�����Ż����Ǽ��ٱȽϴ��������۰�鷨��ֱ���ҵ���һ���ȴ��Ƚ�Ԫ��С��Ԫ�أ�Ȼ�����ĸ�ֵ����֮ǰ����Ҫ���д�С�ıȽ�
void insert_Sort_2(vector<int>& vec, int len)
{
	int flag;
	for (int i = 1; i < len; i++)
	{
		flag = vec[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (vec[j] > flag)
				vec[j + 1] = vec[j];
			else
				break;
		}
		vec[j + 1] = flag;
	}
		
}


int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	insert_Sort_2(vec, vec.size());

	return 0;
}