#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdlib.h>
#if 0
int main()
{
	int* p = new int;
	*p = 20;
	int* pt = new int(10);
	int* p1 = new int[10];
	int* p1t = new int[3]{ 1,2,3 };

	delete p;
	p = nullptr;
	delete p;
	delete pt;
	delete[] p1;
	delete[] p1t;
	system("pause");
	return 0;

}
#endif 

#if 0
class Date
{
public:
	Date(int day=1)
		:_day(day)
	{
		cout << "Date():"<<this << endl;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _day;
};
int main()
{
	//Date* d1 = new Date;
	//Date* d2 = new Date(10);
	//delete d1;
	//delete d2;
	//Date* d3 = new Date[10];
	//delete[] d3;
	Date* d4 = (Date*)malloc(sizeof(Date));
	new(d4) Date(30);
	int arr[10];
	arr[2] = 5;
	new(arr+2) int(2);
	delete d4;
	system("pause");
	return 0;
}
#endif

#if 0
class Heaponly 
{
public:
	Heaponly(int a)
	{
		day = a;
	}
	void Destroy()
	{
		delete this;
	}
private:
	~Heaponly()
	{
	}
	int day;
};
int main()
{
	//Heaponly h(10);
	Heaponly* ph = new Heaponly(10);
	ph->Destroy();
	system("pause");
	return 0;
}
#endif

#if 0
class Heaponly
{
	~Heaponly()
	{
	}
	static Heaponly* GetHeaponly(int data=10)
	{
		Heaponly* p = new Heaponly;
		p->_data = data;
		return p;
	}
private:
	Heaponly(int data=10)
	{
	}
	Heaponly(const Heaponly& d);
	int _data;
};
int main()
{
	Heaponly* ph = 
	system("pause");
	return 0;
}
#endif


class Singleton
{
public:
	static Singleton* GetSingleton()
	{
		return &s_once;
	}
	friend ostream& operator<<(ostream& _cout,  Singleton& s);
private:
	Singleton(int data)
		:_data(data)
	{

	}
	~Singleton()
	{}
	Singleton(const Singleton& s);
	Singleton& operator=(const Singleton& s);
	int _data;
	static Singleton s_once;
};
Singleton Singleton::s_once(1);
ostream& operator<<(ostream& _cout, Singleton& s)
{
	_cout << s._data;
	return _cout;
}
int main()
{
	cout << *Singleton::GetSingleton() << endl;
	system("pause");
	return 0;
}