#include <iostream>
#include <vector>
#include <Queue>
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
	//BFS
	vector<int> PrintFromTopToBottom(TreeNode* root)
	{
		queue<TreeNode *> Queue;
		vector<int> val;
		if (root != nullptr)
			Queue.push(root);

		while (!Queue.empty())
		{
			val.push_back(Queue.front()->val);
			TreeNode * node = Queue.front();
			Queue.pop();
			if (node->left)
				Queue.push(node->left);
			if (node->right)
				Queue.push(node->right);
		}
		return val;
	}
};