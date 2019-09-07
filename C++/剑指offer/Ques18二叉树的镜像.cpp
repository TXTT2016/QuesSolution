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

class Solution
{
public:
	void Mirror(TreeNode *pRoot)
	{
		preOrder(pRoot);
	}
	//DFS
	void preOrder(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return;
		if (pRoot->left != nullptr || pRoot->right != nullptr)
			swap(pRoot->left, pRoot->right);
		preOrder(pRoot->left);
		preOrder(pRoot->right);
	}

};