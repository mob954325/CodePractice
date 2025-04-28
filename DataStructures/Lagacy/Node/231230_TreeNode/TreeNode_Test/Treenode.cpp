#include <iostream>

using namespace std;

struct TreeNode
{
	int Data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data)
		: Data(data), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, int data)
{
	if (root = nullptr) // root 포인터가 null이면
	{
		return new TreeNode(data);
	}

	if (data < root->Data)
	{
		root->left = insertNode(root->left, data);
	}
	else if(data > root->Data)
	{
		root->right = insertNode(root->right, data);
	}
	return root;
}

void inorder(TreeNode* root)
{
	if (root != nullptr)
	{
		cout << root->Data << ' ';
	}
}