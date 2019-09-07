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

//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

class Solution
{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == nullptr) return false;
		if (pRoot1 == nullptr && pRoot2 != nullptr) return false;

		bool flag = false;
		if (pRoot1->val == pRoot2->val)
			flag = IsSubtree(pRoot1, pRoot2);
		if (!flag)
		{
			flag = HasSubtree(pRoot1->left, pRoot2);//DFS
			if (!flag)
				flag = HasSubtree(pRoot1->right, pRoot2);
		}
		return flag;
	}

	bool IsSubtree(TreeNode* root1, TreeNode* root2)
	{
		if (root2 == nullptr) return true;
		if (root1 == nullptr && root2 != nullptr) return false;
		if (root1->val == root2->val)
			return IsSubtree(root1->left, root2->left) && IsSubtree(root1->right, root2->right);
		else
			return false;
	}

};