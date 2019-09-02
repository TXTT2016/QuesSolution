#include <iostream>
#include <vector>
using namespace std;


//��ǰ�����������һ�����Ͱ�������������Ӽ��������Ӽ�����������������Ӽ�
class Solution
{
public:
	static vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int> > res;
		res.push_back({});
		for (int i = 0; i < nums.size(); i++)
		{
			int len = res.size();
			for (int j = 0; j < len; j++)
			{
				vector<int> temp;
				for (int k = 0; k < res[j].size(); k++)
				{
					temp.push_back(res[j][k]);
				}
				temp.push_back(nums[i]);
				res.push_back(temp);
			}
			
		}
		return res;
	}
};

int main()
{
	vector<int> vec{ 1,2,3 };

	vector<vector<int> > res = Solution::subsets(vec);

	return 0;
}