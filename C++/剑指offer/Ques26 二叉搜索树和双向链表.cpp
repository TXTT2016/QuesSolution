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

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

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

	//DFS,先找到最小，然后次小
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