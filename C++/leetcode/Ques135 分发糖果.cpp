#include <vector>


using namespace std;
//ά��һ��ͬ�ȴ�С���ǹ����飨��ȫ��Ϊ1������α���ԭ���飬��ÿ��Ԫ�غ�����Ԫ�ؽ��бȽ�
//��������ߵ��ǹ�+1�������ұߵ��ǹ�+1��һֱ������һ�κ��ǹ�����δ�����仯����ɡ�ʱ�临�Ӷ�N�����ռ�N

//�ڶ�����ά�������ǹ����飬һ���Ǵ����ұ����ģ�һ���Ǵ��ҵ�������ģ������������
//ȡ�ǹ����鼴�ɣ���ͬλ���ϵ�ֵȡ�ϴ��ߡ�

//�������ǽ�ά��һ���ǹ����飨��ȫ��Ϊ1���������ұ���һ�飬��rank[i] > rank[i-1]ʱ,candy[i] + candy[i-1] + 1
//�ٴδ�������������飬��������ǵ�rank[i] > rank[i+1]����candy[i]<=candy[i+1]ʱ�Ÿ���candy[i]=candy[i+1]+1;
//��Ϊ���������ұ���ʱ����candy[i]���Ѿ�����candy[i]+1��

//�����ַ����е㿴����- -!(��ʵ����û���濴)�������Լ�����ʱ��û�����Ҳ������һ�ַ������ģ������������ܹ���Ҳû�ö���ռ䣬�����ǲ�֪Ϊɶ�о���ô��

//����ֱ�Ӳ��õ����ַ���
class Solution
{
public:
	int candy(vector<int>& ratings)
	{
		vector<int> candy(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); i++)
			if (ratings[i] > ratings[i - 1])
				candy[i] = candy[i - 1] + 1;
		for (int i = ratings.size() - 2; i >= 0; i--)
			if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
				candy[i] = candy[i + 1] + 1;
		int sum = 0;
		for (int i = 0; i < candy.size(); i++)
			sum += candy[i];
		return sum;
	}
};