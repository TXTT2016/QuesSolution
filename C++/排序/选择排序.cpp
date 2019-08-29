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
//—°‘Ò≈≈–Ú
void selsort(Elem A[], int len)
{
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
			if (Comp<Elem>::lt(A[i], A[j]))
				swap(A[i], A[j]);
}

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	

	return 0;
}