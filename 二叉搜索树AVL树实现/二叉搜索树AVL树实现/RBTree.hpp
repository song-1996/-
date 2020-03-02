#pragma once

enum Color{RED,BLACK};
template<class V>
struct RBTreeNode
{
	RBTreeNode<V>(const V& val=V(), Color color=RED)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_color(color)
		,_val(val)
	{}
	RBTreeNode<V>* _pLeft;
	RBTreeNode<V>* _pRight;
	RBTreeNode<V>* _pParent;
	V _val;
	Color _color;
};

template <class V>
class RBTree
{
public:
	typedef RBTreeNode<V> Node;
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}
	bool Insert(const V& val)
	{
		Node*& pRoot = _pHead->_pParent;
		if (nullptr == pRoot)
		{
			pRoot = new Node(val, BLACK);
			pRoot->_pParent = _pHead;
		}
		else
		{
			//按照二叉搜索树的性质插入新节点
			//找待插入节点在二叉搜索树中的位置
			Node* pCur = pRoot;
			Node* pParent = _pHead;
			while (pCur)
			{
				pParent = pCur;
				if (pCur->_val < val)
					pCur = pCur->_pRight;
				else if (pCur->_val > val)
					pCur = pCur->_pLeft;
				else
					return false;
			}
			//插入新节点
			pCur = new Node(val);
			if (pParent->_val > val)
				pParent->_pLeft = pCur;
			else
				pParent->_pRight = pCur;
			pCur->_pParent = pParent;
			while ( pParent!=_pHead && RED == pParent->_color)
			{
				Node* grandFather = pParent->_pParent;
				if (pParent == grandFather->_pLeft)
				{
					Node* uncle = grandFather->_pRight;
					if (uncle && RED == uncle->_color)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = pParent->_pParent;
						pParent = pCur->_pParent;
					}
					else
					{
						//叔叔节点可能不存在||叔叔节点存在且为黑
						//情况三：pCur是双亲的右孩子
						if (pCur == pParent->_pRight)
						{
							RotateL(pParent);
							swap(pParent, pCur);
						}
						grandFather->_color = RED;
						pParent->_color = BLACK;
						RotateR(grandFather);
					}
				}
				else
				{
					Node* uncle = grandFather->_pLeft;
					if (uncle && RED == uncle->_color)
					{
						pParent->_color = BLACK;
						uncle->_color = BLACK;
						grandFather->_color = RED;
						pCur = grandFather;
						pParent = pCur->_pParent;
					}
					else
					{
						if (pCur == pParent->_pLeft)
						{
							RotateR(pParent);
							swap(pParent, pCur);
						}
						grandFather->_color = RED;
						pParent->_color = BLACK;
						RotateL(grandFather);
					}
				}
			}

		}
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		pRoot->_color = BLACK;
		return true;
	}
	void InOrder()
	{
		_InOrder(GetRoot());
	}
private:
	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_pLeft);
			cout << root->_val << ' ';
			_InOrder(root->_pRight);
		}
	}
	void RotateL(Node* parent)
	{
		Node* pSubR = parent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		parent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = parent;
		pSubR->_pLeft = parent;
		pSubR->_pParent = parent->_pParent;
		parent->_pParent = pSubR;
		Node* pparent = pSubR->_pParent;
		if (pparent!=_pHead)
		{
			if (pparent->_pLeft == parent)
				pparent->_pLeft = pSubR;
			else
				pparent->_pRight = pSubR;
		}
		else
			GetRoot() = pSubR;
	}
	void RotateR(Node* parent)
	{
		Node* pSubL = parent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		parent->_pLeft = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = parent;
		pSubL->_pRight = parent;
		pSubL->_pParent = parent->_pParent;
		parent->_pParent = pSubL;
		Node* pparent = pSubL->_pParent;
		if (pparent != _pHead)
		{
			if (pparent->_pLeft == parent)
				pparent->_pLeft = pSubL;
			else
				pparent->_pRight = pSubL;
		}
		else
			GetRoot() = pSubL;
	}
	Node* LeftMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;
		return pCur;
	}
	Node* RightMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;
		while (pCur->_pRight)
			pCur = pCur->_pRight;
		return pCur;
	}
	Node*& GetRoot()
	{
		return _pHead->_pParent;
	}
private:
	Node* _pHead;
};