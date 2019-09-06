#include <iostream>
#include <vector>
using namespace std;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	//����+����
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
	{
		if (pre.empty() || in.empty())
			return nullptr;

		TreeNode * node = new TreeNode(pre[0]);

		int rootIndex = 0;
		while (rootIndex < pre.size() && in[rootIndex] != pre[0]) rootIndex++;//�ҵ����ڵ�λ��

		vector<int> pre_left, pre_right, in_left, in_right;

		//���ݸ��ڵ��ҳ���������
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
		node->left = reConstructBinaryTree(pre_left, in_left);
		node->right = reConstructBinaryTree(pre_right, in_right);

		return node;
	}

	//����+����(δ����)
	TreeNode* reConstructBinaryTree(vector<int> aft, vector<int> in)
	{
		if (aft.empty() || in.empty())
			return nullptr;

		TreeNode * node = new TreeNode(aft.back());

		int rootIndex = 0;
		while (rootIndex < aft.size() && in[rootIndex] != aft.back()) rootIndex++;//�ҵ����ڵ�λ��

		vector<int> pre_left, pre_right, in_left, in_right;

		//���ݸ��ڵ��ҳ���������
		for (int i = 0; i < rootIndex; i++)
		{
			pre_left.push_back(aft[i]);
			in_left.push_back(in[i]);
		}
		for (int i = rootIndex; i < aft.size() - 1; i++)
		{
			pre_right.push_back(aft[i]);
			in_right.push_back(in[i+1]);
		}
		node->left = reConstructBinaryTree(pre_left, in_left);
		node->right = reConstructBinaryTree(pre_right, in_right);

		return node;
	}
};