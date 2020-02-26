#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#if 0
//һ�������캯����Ϊ˽�е�
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
	//HeapOnly(const HeapOnly& h) = delete��
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
//һ�������캯����Ϊ˽�е�
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
//��.��operator new��Ϊ˽�е�
//ȱ�ݣ����ܽ�ֹ��ȫ�������򴴽�
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
//����ģʽ
//��������ʱ�����󴴽���
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
//����ģʽ
//��һ��ʹ��ʱ�������ӳټ���
#include<mutex>
class Singleton
{
public:
	//��volatile��ԭ��
	//�������п��ܻ��Ż����룬��ֹ�������Դ���ָ������
	//�Ż�ǰ��1.����ռ� 2.���ù��캯�� 3.��ֵ
	//�Ż���1.����ռ� 2.��ֵ 3.���ù��캯��
	//�߳�1���߳�2���߳�1�Ƚ�ȥ�����ȸ�ֵ����ֵ��֮������߳�1��ʱ��Ƭ����
	//�߳�1�ͻᱻ��ȥ���߳�2���ˣ�����m_pins��Ϊ�գ��Ͳ����������ˡ�
	static volatile Singleton* GetInstrance()
	{
		//��ֹ����
		if (nullptr == m_pins)
		{
			//1.�������ܻᵼ���߳�ȫ������ס
			//2.��new��ʱ����ܻ����쳣������û�н������������ˡ�
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
//ģ�����
//C++��class��������ģ������б�struct����
template<class T>//template<typename T>
T Add(T left, T right)
{
	//��һ������������typeid
	cout << typeid(left).name() << endl;
	return left + right;
}
int main()
{
	//��ʽʵ����
	cout << Add(1, 2) << endl;//�ڱ�������ڼ䣬��������ʵ�ε�
								//������ȷ��ģ������б��е�T��
								//����ȷ����T�����ɶ�Ӧ���͵Ĵ��롣
	cout << Add(1.2, 3.2) << endl;
	//cout << Add(1.2, 3) << endl;//ģ�岻�������ʽת��
	cout << Add(1.2, (double)3) << endl;

	//��ʾʵ��������ȷָ��T������double
	//���Խ�����ʽ����ת��������ɹ��������ɴ���
	//ʧ���򱨴�
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
	Add<>(1, 2);//��ʽ����ʵ����Add<int>(1,2);
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
	Add(1, 2.0);//��������ʽת������Ϊģ��������ɸ����ϵĺ���
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