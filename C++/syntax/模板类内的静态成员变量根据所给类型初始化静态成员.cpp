#include <iostream>

using namespace std;

template <typename T>
class test
{
public:
	static int data;
};

int test<int>::data = 1;
int test<char>::data = 2;

int main()
{
	cout << test<int>::data << endl;
	cout << test<char>::data << endl;

	return 0;
}