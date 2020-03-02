#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;

template<class T>
struct TreeNode
{
	TreeNode(const T& x)
		:left(nullptr)
		,right(nullptr)
		,data(x)
	{}
	TreeNode<T>* left;
	TreeNode<T>* right;
	T data;
};

template<class T>
class BSTree
{
public:
	typedef TreeNode<T> Node;
	typedef Node* PNode;
	BSTree()
		:root(nullptr)
	{}
	~BSTree()
	{
		Destroy(root);
		root = nullptr;
	}
	bool Find(const T& x)
	{
		if (root == nullptr)
			return false;
		PNode cur = root;
		while (cur)
		{
			if (cur->data == x)
				return true;
			else if (cur->data < x)
				cur = cur->right;
			else
				cur = cur->left;
		}
		return false;
	}
	bool Insert(const T& x)
	{
		if (root == nullptr)
		{
			PNode NewNode = new Node(x);
			root = NewNode;
		}
		else
		{
			PNode cur = root;
			PNode pParent = nullptr;
			while (cur)
			{
				 pParent = cur;
				if (cur->data > x)
				{
					cur = cur->left;
				}
				else if (cur->data < x)
				{
					cur = cur->right;
				}
				else
				{
					return false;
				}
			}
			if (pParent->data > x)
				pParent->left = new Node(x);
			else
				pParent->right = new Node(x);
		}
		return true;
	}
	bool Erase(const T& x)
	{
		if (root == nullptr)
			return false;
		PNode pParent = root;
		PNode cur = root;
		bool flag = false;
		while (cur)
		{
			if (cur->data == x)
			{
				flag = true;
				break;
			}
			else if (cur->data < x)
			{
				pParent = cur;
				cur = cur->right;
			}
			else
			{
				pParent = cur;
				cur = cur->left;
			}
		}
		if (flag)
		{
			if (cur->left == nullptr&&cur->right == nullptr)
			{
				delete cur;
				if(cur==root)
					cur = nullptr;
			}
			else if (cur->left&&cur->right == nullptr)
			{
				if (cur == root)
					root = root->left;
				else
				{
					if (pParent->left == cur)
						pParent->left = cur->left;
					else
						pParent->right = cur->left;
				}
				delete cur;
			}
			else if (cur->left == nullptr&&cur->right)
			{
				if (cur == root)
					root = root->right;
				else
				{
					if (pParent->left == cur)
						pParent->left = cur->right;
					else
						pParent->right = cur->right;
				}
				delete cur;
			}
			else
			{
					PNode leftmin = cur->right;
					pParent = cur;
					while (leftmin->left)
					{
						pParent = leftmin;
						leftmin = leftmin->left;
					}
					swap(leftmin->data, cur->data);
					if (pParent->left == leftmin)
						pParent->left = leftmin->right;
					else
						pParent->right = leftmin->right;
					delete leftmin;
			}
			return true;
		}
		else
			return false;
	}
	void Inorder()
	{
		_Inorder(root);
	}
	PNode Left_Min()
	{
		return _Left_Min(root);
	}
	PNode Right_Max()
	{
		return _Right_Max(root);
	}
private:
	PNode _Left_Min(PNode _root)
	{
		if (_root == nullptr)
			return nullptr;
		PNode cur = _root;
		while (cur->left)
		{
			cur = cur->left;
		}
		return cur;
	}
	PNode _Right_Max(PNode _root)
	{
		if (_root == nullptr)
			return nullptr;
		PNode cur = _root;
		while (cur->right)
		{
			cur = cur->right;
		}
		return cur;
	}
	void _Inorder(PNode _root)
	{
		if (_root)
		{
			_Inorder(_root->left);
			cout << _root->data << ' ';
			_Inorder(_root->right);
		}
	}
	void Destroy(PNode _root)
	{
		if (_root)
		{
			Destroy(_root->left);
			Destroy(_root->right);
			delete _root;
		}
	}
private:
	PNode root;
};