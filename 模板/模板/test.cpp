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

//�������ؿ���ʵ��ͨ��,���������µ�ȱ��
//1,����ĸ����ʵ�,ֻҪ�в�ͬ�����ͳ���,�ͱ����ṩ��Ӧ�ĺ���
//2.������ά��,һ���ط�����������е����غ�����Ҫ��
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
	//1.����������ʵ�����ݳ���Ӧ���͵ĺ���
	//2.���ú���
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
			//�����¿ռ�
			size_t newcapacity = _capacity * 2;
			T* str = new T[newcapacity];
			//����ԭ�ռ�����ݵ��¿ռ���
			memcpy(str, _array, sizeof(T)*_size);
			//�ͷ�ԭ�ռ䣬����ԭ�ռ�ָ���¿ռ��ַ
			delete[] _array;
			_array = nullptr;
			_array = str;
			//��������Ϊ������
			_capacity = newcapacity;
		}
	}

	T& operator[](size_t data)
	{
		assert(data < _size);
		return _array[data];
	}
	//���const���κ�������ֵ,������������ֵ���ɱ��޸�
	//�ұ�const���ε��Ǹó�Ա������������thisָ��,�����ڸó�Ա�����ڲ��ܶ�����κγ�Ա�����޸�
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