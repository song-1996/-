#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
template<class T>
struct Node
{
	Node(const T& data)
		:_next(nullptr)
		, _data(data)
	{}
	Node<T>* _next;
	T _data;
};
template<class T>
class HashBucket
{
public:
	typedef Node<T> Node;
	typedef Node* PNode;
	HashBucket(size_t capacity = 10)
		:_ht(capacity)
		, _size(0)
	{}
	bool Insert(const T& data)
	{
		size_t pos = HashFunc(data);
		PNode NewNode = new Node(data);
		PNode cur = _ht[pos];
		while (cur)
		{
			if (cur->_data == data)
				return false;
			cur = cur->_next;
		}
			NewNode->_next = _ht[pos];
			_ht[pos] = NewNode;
			_size++;
		return true;
	}
	bool Find(const T& data)
	{
		size_t pos = HashFunc(data);
		PNode cur = _ht[pos];
		while (cur)
		{
			if (cur->_data == data)
				return true;
			cur = cur->_next;
		}
		return false;
	}
	bool Erase(const T& data)
	{
		size_t pos = HashFunc(data);
		PNode cur = _ht[pos];
		PNode pre = nullptr;
			while (cur)
			{
				if (cur->_data == data)
				{
					if (pre == nullptr)
						_ht[pos] = cur->_next;
					else
						pre->_next = cur->_next;
					delete cur;
					_size--;
					return true;
				}
				pre = cur;
				cur = cur->_next;
			}
			return false;
	}
	size_t Size()
	{
		return _size;
	}
	size_t Bucket_Count()
	{
		size_t count = 0;
		for (int i = 0; i < (int)_ht.capacity(); i++)
		{
			if (_ht[i] != nullptr)
				count++;
		}
		return count;
	}
	void Swap(HashBucket<T>& ht)
	{
		swap(_ht, ht._ht);
		swap(_size, ht._size);
	}
	void clear()
	{
		for (size_t i = 0; i < _ht.capacity(); i++)
		{
			PNode cur = _ht[i];
			PNode del = nullptr;
			while (cur)
			{
				del = cur;
				cur = cur->_next;
				delete del;
			}
			_ht[i] = nullptr;
		}
		_size = 0;
	}
	~HashBucket()
	{
		clear();
	}
private:
	size_t HashFunc(const T& data)
	{
		return data % _ht.capacity();
	}
private:
	vector<PNode> _ht;
	size_t _size;
};