

//class Solution
//{
//public:
//	int depth(TreeNode* root)
//	{
//		if (root == nullptr)    return 0;
//
//		int left = depth(root->left);
//		if (left == -1)    return -1; //�������������ƽ��֮���û�б�Ҫ��������ĸ߶ȵ������
//		
//		int right = depth(root->right);
//		if (right == -1)    return -1;//�������������ƽ��֮���û�б�Ҫ��������ĸ߶ȵ������
//
//		if (abs(left - right) > 1)
//			return -1;
//		else
//			return 1 + (left > right ? left : right);
//	}
//
//	bool IsBalanced_Solution(TreeNode* pRoot)
//	{
//		return depth(pRoot) != -1;
//	}
//};

