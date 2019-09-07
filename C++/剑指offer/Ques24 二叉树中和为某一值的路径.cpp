#include <iostream>
#include <vector>

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
	vector<vector<int> > res;
	vector<int> path;
	//DFS
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
	{
		if (root == nullptr)
			return res;

		path.push_back(root->val);

		if (root->val == expectNumber && root->left == nullptr && root->right == nullptr)
			res.push_back(path);
		else
		{
			if (root->left)
				FindPath(root->left, expectNumber - root->val);
			if (root->right)
				FindPath(root->right, expectNumber - root->val);
		}
		if (!path.empty())
			path.pop_back();

		return res;

	}
};