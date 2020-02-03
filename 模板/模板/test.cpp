#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#if 0
int ADD(int a, int b)
{
	return a + b;
}
double ADD(double a, double b)
{
	return a + b;
}
char ADD(char a, char b)
{
	return a + b;
}

//函数重载可以实现通用,但是有以下的缺点
//1,代码的复用率低,只要有不同的类型出现,就必须提供相应的函数
//2.不容易维护,一个地方出错可能所有的重载函数都要改
int main()
{
	ADD(1, 2);
	ADD(1.0, 2.0);
	ADD('a', 'b');
	system("pause");
	return 0;

}
#endif 

#if 0
template<class T>
T ADD(T a, T b)
{
	return a + b;
}
int main()
{
	 ADD(1 , 2);
	 ADD(1.0, 2.0);
	 ADD(1, (int)2.0);
	cout<< ADD<int>(1.0, 3.0)<<endl;
	//1.编译器根据实参推演出相应类型的函数
	//2.调用函数
	system("pause");
	return 0;
}
#endif

#if 0
int ADD(int a, int b)
{
	return a + b;
}
template<class T1,class T2>
T1 ADD(T1 a, T2 b)
{
	return a + b;
}
//int ADD<int>(int a, int b);
int main()
{
	cout<<ADD(1, 2.0)<<endl;
	ADD(1.0, 2.0);
	system("pause");
	return 0;
}
#endif

#include<assert.h>
#if 0
template<class T>

class SeqList
{
public:
	SeqList(int capacity=10)
		:_array(new T[capacity]),
		 _capacity(capacity),
		 _size(0)
	{}
	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	void PushBack(T data);
	void PopBack();
	void checkCapacity()
	{
		if (_size == _capacity)
		{
			//申请新空间
			size_t newcapacity = _capacity * 2;
			T* str = new T[newcapacity];
			//拷贝原空间的内容到新空间中
			memcpy(str, _array, sizeof(T)*_size);
			//释放原空间，并将原空间指向新空间地址
			delete[] _array;
			_array = nullptr;
			_array = str;
			//更新容量为新容量
			_capacity = newcapacity;
		}
	}

	T& operator[](size_t data)
	{
		assert(data < _size);
		return _array[data];
	}
	//左边const修饰函数返回值,表明函数返回值不可被修改
	//右边const修饰的是该成员函数内隐含的this指针,表明在该成员函数内不能对类的任何成员进行修改
	const T& operator[](size_t data) const
	{
		assert(data < _size);
		return _array[data];
	}
	size_t Size()
	{
		return _size;
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
void SeqList<T>::PushBack(T data)
{
	checkCapacity();
	_array[_size++] = data;
}
template<class T>
void SeqList<T>::PopBack()
{
	_size--;
}
int main()
{
	SeqList<int> s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);
	cout << s[1] << endl;
	s[1] = 20;
	cout << s[1] << endl;
	cout << s.Size() << endl;
	s.PopBack();
	s.PopBack();
	cout << s.Size() << endl;
	system("pause");
	return 0;
}
#endif