#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		if (sequence.empty())
			return false;
		return f(sequence, 0, sequence.size() - 1);
	}
	//���ұߵ�Ϊ���ڵ�
	bool f(vector<int> sequence, int head, int back)
	{
		if (sequence.empty())
			return false;
		if (head >= back)
			return true;

		int j = back - 1;
		int i = head;
		while (sequence[j] > sequence[back])//ɸѡ��������head -- j
			j--;
		while (sequence[i] < sequence[back])//ɸѡ��������i -- back
			i++;
		if (i > j)
		{
			return f(sequence, head, j) && f(sequence, i, back - 1);
		}
		return false;
	}
};