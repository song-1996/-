#include"Stack.h"
BTNode* BuyNode(BTDataType data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->data = data;
	NewNode->_Left = NULL;
	NewNode->_Right = NULL;
	return NewNode;
}
BTNode* _CreatBTree(BTNode** root, BTDataType* arr, int size,int* index)
{

		if ((*index) < size && arr[*index] != '#')
		{
			*root = BuyNode(arr[*index]);
			(*index)++;
		}
		else
			return NULL;
		_CreatBTree(&(*root)->_Left, arr, size, index);
		(*index)++;
		_CreatBTree(&(*root)->_Right, arr, size, index);
		return *root;
		
}

void DestroyBTree(BTNode** root)
{
	if (*root)
	{
		DestroyBTree(&(*root)->_Left);
		DestroyBTree(&(*root)->_Right);
		free(*root);
	}
	*root = NULL;
}
BTNode* CreatBTree(BTDataType* arr, int size)
{
	int index = 0;
	BTNode* root;
	return _CreatBTree(&root, arr, size, &index);
}
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->_Left);
		PreOrder(root->_Right);
	}
}
void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->_Left);
		printf("%c ", root->data);
		InOrder(root->_Right);
	}
}
void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->_Left);
		PostOrder(root->_Right);
		printf("%c ", root->data);
	}
}
int GetNodeCount(BTNode* root)
{
	if (!root)
	return 0;
	return GetNodeCount(root->_Left) + GetNodeCount(root->_Right) + 1;
}
int GetLeafCount(BTNode* root)
{
	if (!root)
		return 0;
	if (!root->_Left && !root->_Right)
		return 1;
	return GetLeafCount(root->_Left) + GetLeafCount(root->_Right);
}
int Height(BTNode* root)
{
	if (!root)
		return 0;
	else
	{
		int leftHeight = Height(root->_Left);
		int rightHeight = Height(root->_Right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
}
BTDataType FindRoot(BTNode* root)
{
	if (!root)
		return -1;
	else
		return root->data;
}

int FindNode(BTNode* root, BTDataType data)
{
	if (!root)
		return 0;

	if (root->data == data)
			return 1;
	if(FindNode(root->_Left, data) || FindNode(root->_Right, data))
		return 1;

	return 0;
}

BTNode* CopyBinTree(BTNode* root)
{
	BTNode* str = NULL;
	if (root)
	{
		str = root;
		CopyBinTree(root->_Left);
		CopyBinTree(root->_Right);
	}
	return str;
}
int GetKlevelNodeCount(BTNode* root, int k)
{
	if (!root || k < 1)
		return 0;
	if (k == 1)
		return 1;
	return GetKlevelNodeCount(root->_Left,k-1) + GetKlevelNodeCount(root->_Right,k-1);
}
BTNode* GetNodeParent(BTNode* root, BTNode* Node)
{
	if (!root || root == Node||!Node)
		return NULL;
	static BTNode* Parent = NULL;
	if (root->_Left == Node || root->_Right == Node)
		Parent = root;
	GetNodeParent(root->_Left, Node);
		GetNodeParent(root->_Right, Node);
		return	Parent;
}
BTNode* GetNode(BTNode* root, BTDataType data)
{
	if (!root)
		return NULL;
	static BTNode* Node = NULL;
		if (root->data == data)
				Node = root;
		GetNode(root->_Left, data);
		GetNode(root->_Right, data);
	return Node;
}

void PreOrderNor(BTNode* root)
{
	Stack s;
	InitStack(&s);
	PushStack(&s, root);
	while (!EmptyStack(&s))
	{
		BTNode* str = GetTopStack(&s);
		printf("%c ", str->data);
		PopStack(&s);
		if (str->_Right)
			PushStack(&s, str->_Right);
		if (str->_Left)
			PushStack(&s, str->_Left);
	}
	DestroyStack(&s);
}
void InOrderNor(BTNode* root)
{
	Stack s;
	InitStack(&s);
	while (root||!EmptyStack(&s))
	{
		while (root)
		{
			PushStack(&s, root);
			root = root->_Left;
		}
		BTNode* str = GetTopStack(&s);
		printf("%c ", str->data);
		PopStack(&s);
		if(str->_Right)
			root = str->_Right;
	}
	DestroyStack(&s);
}
void PostOrderNor(BTNode* root)
{
	BTNode* pCur = root;
	BTNode* pPrev = NULL;
	Stack s;
	InitStack(&s);
	while (pCur || !EmptyStack(&s))
	{
		while (pCur)
		{
			PushStack(&s, pCur);
			pCur = pCur->_Left;
		}
		BTNode* pTop = GetTopStack(&s);
		if (pTop->_Right == NULL||pTop->_Right==pPrev)
		{
			printf("%c ", pTop->data);
			pPrev = pTop;
			PopStack(&s);
		}
		else
			pCur = pTop->_Right;
	}
	DestroyStack(&s);
}

void LevelOrder(BTNode* root)
{
	if (!root)
		return;
	BTNode* pcur = root;
	Queue s;
	InitQueue(&s);
	QueuePush(&s, root);
	while (!QueueEmpty(&s))
	{
		pcur = QueueFront(&s);
		printf("%c ", pcur->data);
		QueuePop(&s);
		if (pcur->_Left)
			QueuePush(&s, pcur->_Left);
		if (pcur->_Right)
			QueuePush(&s, pcur->_Right);
	}
	DestroyQueue(&s);
}

int _isBalanced(BTNode* root)
{
	int height = 0;
	if (root)
	{
		if (!root->_Left && !root->_Right)
			return 0;
		else
			return 1;
	}
	else
		return 0;
	return abs(_isBalanced(root->_Left) - _isBalanced(root->_Right)) + height;
}
int isBalanced(BTNode* root)
{
	if (!root)
		return 1;
	int ret = 0;
	ret = abs(_isBalanced(root->_Left) - _isBalanced(root->_Right));
	if (ret < 2)
		return 1;
	return 0;
}

void _reConstructBinaryTree(BTNode** root, int* index, int* pre, int* vin, int left, int right)
{
	(*root) = BuyNode( pre[*index]);
	int i = left;
	for (; i < right; i++)
	{
		if (pre[*index] == vin[i])
			break;
	}
	(*index)++;
	if (i > left)
		_reConstructBinaryTree(&(*root)->_Left, index, pre, vin, left, i);
	if (right > i+1)
		_reConstructBinaryTree(&(*root)->_Right, index, pre, vin, i + 1, right);
}
	BTNode*  reConstructBinaryTree(int* pre, int* vin,int sz)
	{
		BTNode* root = NULL;
		int index = 0;
		int left = 0;
		int right =sz;
		if (sz == 0)
			return root;
		_reConstructBinaryTree(&root, &index, pre, vin, left, right);
		return root;
	}