#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
#if 0
class Person
{
public:
	void Print()
	{
		cout << "_age" << _age<< endl;
	}
private:
	int _age;
};

class Stu : public Person
{
public:
	void Print()
	{
		cout << "_stuid" << _stuid << endl;
	}
private:
	int _stuid;
};

class Tea : public Person
{
public:
	void Print()
	{
		cout << "_teaid" << _teaid << endl;
	}
private:
	int _teaid;
};
int main()
{
	cout << sizeof(Person) << endl;
	cout << sizeof(Stu) << endl;
	cout << sizeof(Tea) << endl;
	system("pause");
	return 0;

}
#endif 

#if 0
class Person
{
public:
	void Print()
	{
		cout << "_age" << _age << endl;
	}
public:
	int pub;
protected:
	int pro;
private:
	int _age;
};

class Stu : public Person
{
public:
	void Print()
	{
		pub = 10;
		pro = 10;
		_age = 10;
		cout << "_stuid" << _stuid << endl;
	}
private:
	int _stuid;
};

class Tea : public Person
{
public:
	void Print()
	{
		
		cout << "_teaid" << _teaid << endl;
	}
private:
	int _teaid;
};
int main()
{
	cout << sizeof(Person) << endl;
	cout << sizeof(Stu) << endl;
	cout << sizeof(Tea) << endl;
	system("pause");
	return 0;

}
#endif 


#if 0 
class source
{
public:
	source(int pri)
		:_pri(pri)
	{}
	void Print()
	{
		cout << "source" << endl;
	}
private:
	int _pri;
};

class derive :public source
{
public:
	derive(int pri,int d)
		:source(pri)
		,_d(d)
	{}
	void Print()
	{
		cout << "derive" << endl;
	}
public:
	int _d;
};


int main()
{
	derive d(20,30);
	source s(10);
	s = d;
	source* ps=&d;
	*ps = d;
	source& s1 = s;
	s1 = d;
	return 0;
}
#endif 

#if 0
class Person
{
public:
	Person(const string& name="",int age=0)
		:_name(name)
		,_age(age)
	{}
	void PrintPerson()
	{
		cout << "_name:" << _name << endl;
		cout << "_age:" << _age << endl;
	}
private:
	string _name;
	int _age;
	string _gender;
};
class Student : public Person
{
public:
	void Work()
	{
		cout << "study" << endl;
	}
private:
	string _stuID;
};
int main()
{
	Student s;
	s.PrintPerson();
	return 0;
}
#endif 

#if 0
class Base
{
public:
	void SetBaseInfo(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void PrintBaseInfo()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class  Derived : public Base
{
public:
	void PrintDerivedInfo(int pub,int pro,int pri)
	{
		//从基类继承下来的成员变量赋值
		_pub = pub;
		_pro = pro;
		//_pri = pri;
		//子类新增加的成员变量赋值
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D :public Derived
{
	void TestFunc()
	{
		_pro = 20;
	}
};

int main()
{
	Derived d;
	d._pub = 10;
	//d._pro = 20;
	return 0;
}
#endif 

#if 0
class Base
{
public:
	void SetBaseInfo(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void PrintBaseInfo()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class  Derived : protected  Base
{
public:
	void PrintDerivedInfo(int pub, int pro, int pri)
	{
		//从基类继承下来的成员变量赋值
		_pub = pub;
		_pro = pro;
		//_pri = pri;
		//子类新增加的成员变量赋值
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D :public Derived
{
	void TestFunc()
	{
		_pub = 10;
		_pro = 20;
		//_pri = 20;
	}
};

int main()
{
	Derived d;
	//d._pub = 10;
	//d._pro = 20;
	return 0;
}
#endif 

#if 0 
class Base
{
public:
	void SetBaseInfo(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void PrintBaseInfo()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class  Derived : private  Base
{
public:
	void PrintDerivedInfo(int pub, int pro, int pri)
	{
		//从基类继承下来的成员变量赋值
		_pub = pub;
		_pro = pro;
		//_pri = pri;
		//子类新增加的成员变量赋值
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D :public Derived
{
	void TestFunc()
	{
		//_pub = 10;
		//_pro = 20;
		//_pri = 20;
	}
};

int main()
{
	//Derived d;
	//d._pub = 10;
	//d._pro = 20;
	return 0;
}
#endif 
#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}
protected:
	int _b;
};

class D :public B
{
public:
	void SetD(int b,int d)
	{
		_b = b;
		_d = d;
	}
private:
	int _d;
};
int main()
{
	B b;
	b.SetB(10);

	D d;
	d.SetD(20, 30);
	b = d;
	//d = b;
	return 0;
}
#endif 

#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}
	void test()
	{
		cout << "B" << endl;
	}
	int _b;
};

class D :public B
{
public:
	char _b;
	void test()
	{
		cout << "D" << endl;
	}
};
int main()
{
	D d;
	d.B::_b = 10;
	d.B::test();
	return 0;
}
#endif 

#if 0
class Base
{
public:
	Base(int b)
	{
		_b = b;
	}
	Base(const Base& b)
	{
		_b = b._b;
	}
	Base& operator=(const Base& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}
		return *this;
	}
private:
	int _b;
};

class Derived :public Base
{
public:
	Derived(int b,int d)
		:Base(b),
		_d(d)
	{}
	Derived(const Derived& d)
		:Base(d)
		,_d(d._d)
	{}
	Derived& operator=(const Derived& d)
	{
		Base::operator=(d);
		if (this != &d)
		{
			_d = d._d;
		}
		return *this;
	}
private:
	int _d;
};
int main()
{
	Derived d1(20,30);
	Derived d2(d1);
	Derived d3(1, 2);
	d3 = d2;
	return 0;
}
#endif 

#if 0
class Base
{
public:
	static Base GetInstrance(int b)
	{
		return Base(b);
	}
private:
	Base(int b)
		:_b(b)
	{}
private:
	int _b;
};
class Derived : public Base
{
public:
	//Derived(int b,int d)
	//	,_d(d)
	//{}
private:
	int _d;
};

int main()
{
	Base b=Base::GetInstrance(10);
	return 0;
}
#endif 

#if 0
class Base final
{
public:

	Base(int b)
		:_b(b)
	{}
private:
	int _b;
};
class Derived : public Base
{
public:
	//Derived(int b,int d)
	//	,_d(d)
	//{}
private:
	int _d;
};
int main()
{
	return 0;
}
#endif 

#if 0
class Derived;
class Base
{
public:
	friend void TestFunc(Base& b,Derived& d);
private:
	int _b;
};

class Derived : public Base
{
protected:
	int _prod;
private:
	int _prid;
};
void TestFunc(Base& b, Derived& d)
{
	cout << b._b<<endl;
	cout << d._prod << endl;
	cout << d._prid << endl;
}
int main()
{
	return 0;
}
#endif;

#if 0
class Base
{
public:
	void Add()
	{
		_b++;
	}
	static int _b;
};

int Base::_b = 0;

class Derived : public Base
{
public:
	void Add1()
	{
		Derived::_b++;
	}
};
int main()
{
	cout << sizeof(Base) << endl;
	Base::_b = 0;
	Derived::_b = 2;
	Base b;
	b.Add();
	Derived d;
	d.Add1();
	cout << &Base::_b << endl;
	cout << &Derived::_b << endl;
	return 0;
}
#endif 

#if 0

//对象模型：对象中各个成员变量在内存中的布局形式
class B1
{
public:
	int _b1;
};
class B2
{
public:
	int _b2;
};
class D :public B2, public B1
{
public:
	int _d;
};
int main()
{
	D d;
	cout << sizeof(d) << endl;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	return 0;
}
#endif 


//class Base1
//{
//public:
//	int _b1;
//};
//class Base2
//{
//public:
//	int _b2;
//};
//class Derived : public Base2,public Base1
//{
//public:
//	int _d;
//};
//int main()
//{
//	Derived d;
//	cout << sizeof(d) << endl;
//	d._b1 = 1;
//	d._b2 = 2;
//	d._d = 3;
//	return 0;
//}

//class B
//{
//public:
//	int b;
//};
//
//class C1 :public B
//{
//public:
//	int c1;
//};
//class C2 :public B
//{
//public:
//	int c2;
//};
//class D :public C1, public C2
//{
//public:
//	int d;
//};
//
//int main()
//{
//	D d;
//	cout << sizeof(d) << endl;
//	d.C1::b = 1;
//	d.c1 = 2;
//	d.c2 = 3;
//	d.d = 4;
//	d.C2::b = 1;
//	return 0;
//}

#if 0
class B
{
public:
	int _b;
};
class D : virtual public B
{
public:
	int _d;
};
int main()
{
	D d;
	cout << sizeof(d) << endl;
	d._b = 1;
	d._d = 2;
	return 0;
}
#endif 

#if 0
class B
{
public:
	int _b;
	static int _a;
};
int B::_a = 10;
class D : public B
{
public:
	int _d;
	static int _a;
};
int D::_a = 20;
int main()
{
	B b;
	D d;
	b._a=b._a + 5;
	d._a++;
	B::_a++;
	

	return 0;
}
#endif 


#if 0
class  B1
{
public:
	int _b1;
};
class  B2
{
public:
	int _b2;
};
class D : public B1, public B2
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	return 0;
}
#endif 

class B
{
public:
	int _b;
};
class D : virtual public B
{
public:
	int _d;
};
int main()
{
	D d;
	d._b = 1;
	d._d = 2;
	return 0;
}