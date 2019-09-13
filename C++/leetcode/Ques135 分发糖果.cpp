#include <vector>


using namespace std;
//维护一个同等大小的糖果数组（先全置为1），多次遍历原数组，对每个元素和左右元素进行比较
//当大于左边的糖果+1，大于右边的糖果+1，一直到遍历一次后糖果数组未发生变化则完成。时间复杂度N方，空间N

//第二种是维护两个糖果数组，一个是从左到右遍历的，一个是从右到左遍历的，遍历完两遍后
//取糖果数组即可，相同位置上的值取较大者。

//第三种是仅维护一个糖果数组（先全置为1），从左到右遍历一遍，当rank[i] > rank[i-1]时,candy[i] + candy[i-1] + 1
//再次从右往左遍历数组，但是这次是当rank[i] > rank[i+1]并且candy[i]<=candy[i+1]时才更新candy[i]=candy[i+1]+1;
//因为当从左往右遍历时可能candy[i]就已经大于candy[i]+1了

//第四种方法有点看不懂- -!(其实就是没认真看)，当初自己做的时候没看题解也是用另一种方法做的，测试用例都能过，也没用额外空间，但就是不知为啥感觉这么怪

//这里直接采用第三种方法
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