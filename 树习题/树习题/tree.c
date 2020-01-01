#include"tree.h"

Node* BuyNode(int data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->val = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}
Node* _CreatBTree(Node** root, int* arr, int size, int* index)
{

	if ((*index) < size && arr[*index] != '#')
	{
		*root = BuyNode(arr[*index]);
		(*index)++;
	}
	else
		return NULL;
	_CreatBTree(&(*root)->left, arr, size, index);
	(*index)++;
	_CreatBTree(&(*root)->right, arr, size, index);
	return *root;

}

void DestroyBTree(Node** root)
{
	if (*root)
	{
		DestroyBTree(&(*root)->left);
		DestroyBTree(&(*root)->right);
		free(*root);
	}
	*root = NULL;
}
Node* CreatBTree(int* arr, int size)
{
	int index = 0;
	Node* root;
	return _CreatBTree(&root, arr, size, &index);
}
int GetNodeCount(Node* root)
{
	if (!root)
		return 0;
	return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}
void PreOrderTree1(Node* root, int* s, int* index)

{
	if (root)
	{
		s[(*index)++] = root->val;
		PreOrderTree1(root->left, s, index);
		PreOrderTree1(root->right, s, index);
	}
}
void InOrderTreeS1(Node* root, int* s, int* index)
{
	if (root)
	{
		InOrderTreeS1(root->left, s, index);
		s[(*index)++] = root->val;
		InOrderTreeS1(root->right, s, index);
	}

}
int isSameTree(Node* p, Node* q)
{
	int sz1 = GetNodeCount(p);
	int sz2 = GetNodeCount(q);
	int sz = 0;
	if (sz1 != 0 && sz2 == 0 || sz1 == 0 && sz2 != 0)
	{
		return 0;
	}
	if (sz1 == 0 && sz2 == 0)
		return 1;
	int* s1Or = (int*)malloc(sizeof(int)*sz1);
	int* s2Or = (int*)malloc(sizeof(int)*sz2);
	int* s1Pre = (int*)malloc(sizeof(int)*sz1);
	int* s2Pre = (int*)malloc(sizeof(int)*sz2);
	if (p)
	{
		int index = 0; int index1 = 0;
		PreOrderTree1(p, s1Pre, &index1);
		InOrderTreeS1(p, s1Or, &index);
	}
	if (q)
	{
		int index1 = 0; int index = 0;
		PreOrderTree1(q, s2Pre, &index1);
		InOrderTreeS1(q, s2Or, &index);
	}
	int i = 0;
	if (sz1 <= sz2)
		sz = sz2;
	while (i < sz)
	{
		if ((s1Pre[i] == s2Pre[i] && s1Or[i] == s2Or[i]) && (!(s1Pre[i] == s1Pre[i + 1] && s2Or[i] == s2Or[i + 1])))
			i++;
		else
			return 0;
	}
	return 1;
}
//
//Node* _buildTree(int *pre, int preSize, int* ino, int left, int right, int* index)
//{
//	if (right-left <1)
//		return NULL;
//	int left1 = left;
//	Node* NewTree = (Node*)malloc(sizeof(Node));
//	if (NewTree == NULL)
//	{
//		return NULL;
//	}
//	NewTree->val = pre[*index];
//	NewTree->left = NULL;
//	NewTree->right = NULL;
//	while (left < right)
//	{
//		if (ino[left] == pre[*index])
//		{
//			break;
//		}
//		left++;
//	}
//	(*index)++;
//	NewTree->left = _buildTree(pre, preSize, ino, left1, left, index);
//	NewTree->right = _buildTree(pre, preSize, ino, left+1, right, index);
//	return NewTree;
//}
//Node* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
//{
//	int index = 0;
//	return  _buildTree(preorder, preorderSize, inorder, 0, inorderSize, &index);
//}

Node* _buildTree(int* ino, int inoSize, int* pos, int left, int right, int* index)
{
	if (right - left < 1)
		return  NULL;
	int left1 = left;
	Node* NewTree = (Node*)malloc(sizeof(Node));
	if (NewTree == NULL)
		return NULL;
	NewTree->val = pos[*index - 1];
	NewTree->left = NULL;
	NewTree->right = NULL;
	while (left < right)
	{
		if (ino[left] == pos[*index - 1])
			break;
		left++;
	}
	(*index)--;
	NewTree->right = _buildTree(ino, inoSize, pos, left + 1, right, index);
	NewTree->left = _buildTree(ino, inoSize, pos, left1, left, index);
	return NewTree;
}
Node* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
	int index = postorderSize;
	return _buildTree(inorder, inorderSize, postorder, 0, postorderSize, &index);
}