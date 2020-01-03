#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
using namespace std;
#if 0
class Person
{
public:
	void InitPerson(const char* name, int age, const char* gender)
	{
		strcpy(_name, name);
		_age = age;
		strcpy(_gender, gender);
	}
	void Print()
	{
		cout << _name << ' ' << _age << ' ' << _gender << endl;
	}
private:
	char _name[20];
int _age;
char _gender[5];
};
int main()
{
	Person s;
s.InitPerson("zhangsan", 20, "man");
s.Print();
system("pause");
return 0;

}
#endif
#if 0
struct stu1
{
	void print()
	{
		cout << "print()" << endl;
	}
	int a = 10;
	char b = 'a';
	short c = 3;
};
struct stu4
{

};
struct stu2
{
	int a = 10;
	char b = 'a';
	short c = 3;
};
struct stu3
{
	void print()
	{
		cout << "print()" << endl;
	}
};
int main()
{
	stu1 s1;
	stu2 s2;
	stu3 s3;
	stu4 s4;
	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;
	cout << sizeof(s3) << endl;
	cout << sizeof(s4) << endl;
	system("pause");
	return 0;

}
#endif

#if 0
class Date
{
public:
	void InitDate(int year, int month, int day)
	{
		Date& this1 = *this;
		cout << &this1 << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		Date& this1 = *this;
		cout << &this1 << endl;
		cout << _year << '-' << _month << '-' << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date* s = NULL;
	s->InitDate(2019, 3, 32);
	s->Print();
	system("pause");
	return 0;
}
#endif

#if 0
class string1
{
public:
	string1(const char* name)
	{
		if (name == nullptr)
			name = "";
		_name = (char*)malloc(sizeof(char)*(strlen(name) + 1));
		if (name == nullptr)
		{
			return;
		}
		strcpy(_name, name);
	}
	~string1()
	{
		free(_name);
		_name = nullptr;
	}
	void Print()
	{
		cout << _name << endl;
	}
private:
	char* _name;
};
class Date
{
public:
	Date(int year, int month, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout<< _year << '-' << _month << '-' << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 3, 23);
	d1.Print();
	string1 s1("zhangsan");
	s1.Print();
	system("pause");
	return 0;
}
#endif


#if 0
class Time
{
public:
	Time(int hour,int minute,int second)
	{
		cout << "Time()" << endl;
		_hour = hour;
		_minute = minute;
		_second = second;
	}
	void PrintTime()
	{
		cout << _hour << '-' << _minute << '-' << _second << endl;
	}
	private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	Date d;
	system("pause");
	return 0;
}
#endif
#include<assert.h>
#if 0
typedef int DataType;

class Sqlist
{
public:
	Sqlist(int capacity = 10)
	{
		_arr = (DataType*)malloc(sizeof(DataType)*capacity);
		if (_arr == nullptr)
		{
			assert(0);
		}
		_size = 0;
		_capacity = capacity;
	}
	~Sqlist()
	{
		if (_arr != nullptr)
		{
			free(_arr);
			_arr = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}
private:
	DataType* _arr;
	int _size;
	int _capacity;
};
int main()
{
	Sqlist s;
	system("pause");
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
		_str = nullptr;
	}
private:
	char* _str;
};
class Person
{
private:
	String _name;
	int _age;
};
int main()
{
	Person p;
	system("pause");
	return 0;
}
#endif
#if 0
class String
{
public:
	String(const char* str = "jack")
	{
		cout << "string()"<<this << endl;
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	//String(const String& s1)
	//{
	//	_str = (char*)malloc(strlen(s1._str) + 1);
	//	strcpy(_str, s1._str);
	//}
		String(const String* s1)
	{
		_str = (char*)malloc(strlen(s1->_str) + 1);
		strcpy(_str, s1->_str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
		_str = nullptr;
	}
private:
	char* _str;
};
class Date
{
public:
	Date(int year=1900,int month=1,int day=1)
	{
		cout << "Date()" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 3, 25);
	Date d2(d1);
	String s1("zhangsan");
	String s2(&s1);
	system("pause");
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "jack")
	{
		cout << "string()" << this << endl;
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	String(const String& s1)
	{
		_str = (char*)malloc(strlen(s1._str) + 1);
		strcpy(_str, s1._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			_str = (char*)malloc(strlen(s._str) + 1);
			strcpy(_str, s._str);
		}
		return *this;
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
		_str = nullptr;
	}
private:
	char* _str;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date operator+(int day)
	{
		_day = _day + day;
		return *this;
	}
	bool operator==(const Date& d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{

	Date d1(2019, 3, 25);
	Date d2;
	d2 = 3;
	Date d3(d1);
	if (d1 == d3)
		cout << 1 << endl;
	Date d4(0, 0, 0);
	d4 = d2 = d1;
	String s1("zhangsan");
	String s2;
	String s3;
	s2 = s1;
	s2 = "lisi";
	s3= "lisi";
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date& operator++()
	{
		_day = _day + 1;
			return *this;
	}
	const Date operator++(int)
	{
		Date this1(*this);
		_day = _day + 1;
		return this1;
	}
	Date& operator--()
	{
		_day = _day - 1;
		return *this;
	}
	const Date operator--(int)
	{
		Date this1(*this);
		_day = _day - 1;
		return this1;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2 = (++d1);
	Date d3 = d1++;
	Date d4 = (--d1);
	Date d5 = (d1--);
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	void Print1()
	{
		Print2();
		cout <<" Date()" << "-" << this << endl;
	}
	void Print2() const
	{
		Print1();
		cout << " Date()" << "-" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	const Date d1;
	d1.Print();
	const Date d2;
	d2.Print();
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	bool _Isleap(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return true;
		return false;
	}
	int GetMonthday(int year,int month)
	{
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (_Isleap(year) && month == 2)
			return 29;
		return arr[month];

	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if ((year >= 1900) && (month > 0 && month <= 12) && (day > 0 && day <= GetMonthday( year, month)))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "不合法日期" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date operator+(int day)
	{
		int Maxday=GetMonthday(_year, _month);
		Date this1(*this);
		_day = _day + day;
		if (_day <= Maxday)
		{
			return *this;
		}
		else
			return this1;
	}
	bool operator>(const Date& d) const
	{
		if (_year > d._year)
			return true;
		else
			if (_year==d._year&&_month>d._month)
				return true;
			else
				if (_year == d._year&&_month==d._month&&_day>d._day)
					return true;
				else
					return false;
	}
	bool operator>=(const Date& d)const
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
			return true;
		if (_year > d._year)
			return true;
		else
			if (_year == d._year&&_month > d._month)
				return true;
			else
				if (_year == d._year&&_month == d._month&&_day > d._day)
					return true;
				else
					return false;
	}
	bool operator<(const Date& d)const
	{
		return  !operator>=(d);
	}
	bool operator<=(const Date& d)const
	{
		return  !operator>(d);
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 3, 27);
	Date d2(2019, 3, 27);
	d1=d1 + 6;
	if (d1 > d2)
		cout << ">" << endl;
	if(d1 >= d2)
		cout << ">=" << endl;
	if (d1 < d2)
		cout << "<" << endl;
	if (d1 <= d2)
		cout << "<=" << endl;
	system("pause");
	return 0;
}
#endif

#if 0
class Time
{
public:
Time(int hour = 0)
:_hour(hour)
{
cout << "Time()" << endl;
}
private:
int _hour;
};
class Date
{
public:
	Date(int day)
	{}
private:
	int _day;
	Time _t;
};
int main()
{
	Date d(1);
	
	system("pause");
	return 0;
}
#endif

#if 0
class Array
{
public:
	Array(int size=5)
		:_size(size),
		_array ((int*)malloc(sizeof(int)*size))
	{

	}
	~Array()
	{
		if (_array != nullptr)
		{
			free(_array);
			_array = nullptr;
			_size = 0;
		}
	}
private:
	int* _array;
	int _size;
};
int main()
{
	Array a;
	system("pause");
	return 0;
}
#endif 

#if 0
class Date
{
public:
	explicit Date(int day)
		:_day(day)
	{
	}
private:
	int _day;
};
int main()
{
	Date d1(2019);
	Date d2  (2018);
	 d2 = d1;
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year=1990)
		:_year(year)
	{
		count++;
	}
	static int Getcount()
	{
		 return count;
	}
private:
	int _year;
	static int count;
};
int Date::count = 0;
int main()
{
	cout << Date::Getcount() << endl;
	Date d1;
	Date d2;
	Date d3;
	cout << Date::Getcount() << endl;
	system("pause");
	return 0;
}
#endif
#include<string.h>
#if 0
class String 
{
	friend ostream& operator<<(ostream& _cout, const String& s);
	friend istream& operator>>(istream& _cin, const String& s);
public:
	String(const char* str="jack")
	{
		if (str == nullptr)
			str = "";
		_str = (char*)malloc(strlen(str) + 1);
		if (_str == nullptr)
			assert(0);
		strcpy(_str, str);
	}
	//void PrintString()
	//{
	//	cout << _str << endl;
	//}
	//void operator<<(ostream& _cout)
	//{
	//	_cout << _str;
	//}
	~String()
	{
		if (_str != nullptr)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};
ostream& operator<<(ostream& _cout, const String& s)
{
	_cout << s._str;
	return _cout;
}
istream& operator>>(istream& _cin, const String& s)
{
	_cin >> s._str;
	return _cin;
}
int main()
{
	String s1;
	String s2(nullptr);
	String s3("zhangsan");
	cin >> s1>>s2;
	cout << s1<<' '<<s3<<' '<<s2;
	//s1.PrintString();
	//s2.PrintString();
	//s3.PrintString();
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
	class Time
	{
	public:
		Time(int second=10)
		{
			_second = second;
		}
		void PrintDate()
		{
			Date d;
			d._day = 10;
			cout << d._day << endl;
		}
	private:
		int _second;
	};
public:
	explicit Date(int day=1)
		:_day(day)
	{
	}
	Time t;
private:
	int _day;
};
int main()
{
	
	Date d;
	d.t;
	d.t.PrintDate();
	system("pause");
	return 0;
}
#endif

#if 0
class solution
{
public:
	class Temp
	{
	public:
		Temp()
		{
			n++;
			sum = sum + n;
		}
		static void Reset()
		{
			n = 0;
			sum = 0;
		}
		static int Getsum()
		{
			return sum;
		}
	private:
		static int n;
		static int sum;
	};
	int solution_sum(int n)
	{
		Temp::Reset();
		Temp a[100];
		return Temp::Getsum();
	}
};
int solution::Temp::n = 0;
int solution::Temp::sum = 0;
int main()
{
	solution s;
	cout << s.solution_sum(100) << endl;
	system("pause");
	return 0;
}
#endif


