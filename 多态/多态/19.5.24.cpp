#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#if 0
//普通人
class Person
{
public:
	virtual void BuyTicket(int a=0)
	{
		cout << "全价票" <<a<< endl;
	}
	virtual void func()
	{
		BuyTicket();
	}
	virtual ~Person()
	{
		cout << "~Person" << endl;
	}
private:
	string _name;
	string _age;
	int _gender;
};
class Student : public Person
{
public:
	void BuyTicket(int a=1)
	{
		cout << "半价票" <<a<< endl;
	}
	 ~Student()
	{
		 cout << "~Student" << endl;
	}
};
void SellTicket(Person& p)
{
	p.func();
}
int main()
{
	//Person p;
	//Student s;
	//SellTicket(p);
	//SellTicket(s);
	//cout << sizeof(s) << endl;
	Person* p = new Person;
	p->BuyTicket();
	delete p;
	p = new Student;
	p->BuyTicket();
	delete p;
	system("pause");
	return 0;

}
#endif 
#if 0
class WC
{
public:
	void GotoManWc()
	{
		cout << "男" << endl;
	}
	void GotoWomanWc()
	{
		cout << "女" << endl;
	}
};
//抽象类
class Person
{
public:
	//纯虚函数
	virtual void GotoWc(WC& wc) = 0;
};
class Man : public Person
{
public:
	virtual  void GotoWc(WC& wc)
	{
		wc.GotoManWc();
	}
};
class Woman : public Person
{
public:
	virtual void GotoWc(WC& wc)
	{

		wc.GotoWomanWc();
	}
};
#include<windows.h>
void TestFunc()
{
	//Person p;
	WC wc;
	Person* p = nullptr;
	for (int i = 0; i < 10; i++)
	{
		if (rand() % 2 == 0)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}
		p->GotoWc(wc);
		Sleep(1000);
		delete p;
	}

}
int main()
{
	TestFunc();
	return 0;
}
#endif 

//class Base
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "Base::TesrFunc1()" << endl;
//	}
//	virtual void TestFunc2()
//	{
//		cout << "Base::TesrFunc2()" << endl;
//	}
//	virtual void TestFunc3()
//	{
//		cout << "Base::TesrFunc3()" << endl;
//	}
//	int _b;
//};
//class Derived : public Base
//{
//public:
//	virtual void TestFunc5()
//	{
//		cout << "Derived::TestFunc5()" << endl;
//	}
//	virtual void TestFunc1()
//	{
//		cout << "Derived::TestFunc1()" << endl;
//	}
//	virtual void TestFunc3()
//	{
//		cout << "Derived::TestFunc3()" << endl;
//	}
//	virtual void TestFunc4()
//	{
//		cout << "Derived::TestFunc4()" << endl;
//	}
//	int _d;
//};
//typedef void(*PVF)();
//void Print(const Base& b, const string& s)
//{
//	PVF* pvf = (PVF*)*(int*)&b;
//	while (*pvf)
//	{
//		cout << s << ":";
//		(*pvf)();
//		pvf++;
//		cout <<endl;
//	}
//	
//
//}
//int main()
//{
//	Base b;
//	Derived d;
//	d._b = 1;
//	d._d = 2;
//	//cout << sizeof(d) << endl;
//	Print(d, "Derived");
//	return 0;
//}

//class Base
//{
//public :
//	virtual void Print1()
//	{
//		cout << "Base::Print1()" << endl;
//	}
//	virtual void Print2()
//	{
//		cout << "Base::Print2()" << endl;
//	}
//	virtual void Print3()
//	{
//		cout << "Base::Print3()" << endl;
//	}
//	int _b;
//};
//
//class Derived : public Base
//{
//public:
//	virtual void Print1()
//	{
//		cout << "Derived::Print1()" << endl;
//	}
//	virtual void Print3()
//	{
//		cout << "Derived::Print3()" << endl;
//	}
//	int _d;
//};
//void TestVirFunc(Base& b)
//{
//	b.Print1();
//	b.Print2();
//	b.Print3();
//}
//int main()
//{
//	Base b;
//	Derived d;
//	d._b = 1;
//	d._d = 2;
//	cout << sizeof(b) << endl;
//	TestVirFunc(b);
//	TestVirFunc(d);
//	return 0;
//}

#if 0
class B
{
public:
	virtual void Print1()
	{
		cout << "B::Print1()" << endl;
	}
	virtual void Print2()
	{
		cout << "B::Print2()" << endl;
	}
	int _b;
};
class C1 : public B
{
public:
	virtual void Print1()
	{
		cout << "C1::Print1()" << endl;
	}
	virtual void Print3()
	{
		cout << "C1::Print3()" << endl;
	}
	int _c1;
};
class C2:public B
{
public:
	virtual void Print1()
	{
		cout << "C2::Print1()" << endl;
	}
	virtual void Print3()
	{
		cout << "C2::Print3()" << endl;
	}
	int _c2;
};
class D:public C1,public C2
{
public:
	virtual void Print1()
	{
		cout << "D::Print1()" << endl;
	}
	virtual void Print4()
	{
		cout << "D::Print4()" << endl;
	}
	int _d;
};
void TestVPF(C2& c)
{
	c.Print1();
	c.Print2();
	c.Print3();
}
int main()
{
	D d;
	d.C1::_b = 0;
	d.C2::_b = 1;
	d._c1 = 2;
	d._c2 = 3; 
	d._d = 4;
	TestVPF(d);
	return 0;
}
#endif 

#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
	int _b;
};
class Derived : public Base
{
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}
};
int main()
{

	cout << sizeof(Derived) << endl;
	Base b;
	Derived d;
	//d.TestFunc1();不能访问私有成员函数
	Base* pb = &d;
	pb->TestFunc1();



	//cout << sizeof(Base) << endl;//成员函数设成虚函数之后多了4个字节
	//Base b;
	//b._b = 1;
	return 0;
}
#endif 
//
//class Base
//{
//public:
//	virtual void TestFunc1()
//	{
//		cout << "Base::TestFunc1()" << endl;
//	}
//	int _b;
//};
//class Derived : public Base
//{
//	virtual void TestFunc3()
//	{
//		cout << " Derived::TestFunc3()" << endl;
//	}
//	virtual void TestFunc1()
//	{
//		cout << " Derived::TestFunc1()" << endl;
//	}
//public:
//	int _d;
//};
//int main()
//{
//	Base b;
//	Derived d;
//	b._b = 1;
//	d._d = 2;
//	return 0;
//}

#if 0
class Base
{
public:
	 void TestFunc0()
	{
		cout << "Base::TesrFunc0()" << endl;
	}
	virtual void TestFunc1()
	{
		cout << "Base::TesrFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TesrFunc2()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Base::TesrFunc3()" << endl;
	}
	int _b;
};
class Derived : public Base
{
public:
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}
	int _d;
};
void TestVirtualFunc(Base& b)
{
	b.TestFunc0();
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}
int main()
{
	Base b;
	Derived d;
	TestVirtualFunc(b);
	TestVirtualFunc(d);
	Base* pb = (Base*)new Derived();
	pb->TestFunc1();
	return 0;
}
#endif 

//int main()
//{
//	int a = 10;
//	const int*  pa = &a;
//	cout << *pa << endl;
//	a= 20;
//	cout << *pa << endl;
//}


#if 0
class Base1
{
public:
	virtual void TestFunc1()
	{
		cout << "Base1::TesrFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base1::TesrFunc2()" << endl;
	}
	int _b1;
};
class Base2
{
public:
	virtual void TestFunc3()
	{
		cout << "Base2::TesrFunc3()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Base2::TesrFunc4()" << endl;
	}
	int _b2;
};
class Derived : public Base1,public Base2
{
public:
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}
	virtual void TestFunc6()
	{
		cout << "Derived::TestFunc6()" << endl;
	}
	int _d;
};
void TestVirtualFunc(Base1& b)
{
	b.TestFunc1();
	b.TestFunc2();
}

typedef void(*PVF)();
void Print(const Base2& b, const string& s)
{
	PVF* pvf = (PVF*)*(int*)&b;
	while (*pvf)
	{
		cout << s << ":";
		(*pvf)();
		pvf++;
		cout <<endl;
	}
}
int main()
{
	Base1 b;
	Derived d;
	TestVirtualFunc(b);
	TestVirtualFunc(d);
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	Print(d, "Derived");
	//cout << sizeof(d) << endl;
	return 0;
}
#endif 

class B
{
public:
	virtual void TestFunc1()
	{
		cout << "B::TesrFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "B::TesrFunc2()" << endl;
	}
	int _b;
};
class C1 : virtual public B
{
public:
	virtual void TestFunc1()
	{
		cout << "C1::TesrFunc1()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "C1::TesrFunc3()" << endl;
	}
	int _c1;
};
class C2 : virtual public B
{
public:
	virtual void TestFunc4()
	{
		cout << "C2::TesrFunc4()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "C2::TesrFunc2()" << endl;
	}
	int _c2;
};
class D : public C1, public C2
{
public:
	virtual void TestFunc6()
	{
		cout << "D::TesrFunc6()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "D::TesrFunc2()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "D::TesrFunc4()" << endl;
	}
	virtual void TestFunc5()
	{
		cout << "D::TesrFunc5()" << endl;
	}
	int _d;
};

void TestVirtualFunc(B& b)
{
	b.TestFunc1();
	b.TestFunc2();
}

typedef void(*PVF)();
void Print(const B& c, const string& s)
{
	//18 fd ba 00
	PVF* pvf = (PVF*)*(int*)&c;
	while (*pvf)
	{
		cout << s << ":";
		(*pvf)();
		pvf++;
		cout << endl;
	}
}
int main()
{

	D d;
	C1 c;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;
	Print(d, "C1");
	cout << sizeof(d) << endl;
	return 0;
}