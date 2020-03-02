#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		, _parent(nullptr)
		,_data(data)
		,_bf(0)
	{}
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	T _data;
	int _bf;
};

template<class T>
class AVLTree
{
public:
	typedef AVLTreeNode<T> Node;
	typedef Node* PNode;
	AVLTree()
		:_root(nullptr)
	{}
	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
		}
		else
		{
			PNode cur = _root;
			PNode parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (cur->_data < data)
					cur = cur->_right;
				else if (cur->_data > data)
					cur = cur->_left;
				else
					return false;
			}
			PNode pCur = new Node(data);
			if (data < parent->_data)
				parent->_left = pCur;
			else
				parent->_right = pCur;
			pCur->_parent = parent;
			while (parent)
			{
				if (parent->_left == pCur)
					parent->_bf--;
				else
					parent->_bf++;
				if (0 == parent->_bf)
					break;
				else if (1 == parent->_bf || -1 == parent->_bf)
				{
					pCur = parent;
					parent = parent->_parent;
				}
				else
				{
					if (2 == parent->_bf)
					{
						if (1 == pCur->_bf)
						{
							Rotate_Left(parent);
						}
						else
						{
							RotateRL(parent);
						}
					}
					else
					{
						if (-1 == pCur->_bf)
						{
							Rotate_Right(parent);
						}
						else
						{
							RotateLR(parent);
						}
					}
					break;
				}
			}
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
	}
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}
private:
	
	int Height(PNode root)
	{
		if (root == nullptr)
			return 0;
		int left_height = Height(root->_left);
		int right_height = Height(root->_right);
		return left_height > right_height ? left_height + 1 : right_height + 1;
	}
	bool _IsBalanceTree(PNode root)
	{
		if (root == nullptr)
			return true;
		if ((abs(Height(root->_right) - Height(root->_left)) > 1)||
			(Height(root->_right) - Height(root->_left) !=(root->_bf)))
			return false;
		return _IsBalanceTree(root->_left)&&
			_IsBalanceTree(root->_right);
	}
	void _InOrder(PNode root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << ' ';
			_InOrder(root->_right);
		}
	}
	void Rotate_Left(PNode root)
	{
		PNode SubR = root->_right;
		PNode Parent = root;
		PNode SubRL = SubR->_left;
		Parent->_right = SubRL;
		if (SubRL)
			SubRL->_parent = Parent;
		SubR->_left = Parent;
		SubR->_parent = Parent->_parent;
		Parent->_parent = SubR;
		PNode pParent = SubR->_parent;
		if (pParent)
		{
			if (pParent->_left == Parent)
				pParent->_left = SubR;
			else
				pParent->_right = SubR;
		}
		else
			_root = SubR;
		SubR->_bf = 0;
		Parent->_bf = 0;
	}
	void Rotate_Right(PNode root)
	{
		PNode SubL = root->_left;
		PNode Parent = root;
		PNode SubLR = SubL->_right;
		Parent->_left = SubLR;
		if (SubLR)
			SubLR->_parent = Parent;
		SubL->_right = Parent;
		SubL->_parent = Parent->_parent;
		Parent->_parent = SubL;
		PNode pParent = SubL->_parent;
		if (pParent)
		{
			if (pParent->_left == Parent)
				pParent->_left = SubL;
			else
				pParent->_right = SubL;
		}
		else
			_root = SubL;
		SubL->_bf = 0;
		Parent->_bf = 0;
	}
	void RotateRL(PNode parent)
	{
		PNode pSubR = parent->_right;
		PNode pSubRL = parent->_left;
		int bf = pSubRL->_bf;
		Rotate_Right(parent->_right);
		Rotate_Left(parent);
		if (bf == -1)
			pSubR->_bf = 1;
		else
			parent->_bf = -1;
	}
	void RotateLR(PNode parent)
	{
		PNode pSubL = parent->_left;
		PNode pSubLR = pSubL->_right;
		int bf = pSubLR->_bf;
		Rotate_Left(parent->_left);
		Rotate_Right(parent);
		if (bf == -1)-
			parent->_bf = 1;
		else
			pSubL->_bf = -1;
	}
private:
	PNode _root;
};