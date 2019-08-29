# include <iostream>
# include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//根据先序和中序遍历还原二叉树
template <typename T>
TreeNode * BinaryTreeFromPreorderAndInorder(vector<T> pre, vector<T> in)
{
	if (pre.empty() || in.empty())
		return nullptr;
	
	TreeNode * node = new TreeNode(pre[0]);
	
	int rootIndex = 0;
	while (rootIndex < pre.size() && in[rootIndex] != pre[0]) rootIndex++;

	vector<T> pre_left, pre_right, in_left, in_right;

	for (int i = 0; i < rootIndex; i++)
	{
		pre_left.push_back(pre[i + 1]);
		in_left.push_back(in[i]);
	}

	for (int i = rootIndex + 1; i < pre.size(); i++)
	{
		pre_right.push_back(pre[i]);
		in_right.push_back(in[i]);
	}
	node->left = BinaryTreeFromPreorderAndInorder(pre_left, in_left);
	node->right = BinaryTreeFromPreorderAndInorder(pre_right, in_right);

	return node;
}



int main()
{
	vector<int> pre = { 1, 3, 4, 2, 5 };
	vector<int> in = { 3, 4, 1, 2, 5 };


	return 0;
}