#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;

template<class T>
class Seqlist
{
public:
	Seqlist(int capacity = 5);
	~Seqlist();
	void CheckCapacity();
	void PushBack(T data);
	void PopBack();
	void PushFront(T data);
	void PopFront();
	void SeqlistInsert(size_t pos,T data);
	void SeqlistErase(size_t pos);
	int SeqlistFind(T data);
	void Remove(T data);
	void RemoveAll(T data);
	size_t Size();
	size_t Capacity();
	int Empty();
	T& Front() const;
	T& Back() const;
	T& operator[](size_t pos) const;
	void Print();
private:
	T* _array;
	size_t _capacity;
	int _size;

};
#include"Seqlist.template"