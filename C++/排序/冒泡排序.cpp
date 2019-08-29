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

//ц╟ещеепР
template <class Elem>
void bubsort(Elem A[], int len)
{
	
	int i, j;
	 for (i = 0; i < len - 1; i++)
		 for (j = 0; j < len - 1 - i; j++)
			 if (Comp<Elem>::lt(A[j], A[j + 1]))
			swap(A[j], A[j + 1]);
}

int main()
{
	vector<int> vec{ 20, 39, 12, 55, 34, 78, 56, 34 };
	

	return 0;
}