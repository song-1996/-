#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#if 0
//一：将构造函数设为私有的
class HeapOnly
{
public:
	static HeapOnly* Getobject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(const HeapOnly& h);
	//C++11
	//HeapOnly(const HeapOnly& h) = delete；
private:
	HeapOnly()
	{}
};
int main()
{
	HeapOnly* h = HeapOnly::Getobject();
	system("pause");
	return 0;

}
#endif 

#if 0
//一：将构造函数设为私有的
class StackOnly
{
public:
	static StackOnly Getobject()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
};
//二.将operator new设为私有的
//缺陷：不能禁止在全局作用域创建
class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

StackOnly s;
int main()
{
	//StackOnly s=StackOnly::Getobject();
	StackOnly s;
	StackOnly *ps = new StackOnly;
	return 0;
}
#endif

#if 0
//饿汉模式
//程序启动时将对象创建好
class Singleton
{
public:
	static Singleton& GetInstrance()
	{
		return m_ins;
	}

private:
	Singleton()
	{}
	Singleton(const Singleton&)
	{}
	static Singleton m_ins;
};
Singleton Singleton::m_ins;
//懒汉模式
//第一次使用时创建，延迟加载
#include<mutex>
class Singleton
{
public:
	//加volatile的原因
	//编译器有可能会优化代码，禁止编译器对代码指令重排
	//优化前：1.申请空间 2.调用构造函数 3.赋值
	//优化后：1.申请空间 2.赋值 3.调用构造函数
	//线程1和线程2，线程1先进去，会先赋值，赋值完之后，如果线程1的时间片到了
	//线程1就会被下去，线程2来了，发现m_pins不为空，就不创建对象了。
	static volatile Singleton* GetInstrance()
	{
		//防止阻塞
		if (nullptr == m_pins)
		{
			//1.加锁可能会导致线程全部阻塞住
			//2.在new的时候可能会抛异常，导致没有解锁，就死锁了。
			m_mutex.lock();
			if (nullptr == m_pins)
				m_pins = new Singleton;
			m_mutex.unlock();
		}
		return m_pins;
	}
	class GC
	{
	public:
		~GC()
		{
			if (m_pins)
			{
				delete m_pins;
				m_pins = nullptr;
			}
		}
	};
private:
	Singleton();
	Singleton(const Singleton&);
	static volatile Singleton* m_pins;
	static mutex m_mutex;
	static GC m_gc;
};
volatile Singleton* Singleton::m_pins=nullptr;
mutex Singleton::m_mutex;
Singleton::GC m_gc;
int main()
{
	volatile Singleton* s=Singleton::GetInstrance();
	return 0;
}
#endif

#if 0
//模板初阶
//C++中class可以用在模板参数列表，struct不行
template<class T>//template<typename T>
T Add(T left, T right)
{
	//看一个变量的类型typeid
	cout << typeid(left).name() << endl;
	return left + right;
}
int main()
{
	//隐式实例化
	cout << Add(1, 2) << endl;//在编译代码期间，必须推演实参的
								//类型来确定模板参数列表中的T，
								//根据确定的T来生成对应类型的代码。
	cout << Add(1.2, 3.2) << endl;
	//cout << Add(1.2, 3) << endl;//模板不会进行隐式转换
	cout << Add(1.2, (double)3) << endl;

	//显示实例化：明确指定T的类型double
	//尝试进行隐式类型转换，如果成功，则生成代码
	//失败则报错
	cout << Add<double>(1.2, 3) << endl;
	return 0;
}
#endif 

#if 0
template<class T>
T Add(T left, T right)
{
	return left + right;
}
int Add(int left, int right)
{
	return left + right;
}
int main()
{
	Add(1, 2);
	Add<>(1, 2);//隐式类型实例化Add<int>(1,2);
	return 0;
}
#endif 

#if 0
template<class T1,class T2>
T2 Add(T1 left, T2 right)
{
	return left + right;
}
int Add(int left, int right)
{
	return left + right;
}
int main()
{
	Add(1, 2);
	Add(1, 2.0);//不进行隐式转换，因为模板可以生成更符合的函数
	return 0;
}
#endif 

#include<crtdbg.h>
#ifdef _DEBUG
#define new  new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
int main()
{
	int *p = new int[20];
	_CrtDumpMemoryLeaks();
	return 0;
}