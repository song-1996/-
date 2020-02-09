#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
#include<assert.h>

namespace bit
{
	class String
	{
	public:
		typedef char* Iterator;
	public:
		String(const char* str="")
		{
			if (str == nullptr)
				str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			: _str ( new char[s._capacity + 1])
			, _size ( s._size)
			,_capacity ( s._capacity)
		{
			strcpy(_str, s._str);
		}
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				char* ptr = new char[s._capacity + 1];
				strcpy(ptr, s._str);
				if (_str != nullptr)
				{
					delete[] _str;
					_str = nullptr;
				}
				_str = ptr;
				_capacity = s._capacity;
				_size = s._size;
			}
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		Iterator begin()
		{
			return _str;
		}
		Iterator end()
		{
			return _str + _size;
		}
		void Reserve(size_t newcapacity)
		{
			if (newcapacity > _capacity)
			{
				char* ptr = new char[newcapacity+1];
				strcpy(ptr, _str);
				delete[] _str;
				_str = ptr;
				_capacity = newcapacity;
			}
		}
		
		void resize(size_t newsize, char c=char())
		{
			size_t oldsize = _size;
			if (newsize > oldsize)
			{
				for (size_t i = oldsize; i < newsize; i++)
					PushBack(c);
			}
			_size = newsize;
		}
		void PushBack(char c)
		{
			if (_size == _capacity)
				Reserve(2 * _capacity);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void Append(size_t n,char c)
		{
			for (size_t i = 0; i < n; i++)
			{
				PushBack(c);
			}
		}

		void Append(const char* str)
		{
			int sz=strlen(str);
			if (_size + sz > _capacity)
			{
				Reserve(_size + sz + 1);
			}
			char* end=_str + _size;
			strcpy(end, str);
			_size = _size + sz;
			_str[_size] = '\0';
		}
		String& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}
		String& operator+=(const char* str)
		{
			int sz = strlen(str);
			if (_size + sz > _capacity)
			{
				Reserve(_size + sz + 1);
			}
			char* end = _str + _size;
			strcpy(end, str);
			_size = _size + sz;
			_str[_size] = '\0';
			return *this;
		}
		void Clean()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char*  C_str() const
		{
			return _str;
		}

		size_t Size() const
		{
			return _size;
		}
		size_t Capacity() const
		{
			return _capacity;
		}
		bool empty() const
		{
			return _size == 0;
		}
		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		const char& operator[](size_t pos) const 
		{
			return _str[pos];
		}
		
		size_t Find(char c, size_t pos=0) const
		{
			size_t i = pos;
			for (i = pos; i < _size; i++)
			{
				if (c == _str[i])
					return i;
			}
			return -1;
		}
		size_t Find(const char* str, size_t pos=0) const
		{
			const char* startcur = str;
			size_t startpos=pos;
			while (pos < _size)
			{
				startpos = pos;
				startcur = str;
					while (*(_str+ startpos) == *startcur)
					{
						startpos++;
						startcur++;
						if (*startcur == '\0')
							return pos;
					}
					pos=pos + 1;
			}
			return -1;
		}
		String SubStr(size_t pos, size_t n)
		{
			size_t i = pos;
			size_t cur_n = 0;
			String ret;
			ret.Reserve(n);
			if (pos > _size)
				return _str;
			else
			{
				while (cur_n<n)
				{
					ret.PushBack(_str[i]);
					cur_n++;
					i++;
					if(i>=_size)
						return ret;
				}
			}
			return ret;
		}
		String& Insert(size_t pos,size_t n, char c)
		{

			if (pos >= 0 && pos <= _size)
			{
				(*this).Reserve(_size + n+1);
				size_t cur_n = 0;
				size_t i = pos;
				for (; i < _size; i++)
				{
					_str[i + n] = _str[i];
				}
				while (cur_n<n)
				{
					_str[pos] = c;
					pos++;
					cur_n++;
				}
				_size = _size + n;
				_str[_size] = '\0';
				return *this;
			}
			return *this;
		}
		String& Insert(size_t pos, const char* str)
		{
			if (pos >= 0 && pos <= _size)
			{
				int len = strlen(str);
				(*this).Reserve(_size + len + 1);
				for (size_t i = pos; i < _size; i++)
				{
					_str[i + len] = _str[i];
				}
				while (*str)
				{
					_str[pos] = *str;
					str++;
					pos++;
				}
				_size = _size + len;
				_str[_size] = '\0';
				return *this;
			}
			return *this;
		}
		String& Erase(size_t pos=0, size_t len=-1)
		{
			size_t klen = -1;
			if (pos >= 0 && pos <= _size)
			{
				if (pos == 0 && len == klen)
				{
					(*this).Clean();
				}
				else if (len == klen)
				{
					_size = pos;
					_str[_size] = '\0';
				}
				else
				{
					if (len >= _size)
					{
						_size = pos;
						_str[_size] = '\0';
					}
					else
					{
						for (size_t i = pos; i < _size; i++)
						{
							_str[i] = _str[i + len];
						}
						_size = _size - len;
						_str[_size] = '\0';
					}
				}
				return *this;
			}
			return *this;
		}
		private:
		friend ostream& operator<<(ostream& _cout, const bit::String& str);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}

ostream& bit::operator<<(ostream& _cout, const bit::String& str)
{
	cout << str._str;
	return _cout;
}

int main()
{
	bit::String s("abcdef");
	//s.Erase();
	//s.Erase(2);
	//s.Erase(1, 2);
	//s.Erase(2, 10);
	cout << s<<endl;
	////s.Insert(2, 3, 'g');
	//s.Insert(1, "hello");
	//size_t pos = -1;
	//size_t ret=s.Find('c');
	//size_t sret=s.Find("ccb");
	//if (ret != pos)
	//	cout << "find" << endl;
	//else
	//	cout << "not find" << endl;
	//if (sret != pos)
	//	cout << "sfind" << endl;
	//else
	//	cout << "not sfind" << endl;
	//bit::String s2;
	//s2 = s.SubStr(2, 10);
	//string s("hello");
	//string s1;
	//s1=s.erase(2, 9);
	//s.insert(8, 2, 'c');
	//s.push_back('c');
	//s += 'd';
	//string s1;
	//s1 = s.substr(4, 10);
	system("pause");
	return 0;

}
#if 0 
int main()
{
	/*
	bit::String s1("hello");
	bit::String s2(s1);
	bit::String s3;
	s3 = s2;
	s1.Append(" world");
	s1 += " nishinimabi";
	s1 += 'u';
	s1.PushBack('z');
	s1.Append(6,'p');
	*/
	/*bit::String s1("hello");
	s1.resize(1);
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1.resize(10, 'c');
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1.resize(20);
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;*/
	
	//string s("hello world");
	//size_t pos = -1;
	//size_t ret=s.find('q', 0);
	//if (ret !=pos)
	//	cout << "find" << endl;
	//else
	//	cout << "not find" << endl;
	system("pause");
	return 0;

}
#endif