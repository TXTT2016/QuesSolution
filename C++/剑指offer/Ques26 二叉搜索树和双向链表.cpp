#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL)
	{}
};

//����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

class Solution
{
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* temp = nullptr;
		convert(pRootOfTree, temp);
		while (temp->left != nullptr && temp != nullptr)
			temp = temp->left;
		return temp;
	}

	//DFS,���ҵ���С��Ȼ���С
	void convert(TreeNode* node, TreeNode*& temp)
	{
		if (node == nullptr)
			return;

		if (node->left != nullptr)
			convert(node->left, temp);

		node->left = temp;
		if (temp != nullptr)
			temp->right = node;
		temp = node;

		if (node->right != nullptr)
			convert(node->right, temp);
	}

};