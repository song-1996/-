#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<assert.h>
using namespace std;

namespace myvector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector()
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{}
		vector(size_t n,const T& data)
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			start = new T[n];
			for (size_t i = 0; i < n; i++)
			{
				start[i] = data;
			}
			finish = start + n;
			end_of_storage = finish;
		}
		vector(iterator first,iterator last)
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			int sz = last - first;
			start = new T[sz];
			int i = 0;
			while(first<last)
			{
				start[i++] = *first;
				first++;
			}
			finish = start + sz;
			end_of_storage = finish;
		}
		vector(const vector<T>& v)
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			int sz = v.finish - v.start;
			T* ptr = new T[sz];
			memcpy(ptr, v.start, sizeof(T)*sz);
			delete[] start;
			start = ptr;
			ptr = nullptr;
			finish = start + sz;
			end_of_storage = finish;
		}
		~vector()
		{
			if (start)
			{
				delete[] start;
				start = nullptr;
				finish = nullptr;
				end_of_storage = nullptr;
			}
		}
		vector<T>& operator=(const vector<T>& v)
		{
			if (start != v.start)
			{
				int sz = v.finish - v.start;
				T* ptr = new T[sz];
				memcpy(ptr, v.start, sizeof(T)*sz);
				delete[] start;
				start = ptr;
				ptr = nullptr;
				finish = start + sz;
				end_of_storage = finish;
			}
			return  *this;
		}
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
		int size()
		{
			return finish - start;
		}
		size_t capacity()
		{
			return end_of_storage - start;
		}
		bool empty()
		{
			return start == finish;
		}
		void reserve(size_t newcapacity)
		{
			size_t sz = finish - start;
			if (capacity() < newcapacity)
			{
				T* ptr = new T[newcapacity];
				if (start)
				{
					memcpy(ptr, start, sizeof(T)*sz);
					delete[] start;
					start = ptr;
					finish = start + sz;
					end_of_storage = start + newcapacity;
				}
			}
		}
		void resize(size_t n,const T& data=T())
		{
			size_t oldsize = finish - start;
			if (n > oldsize)
			{
				if (oldsize + n >= capacity())
				{
					reserve(n + oldsize);
				}
				size_t i = 0;
				while (i < n)
				{
					start[oldsize++] = data;
					i++;
				}
				finish = start + oldsize;
			}
			else
			{
				finish = start + n;
			}
		}
		T& operator[](size_t pos)
		{
			size_t sz = finish - start;
			assert(pos < sz);
				return start[pos];
		}
		const T& operator[](size_t pos) const 
		{
			size_t sz = finish - start;
			assert(pos < sz);
			return start[pos];
		}
		T& front()
		{
			return start[0];
		}
		T& back()
		{
			return start[finish - start-1];
		}
		void assign(iterator first, iterator last)
		{
			size_t len = last - first;
			size_t sz = finish - start;
			size_t capacity = end_of_storage - start;
			if (len + sz > capacity)
				reserve(len + capacity);
			for (size_t i = 0; i < len; i++)
			{
				start[sz++] = *first;
				first++;
			}
			finish = finish + len;
		}
		void assign(size_t n, const T& data)
		{
			size_t sz = finish - start;
			size_t capacity = end_of_storage - start;
			if (n + sz > capacity)
				reserve(n + capacity);
			for (size_t i = 0; i < n; i++)
			{
				start[sz++] = data;
			}
			finish = finish + n;
		}
		void push_back(const T& data)
		{
			size_t sz = finish - start;
			size_t capacity = end_of_storage - start;
			if (1 + sz > capacity)
				reserve(capacity * 2);
			start[sz++] = data;
			finish = finish + 1;
		}
		void pop_back()
		{
			size_t sz = finish - start;
			if (sz)
			{
				sz--;
				finish = start + sz;
			}

		}
		iterator insert(iterator pos, const T& x)
 		{
			assert((pos >= start) && (pos <= finish));
			int  sz = pos - start;
			if (capacity() < size() + (size_t)1)
			{
				reserve(2 * capacity());
				pos = start + sz;
			}
			for (int i = size()-1; i>=sz; i--)
			{
				start[i+1] = start[i];
			}
			*pos = x;
			finish++;
			return pos;
		}
		void insert(iterator pos, size_t n, const T& x)
		{
			assert((pos >= start) && (pos <= finish));
			size_t capacity = end_of_storage - start;
			size_t  sz= pos - start;
			if (capacity < (size() + n))
			{
				reserve(n+ capacity);
				pos = start + sz;
			}
			iterator fc = finish;
			while (pos <= fc)
			{
				*(fc + n) = *fc;
				fc--;
			}
			size_t curn = 0;
			while (curn < n)
			{
				*pos = x;
				pos++;
				curn++;
			}
			finish=finish + n;
		}
		void Print()
		{
			auto it = begin();
			for (; it < end(); it++)
			{
				cout << *it << ' ';
			}
			cout << endl;
		}
	private:
		T* start;
		T* finish;
		T* end_of_storage;
	};
}
int main()
{
	myvector::vector<int> v1;
	v1.Print();
	myvector::vector<int> v2(3, 2);
	v2.Print();
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	myvector::vector<int> v3(arr, arr + 10);
	v3.Print();
	myvector::vector<int> v4(v2);
	v4.Print();
	for(int i=0;i<10;i++)
	v2.insert(v2.begin(), 500);
	v2.Print();
	system("pause");
	return 0;

}