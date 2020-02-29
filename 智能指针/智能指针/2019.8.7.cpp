#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

#if 0
//������У���Ϊ����ָ��ֻ�ǹ���ָ�룬����ƾ�մ���ָ��
namespace myclass
{
	//C++98 auto_ptr: ��Դת��
	//C++��׼�⣺ʲô����¶���Ҫʹ��auto_ptr
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr( T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		auto_ptr(auto_ptr<T>& p)
		{
			if (_ptr)
				delete _ptr;
			_ptr = p._ptr;
			p._ptr = nullptr;
			
		}
		auto_ptr<T>& operator=(auto_ptr<T>& p)
		{
			if (this != &p)
			{
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = p._ptr;
				p._ptr = nullptr;
			}
			return *this;
		}
	private:
		T* _ptr;
	};
}
int main()
{
	myclass::auto_ptr<int> p1(new int);
	myclass::auto_ptr<int> p2(p1);
	*p1 = 10;
	myclass::auto_ptr<int> p3;
	p3 = p1;
	return 0;
}
#endif

#if 0
namespace myclass
{
	//auto_ptr�Ľ�����Դ����Ȩ��ת��
	//ȱ�㣺��Ȼ�Ľ���֮ǰ�Ĳ���ͬʱ����������������⣬���ǻ����Ұָ������
	//����������(�ھֲ��������ϴ���һ�������������ж�����¶�����п������죬
	//���ǳ���������֮�󣬾ͻ����Ұָ������)
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_owner(false)
		{
			if (_ptr)
			{
				_owner = true;
			}
		}
		~auto_ptr()
		{
			if (_ptr && _owner)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		auto_ptr(const auto_ptr<T>& p)
		{
			if (p._owner)
			{
				if (_ptr)
					delete _ptr;
				_ptr = p._ptr;
				_owner = p._owner;
				p._owner = false;
			}
		}
		auto_ptr<T>& operator=(const auto_ptr<T>& p)
		{
			if (this != &p && p._owner)
			{
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = p._ptr;
				_owner = p._owner;
				p._owner = false;
			}
			return *this;
		}
	private:
		T* _ptr;
		mutable bool _owner;
	};
}

int main()
{
	myclass::auto_ptr<int> p1(new int);
	myclass::auto_ptr<int> p2(p1);
	//*p1 = 10;
	if (true)
	{
		myclass::auto_ptr<int> p3(p2);
	}
	return 0;
}
#endif 
#if 0
namespace myclass
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		unique_ptr(const unique_ptr<T>& ptr);
		unique_ptr<T>& operator=(const unique_ptr<T>& ptr);
	private:
		 T* _ptr;
	};
}
int main()
{
	myclass::unique_ptr<int> p1=new int;
	myclass::unique_ptr<int> p2(p1);
	myclass::unique_ptr<int> p3;
	p3 = p1;
	return 0;
}
#endif

#if 0
//C++11 ��lambda
//����ɾ����
template<class T>
class DFDel
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};
template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

#include<mutex>
template<class T>
class FClose
{
public:
	void operator()(FILE* p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};
namespace myclass
{
	template<class T,class DF= DFDel<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_count(nullptr)
			,_pMutex(new int(1))
		{
			if (_ptr)
			{
				_count = new int(1);
			}
		}
		shared_ptr( shared_ptr<T>& p)
			:_ptr(p._ptr)
			,_count(p._count)
		{
			_pMutex->lock();
			if(_ptr)
				++(*_count);
			_pMutex->unlock();
		}
		//���������
		//sp1:δ������Դ---ֱ�ӹ���
		//sp1:����������Դ--���ͷ���Դ���ٽ��й���
		//sp1:����������ͬ������Դ--���ü����ȼ�һ���ٽ��й���
		shared_ptr<T>& operator=(shared_ptr<T>& p)
		{
			if (_ptr != p._ptr)
			{
				if (_ptr)
				{
					Release();
					AddLock();
				}
				else
				{
					AddLock();
				}
			}
			return *this;
		}
		~shared_ptr()
		{
			Release();
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
	private:
		void Release()
		{
			_pMutex->lock();
			if (_ptr && --(*_count) == 0)
			{
				//delete _ptr;
				//DF��һ������
				//DF():����һ����������
				DF()(_ptr);
				delete _count;
				_ptr = nullptr;
			}
			_pMutex->unlock();
		}

		void AddLock()
		{
			_pMutex->lock();
			_ptr = this->_ptr;
			_count = this->_count;
			(*_count)++;
			_pMutex->unlock();
		}
	private:
		T* _ptr;
		int* _count;
		mutex* _pMutex;
	};
}

void TestFunc()
{
	myclass::shared_ptr<int,Free<int>> p5((int*)malloc(sizeof(int)));
	myclass::shared_ptr<FILE,FClose<FILE>> p6(fopen("666.txt","rb"));
	myclass::shared_ptr<int> p7(new int);
	//myclass::shared_ptr<int> p7(new int[10]);
	//����ָ�벻��ȥ���������Ŀռ䣬��׼������vector
}
int main()
{
	//TestFunc();
	myclass::shared_ptr<int> p1(new int);  //p1 1
	myclass::shared_ptr<int> p2(new int);  //p2 1
	myclass::shared_ptr<int> p3(new int);  //p3 1
	myclass::shared_ptr<int> p4(p1);  //p1  2
	p1 = p3;  //p1 1   p3  2
	p2 = p1;  //p1 2   p2  0
	p3 = p1;  //p1 3   p3  1
	return 0;
}
#endif 

#include<memory>
#include<cstdlib>
//shared_ptr: ѭ����������
struct ListNode
{
	ListNode(int data=int())
		:_data(data)
		//:pre(nullptr)
		//, next(nullptr)
		//,_data(data)
	{	
		cout << "ListNode():" << this << endl;
	}
	~ListNode()
	{
		cout << "~ListNode():" << this << endl;
	}
	//ListNode* _pPre;
	//ListNode* _pNext;
	shared_ptr<ListNode> pre;
	shared_ptr<ListNode> next;
	int _data;
};
void TestFunc()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->next = sp2;
	sp2->pre = sp1;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}
int main()
{
	TestFunc();
	system("pause");
	return 0;
}

//weak_ptr�����������ü�����