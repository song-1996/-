#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<vector>
#include"search_prime.h"
using namespace std;

enum State
{
	EMPTY,
	EXIST,
	DELETE
};
template<class T>
class HashTable
{
public:
	struct Elem
	{
		T _data;
		State _state;
	};
	HashTable(size_t capacity=GetNextPrime(1))
		:_ht(capacity)
		,_size(0)
	{
		for (size_t i = 0; i < capacity; i++)
		{
			_ht[i]._state = EMPTY;
		}
	}
	bool Insert(const T& data)
	{
		Check_Capacity();
		size_t pos=HashFunc(data);
		while (_ht[pos]._state != EMPTY)
		{
			if (_ht[pos]._data == data)
				return false;
			pos++;
			if (pos == _ht.capacity())
				pos = 0;
		}
		_ht[pos]._data = data;
		_ht[pos]._state=EXIST;
		_size++;
		return true;

	}
	size_t Find(const T& data)
	{
		size_t pos = HashFunc(data);
		while (_ht[pos]._state != EMPTY )
		{
			if (_ht[pos]._state == EXIST && _ht[pos]._data == data)
				return pos;
			pos++;
		}
		return -1;
	}
	bool Erase(const T& data)
	{
		size_t pos=Find(data);
		if (pos == (size_t)-1)
			return false;
		_ht[pos]._state = DELETE;
		_size--;
		return true;
	}
	size_t Size()
	{
		return _size;
	}
	bool Empty()
	{
		return _size == 0;
	}
	void Swap(HashTable<T>& ht)
	{
		swap(_ht, ht._ht);
		swap(_size, ht._size);
	}
	void Check_Capacity()
	{
		if ((_size * 10) / _ht.capacity() > 7)
		{
			HashTable<T>  newht(GetNextPrime(_ht.capacity()));
			for (int i = 0; i < (int)_ht.capacity(); i++)
			{
				if (_ht[i]._state == EXIST)
					newht.Insert(_ht[i]._data);
			}
			Swap(newht);
		}
	}
	void Print()
	{
		int i = 0;
		while (i<(int)_ht.capacity())
		{
			if (_ht[i]._state == EXIST)
				cout << _ht[i]._data << ' ';
			i++;
		}
		cout << endl;
	}
private:
	size_t HashFunc(const T& data)
	{
		return data % _ht.capacity();
	}
private:
	vector<Elem> _ht;
	size_t _size;
};