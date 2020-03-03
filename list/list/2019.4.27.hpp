#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;



template<class T>
struct ListNode
{
	ListNode(const T& data=	T())
		:_next(nullptr),
		_data(data)
	{}
	ListNode<T>* _next;
	T _data;
};

namespace mylist
{
	template<class T>
	class List
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		List()
		{
			CreateHead();
		}
		~List()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void ListPushBack(const T& data= T())
		{
			PNode cur = _head;
			PNode NewNode = new Node(data);
			while (cur->_next)
			{
				cur = cur->_next;
			}
			cur->_next = NewNode;
			cur = NewNode;
		}
		void ListPopBack()
		{
			PNode cur = _head;
			PNode pre = _head;
			while (cur->_next)
			{
				pre = cur;
				cur = cur->_next;
			}
			pre->_next = cur->_next;
			if(cur!=_head)
				delete cur;
		}
		void ListPushFront(const T& data = T())
		{
			PNode NewNode =new  Node(data);
			NewNode->_next = _head->_next;
			_head->_next = NewNode;
		}
		void ListPopFront()
		{
			PNode Del = _head->_next;
			if (Del == nullptr)
				return;
			_head->_next = Del->_next;
			delete Del;
			
		}
		PNode ListFind(const T& data)
		{
			PNode cur = _head;
			while (cur->_next)
			{
				cur = cur->_next;
				if (cur->_data == data)
					return cur;
			}
			return nullptr;
		}
		void ListInsert(PNode _Node ,const T& data=T())
		{
			PNode cur = _head;
			PNode NewNode = new Node(data);
			while (cur->_next)
			{
				cur = cur->_next;
				if (cur == _Node)
				{	
					NewNode->_next = cur->_next;
					cur->_next = NewNode;
					return;
				}
			}
		}
		void ListErase(PNode _Node)
		{
			PNode cur = _head;
			PNode pre = _head;
			while (cur->_next)
			{
				pre = cur;
				cur = cur->_next;
				if (cur == _Node)
				{
					pre->_next = cur->_next;
					delete cur;
					return;
				}
			}
		}
		void ListReMoveAll(const T& data)
		{
			PNode cur = _head;
			PNode pre = _head;
			PNode Del = nullptr;
			while (cur->_next)
			{
				pre = cur;
				cur = cur->_next;
				if (cur->_data == data)
				{
					pre->_next = cur->_next;
					Del = cur;
					cur = pre;
					delete Del;
				}
			}
		}
		int ListSize() const
		{
			PNode cur = _head;
			int count = 0;
			while (cur->_next)
			{
				cur = cur->_next;
				count++;
			}
			return count;
		}
		int ListEmpty() const
		{
			return _head->_next == nullptr;
		}
		T ListFront() const
		{
			if (_head->_next)
				return _head->_next->_data;
			else
				return -1;
		}
		T ListBack() const
		{
			PNode cur = _head;
			while (cur->_next)
			{
				cur = cur->_next;
			}
			if (cur != _head)
				return cur->_data;
			else
				return  -1;
		}
		void Print()
		{
			PNode cur = _head;
			while (cur->_next)
			{
				cur = cur->_next;
				cout << cur->_data<<"->";
			}
			cout << "NULL"<<endl;
		}
		PNode Get_Head()
		{
			return _head->_next;
		}
			void headinsert(Node* tail, Node* head)
			{
				head->_next = tail->_next;
				tail->_next = head;
			}
		public:
			Node* swapPairs(Node* head)
			{
				if (!head || !head->_next)
					return head;
				Node* newhead = new Node(0);
				Node* tail = newhead;
				Node* head_next = nullptr;
				int count = 2;
				while (head)
				{
					head_next = head->_next;
					headinsert(tail, head);
					head = head_next;
					if (--count == 0)
					{
						tail = tail->_next->_next;
						count = 2;
					}

				}
				return newhead->_next;
			}
			Node* deleteDuplicates(Node* head)
			{
				Node* newhead = new Node(0);
				Node* tail = newhead;
				tail->_next = head;
				tail = head;
				Node* pre = head;
				Node* cur = head->_next;
				while (cur)
				{
					if (pre->_data != cur->_data)
					{
						tail->_next = cur;
						tail = cur;
						pre = cur;
					}
					cur = cur->_next;
				}
				tail->_next = nullptr;
				return newhead->_next;
			}
			Node* reverseBetween(Node* head, int m, int n)
			{
				if (head == nullptr)
					return head;
				Node* newhead = new Node(0);
				Node* tail = newhead;
				int count = 1;
				while (head)
				{
					if (count >= m && count <= n)
					{
						Node* head_next = head->_next;
						head->_next = tail->_next;
						tail->_next = head;
						head = head_next;
						if (count == n)
						{
							int k = n - m + 1;
							while (k--)
								tail = tail->_next;
						}
					}
					else
					{
						tail->_next = head;
						tail = head;
						head = head->_next;
					}
					count++;
				}
				return newhead->_next;
			}

			bool isPalindrome(Node* head)
			{
				if (head == nullptr)
					return true;
				Node* cur = head;
				int count = 0;
				while (cur)
				{
					count++;
					cur = cur->_next;
				}
				if (count % 2 != 0)
					count = count / 2 + 1;
				else
					count = count / 2;
				cur = head;
				while (count--)
					cur = cur->_next;
				while (cur)
				{
					if (cur->_data == head->_data)
					{
						cur = cur->_next;
						head = head->_next;
					}
					else
						return false;
				}
				return true;
			}
	Node* insertionSortList(Node* head)
    {
        if(!head)
            return nullptr;
		Node* NewNode=new Node(0);
        NewNode->_next=head;
        head=NewNode;
		Node* pre=head;
		Node* cur_pre=head->_next;
		Node* cur=cur_pre->_next;
        while(cur)
        {
           if(pre->_next ==cur)
            {
                cur_pre=cur;
                cur=cur->_next;
                pre=head;
            }
		   else if (cur->_data <= pre->_next->_data)
		   {
			   Node* cur_next = cur->_next;
			   cur_pre->_next = cur->_next;
			   cur->_next = pre->_next;
			   pre->_next = cur;
			   cur = cur_next;
			   pre = head;
		   }
            else
                pre=pre->_next;
        }
		swap(head->_next->_data, head->_next->_next->_data);
        return head->_next;
    }
	private:
		void clear()
		{
			PNode cur = _head->_next;
			PNode Del = _head->_next;
			while (cur)
			{
				_head->_next = cur->_next;
				Del = cur;
				cur = cur->_next;
				delete Del;
			}
		}
		void CreateHead()
		{
			_head = new Node;
		}
	private:
		PNode _head;
	};
}
template<class T>
class Solution {

public:

		typedef ListNode<T> Node;
	typedef Node* PNode;
	Node* Add_Node(Node* l1, Node* l2)
	{
		Node step = Node(0);
		Node* cur = nullptr;
		Node newhead = Node(0);
		Node* tail = &newhead;
		bool flag = false;
		while (l1 && l2)
		{
			int sum = 0;
			sum = l1->_data + l2->_data + step._data;
			step = Node(0);
			if (sum > 9)
			{
				step = Node(1);
				sum -= 10;
			}
			cur = new Node(sum);
			if (flag || cur->_data != 0)
			{
				tail->_next = cur;
				tail = cur;
				flag = true;
			}
			l1 = l1->_next;
			l2 = l2->_next;
		}
		while (l1)
		{
			if (step._data != 0)
			{
				int sum = l1->_data + step._data;
				step = Node(0);
				if (sum > 9)
				{
					step = Node(1);
					sum -= 10;
				}
				cur = new Node(sum);
			}
			else
				cur = l1;
			tail->_next = cur;
			tail = cur;
			l1 = l1->_next;
		}
		while (l2)
		{
			if (step._data != 0)
			{
				int sum = l2->_data + step._data;
				step = Node(0);
				if (sum > 9)
				{
					step = Node(1);
					sum -= 10;
				}
				cur = new Node(sum);
			}
			else
				cur = l2;
			tail->_next = cur;
			tail = cur;
			l2 = l2->_next;
		}
		if (step._data != 0)
		{
			tail->_next = &step;
			tail = &step;
		}
		return newhead._next;
	}
public:
	Node* addTwoNumbers(Node* l1, Node* l2)
	{
		if (!l1 && !l2)
			return nullptr;
		if (l1 && !l2)
			return l1;
		if (!l1 && l2)
			return l2;
		return Add_Node(l1, l2);
	}
};
#if 0
template<class T>
struct dListNode
{
	dListNode(const T& data=T())
		:_next(nullptr),
		_pre(nullptr),
		_data(data)
	{}
	dListNode<T>* _next;
	dListNode<T>* _pre;
	T _data;
};

namespace mydlist
{
	template <class T>
	class DList
	{
		typedef dListNode<T> Node;
		typedef Node* PNode;
	public:
		DList()
		{
			Createhead();
		}
		void DListPushBack(const T& data = T())
		{
			PNode NewNode = new Node(data);
			if (_head == nullptr)
			{
				_head = NewNode;
				_head->_next = _head;
				_head->_pre = _head;
			}
			else
			{
				PNode pre = _head->_pre;
				NewNode->_pre = pre;
				NewNode->_next = _head;
				pre->_next = NewNode;
				_head->_pre = NewNode;
			}
		}
		void DListPopBack()
		{
			if (_head == nullptr)
				return;
			else
			{
				PNode pre = _head->_pre;
				pre->_pre->_next = _head;
				_head->_pre = pre->_pre;
				if (pre == _head)
					_head = nullptr;
				delete pre;
			}
		}
		void DListPushFront(const T& data = T())
		{
			PNode NewNode = new Node(data);
			if (_head == nullptr)
			{
				_head = NewNode;
				_head->_next = _head;
				_head->_pre = _head;
				return;
			}
			else
			{
				NewNode->_next = _head;
				NewNode->_pre = _head->_pre;
				_head->_pre->_next = NewNode;
				_head->_pre = NewNode;
				_head = NewNode;
			}
		}
		void DListPopFront()
		{
			if (_head == nullptr)
				return;
			else
			{
				PNode pre = _head;
				pre->_pre->_next = _head->_next;
				_head->_next->_pre = pre->_pre;
				_head = _head->_next;
				if (pre == _head->_pre)
					_head = nullptr;
				delete pre;
			}
		}
		PNode Find(const T& data = T())
		{
			PNode cur = _head;
			while (cur->_next != _head)
			{
				if (cur->_data == data)
					return cur;
				cur = cur->_next;
			}
			if (cur->_data == data)
				return cur;
			return nullptr;
		}
		void DListInsert(PNode _Node,const T& data=T())
		{
			if (_Node == nullptr)
				return;
			PNode cur = _head;
			PNode NewNode = new Node(data);
			while (cur->_next != _head)
			{
				if (cur == _Node)
				{
					NewNode->_next = cur;
					NewNode->_pre = cur->_pre;
					cur->_pre->_next = NewNode;
					cur->_pre = NewNode;
					return;
				}
				cur = cur->_next;
			}
			if (cur == _Node)
			{
				NewNode->_next = cur;
				NewNode->_pre = cur->_pre;
				cur->_pre->_next = NewNode;
				cur->_pre = NewNode;
			}
		}
		void DListErase(PNode _Node)
		{
			if (_Node == nullptr)
				return;
			PNode cur = _head;
			while (cur->_next != _head)
			{
				if (cur == _Node)
				{
					cur->_pre->_next = cur->_next;
					cur->_next->_pre = cur->_pre;
					delete cur;
					return;
				}
				cur = cur->_next;
			}
			if (cur == _Node)
			{
				cur->_pre->_next = cur->_next;
				cur->_next->_pre = cur->_pre;
				delete cur;
			}
		}
		void Print()
		{
			PNode cur = _head;
			if (_head != nullptr)
			{
				while (cur->_next != _head)
				{
					cout << cur->_data << "->";
					cur = cur->_next;
				}
				cout << cur->_data << "->";
			}
			cout << "NULL" << endl;
		}
		~DList()
		{
			Clear();
		}
	private:
		void Createhead()
		{
			_head = nullptr;
		}
		void Clear()
		{
			if (_head == nullptr)
				return;
			else
			{
				PNode pre = _head;
				while (pre->_next!=_head)
				{
					pre = _head->_pre;
					pre->_pre->_next = _head;
					_head->_pre = pre->_pre;
					delete pre;
					pre = _head;
				}
				delete _head;
				_head = nullptr;
			}
		}
	private:
		PNode _head;
	};
}


template<class T>
struct ListNode
{
	ListNode(const T& data= T())
		:_pre(nullptr),
		_next(nullptr),
		_data(data)
	{}
	ListNode<T>* _pre;
	ListNode<T>* _next;
	T _data;
};

namespace mylist
{
	template<class T>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T> self;
		ListIterator(PNode pNode=nullptr)
			:_pNode(pNode)
		{}
		ListIterator(const self& s)
			:_pNode(s._pNode)
		{}
		T& operator*()
		{
			return _pNode->_data;
		}
		T* operator->()
		{
			return &(_pNode->_data);
		}
		self& operator++()
		{
			_pNode = _pNode->_next;
			return *this;
		}
		self& operator--()
		{
			_pNode = _pNode->_pre;
			return *this;
		}
		const self operator++(int)
		{
			self tmp(*this);
			_pNode = _pNode->_next;
			return tmp;
		}
		const self operator--(int)
		{
			self tmp(*this);
			_pNode = _pNode->_pre;
			return tmp;
		}
		bool operator!=(const self& s) const 
		{
			return _pNode != s->_pNode;
		}
		bool operator==(const self& s) const
		{
			return _pNode == s->_pNode;
		}
	private:
		PNode _pNode;
	};
	template<class T>
	class List {

	public:
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T> Iterator;
		List()
		{
			Create();
		}
		List(size_t n,const T& data=T())
		{
			Create();
			for (size_t i = 0; i < n; i++)
				this->Push_Back(data);
		}
		List(T* first, T* last)
		{
			Create();
			while (first != last)
			{
				this->Push_Back(*first);
				first++;
			}
		}
		List (const List<T>& list)
		{
			Create();
			PNode cur = list._head->_next;
			while (cur!= list._head)
			{
				this->Push_Back(cur->_data);
				cur = cur->_next;
			}
		}
		~List()
		{
			Clear();
			delete _head;
			_head = nullptr;
		}
		void Push_Back(const T& data = T())
		{
			PNode pre= _head->_pre;
			PNode NewNode =new  Node(data);
			NewNode->_next = _head;
			NewNode->_pre = pre;
			pre->_next = NewNode;
			_head->_pre = NewNode;
		}
		void Pop_Back()
		{
			if (_head->_next == _head)
				return;
			PNode pre = _head->_pre;
			pre->_pre->_next = _head;
			_head->_pre = pre->_pre;
			delete pre;
		}
		void Push_Front(const T& data = T())
		{
			PNode NewNode =new  Node(data);
			NewNode->_next = _head->_next;
			NewNode->_pre = _head;
			_head->_next->_pre = NewNode;
			_head->_next = NewNode;
		}
		void Pop_Front()
		{
			if (_head->_next == _head)
				return;
			PNode Del = _head->_next;
			_head->_next = Del->_next;
			Del->_next->_pre = _head;
			delete Del;
		}
		List<T>& operator=(const List<T>& l)
		{
			if (_head != l._head)
			{
				Clear();
				PNode cur = l._head->_next;
				while (cur!=l._head)
				{
					this->Push_Back(cur->_data);
					cur = cur->_next;
				}
			}
			return *this;
		}
		void assign(size_t n, const T& data )
		{
			Clear();
			for (size_t i = 0; i < n; i++)
			{
				this->Push_Back(data);
			}
		}
		void assign(T* first, T* last)
		{
			Clear();
			while (first < last)
			{
				this->Push_Back(*first);
				++first;
			}
		}
		int Empty() const 
		{
			return _head->_next == _head;
		}
		int Size() const 
		{
			int count = 0;
			PNode cur = _head->_next;
			while (cur != _head)
			{
				count ++;
				cur = cur->_next;
			}
			return count;
		}
		void resize(size_t n, T data = T())
		{
			if (Size() < n)
			{
				for(size_t i=Size();i<n;i++)
					this->Push_Back(data);
			}
			else
			{
				for (size_t i = n; i <Size(); i++)
				{
					this->Pop_Back();
				}
			}
		}
		T front()
		{
			if (_head->_next != _head)
				return _head->_next->_data;
		}
		T back()
		{
			if (_head->pre != _head)
				return _head->_pre->_data;
		}
		Iterator begin()
		{
			return Iterator(_head->_next);
		}
		Iterator end()
		{
			return Iterator(_head);
		}
		void Insert(Iterator pos, size_t n, const T& data)
		{

		}
		void swap(List<T>& list)
		{
			swap(_head, list._head);
		}
		void Print()
		{
			PNode cur = _head->_next;
			while (cur!= _head)
			{
				cout << cur->_data << "->";
				cur = cur->_next;
			}
			cout <<endl;
		}
	private:
		void Create()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_pre = _head;
		}
		void Clear()
		{
			PNode cur = _head->_next;
			while (_head != cur)
			{
				_head->_next = cur->_next;
				cur->_next->_pre = _head;
				delete cur;
				cur = _head->_next;
			}
		}
	private:
		PNode _head;
	};
}
#endif 