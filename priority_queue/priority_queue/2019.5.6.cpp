#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

#if 0
class Date
{
public:
	Date(int year,int month,int day)
		:_year(year),
		_month(month),
		_day(day)
	{}
	bool operator<(const Date& d) const
	{
		if ((_year < d._year) ||
			(_year == d._year&&_month < d._month) ||
			(_year == d._year&&_month == d._month&&_day < d._day))
			return true;
		else
			return false;
	}
	~Date()
	{}
private:
	int _year;
	int _month;
	int _day;
};

class Compare
{
public:
	bool operator()(Date* Pleft, Date* Pright)
	{
		return (*Pleft) < (*Pright);
	}
};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		size_t sz = nums.size();
		priority_queue<int> q(nums.begin(),nums.end());
		for (int i = 1; i < k; i++)
			q.pop();
		return q.top();
	}
};
int main()
{
	int arr[] = { 1,1,1,2,2,3 };
	vector<int> v(arr, arr + 6);
	Solution s;
	s.findKthLargest(v,2);
	//int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	//priority_queue<int> q1;
	//cout << q1.empty() << endl;
	//cout << q1.size() << endl;
	//priority_queue<int> q2(arr,arr+10);
	//cout << q2.empty() << endl;
	//cout << q2.size() << endl;
	//cout << q2.top() << endl;
	//priority_queue<int, vector<int>, greater<int>> q3(arr, arr + 10);
	//cout << q3.empty() << endl;
	//cout << q3.size() << endl;
	//cout << q3.top() << endl;
	//Date* d[3] = { &Date (2019, 5, 4),
	//&Date (2019, 5, 5),
	//&Date (2019, 5, 6) };
	////priority_queue<Date> q4(d, d + 3);
	//priority_queue<Date*,vector<Date*>,Compare> q5(d, d + 3);
	
 	system("pause");
	return 0;

}
#endif

#if 0
namespace N
{
	template<class T,class Container=deque<T>>  
	class Stack
	{
	public:
		Stack()
		{}
		void push(const T& data)
		{
			_con.push_back(data);
		}
		void pop()
		{
			_con.pop_back();
		}
		bool empty()
		{
			return  _con.empty();
		}
		int size()
		{
			return _con.size();
		}
		T& top()
		{
			return _con.back();
		}
	private:
		Container _con;
	};

	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		queue()
		{}
		void push(const T& data)
		{
			_con.push_back(data);
		}
		void pop()
		{
			_con.pop_front();
		}
		int size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		T& front()
		{
			return _con.front();
		}
		const T& front() const
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
		const T& back() const
		{
			return _con.back();
		}
	private:
		Container _con;
	};
	template<class T,class Container=vector<T> ,class Compare=less<T>>
	class priority_queue
	{

	public:
		typedef T* iterator;
		priority_queue()
		{}
		priority_queue(iterator first,iterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				first++;
				AdjustUp(_con.size()-1);
			}
		}
		void push(const T& data=T())
		{
			_con.push_back(data);
			AdjustUp(_con.size() - 1);
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		T& top()
		{
			return _con[0];
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		void AdjustDown(int i)
		{
			int parent = i;
			int child = parent * 2 + 1;
			while (child < (int)_con.size())
			{
				if (child + 1 < (int)_con.size()&&Compare()(_con[child], _con[child + 1]))
				{
					child = child + 1;
				}
				if (Compare()(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
				}
				else
					return;
				parent = child;
				child = parent * 2 + 1;
			}
		}
		void AdjustUp(int i)
		{
			int child = i;
			int parent = (child - 1) / 2;
			while (parent>=0)
			{
				if (child+1 < (int)_con.size() && Compare()(_con[child], _con[child + 1]))
				{
					child = child + 1;
				}
				if (Compare()(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
				}
				else
					return;
				child = parent;
				parent = (child - 1) / 2;
			}
		}
	private:
		Container _con;
	};

}
void stacktest()
{
	N::Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.size() << endl;
	cout << s.empty() << endl;
	cout << s.top() << endl;
	s.pop();
	s.pop();
	cout << s.size() << endl;
	cout << s.empty() << endl;
	cout << s.top() << endl;
	s.pop();
	s.pop();
	cout << s.size() << endl;
	cout << s.empty() << endl;
}
void queuetest()
{
	N::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.size() << endl;
	cout << q.empty() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;
	q.pop();
	q.pop();
	cout << q.size() << endl;
	cout << q.empty() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;
	q.pop();
	q.pop();
	cout << q.size() << endl;
	cout << q.empty() << endl;
} 
void priority_queuetest()
{
	int arr[] = { 1,2 };
	N::priority_queue<int,vector<int> ,greater<int>> q(arr,arr+2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	cout << q.top() << endl;
	cout << q.size() << endl;
	cout << q.empty() << endl;
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();	
	cout << q.size() << endl;
	cout << q.empty() << endl;

}
int main()
{
	//stacktest();
	//queuetest();
	priority_queuetest();
	return 0;
}
#endif 
//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
//	{
//	
//		vector<int> v;
//		if (k <= 0 || k > (int)input.size())
//			return v;
//		v.resize(k);
//		priority_queue<int> q(input.begin(), input.begin() + k );
//		for (int i = k; i < (int)input.size(); i++)
//		{
//			if (input[i] <= q.top())
//			{
//				q.pop();
//				q.push(input[i]);
//			}
//		}
//		for (int i = 0; i < k; i++)
//		{
//			v[i] = q.top();
//			q.pop();
//		}
//		return v;
//	}
//};


class Solution {
	int Binary_search(vector<int>& v, int k)
	{
		int left = 0;
		int right = v.size() - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = (left + right) >> 1;
			if (v[mid] == k)
				return mid;
			else if (v[mid] < k)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
public:
	int GetNumberOfK(vector<int> data, int k)
	{
		if (data.empty())
			return 0;
		if (data.size() > 1 && data[0] > data[1])
			reverse(data.begin(), data.end());
		if (k<data[0] || k>data[data.size() - 1])
			return 0;
		int count = 1;
		int ret=Binary_search(data, k);
		if (ret == -1)
			return 0;
		while (1)
		{
			if (ret == 0 || data[ret] != data[ret - 1])
			{
				break;
			}
			else if (data[ret] == data[ret - 1])
			{
				ret = ret - 1;
			}
		}
		while (ret + 1 < (int)data.size() && data[ret] == data[ret + 1])
		{
			count++;
			ret++;
		}
		return count;
	}
};
int main()
{
	int arr[] = { 1,2,3,3,3,3,4,5 };
	vector<int> v(arr, arr + 8);
	Solution s;
	s.GetNumberOfK(v, 3);
	return 0;
}


//class Solution {
//public:
//	int NumberOf1Between1AndN_Solution(int n)
//	{
//		if (n <= 0)
//			return 0;
//		int count = 0;
//		int sum = 0;
//		int _count = 0;
//		int arr[] = { 0,2,10,1,1,1,1,1,1,1,2 };
//		for (int i = 1; i < 11; i++)
//			count += arr[i];
//		int k = n % 100;
//		n = n / 100;
//		if (k < 100)
//		{
//			for (int i = 1; i <= (k / 10); i++)
//				_count += arr[i];
//			switch (k / 10)
//			{
//			case 1:
//				_count += (k % 10);
//				break;
//			case 0:
//			case 2:
//			case 3:
//			case 4:
//			case 5:
//			case 6:
//			case 7:
//			case 8:
//			case 9:
//				if (k % 10 >= 1)
//					_count += 1;
//				break;
//			default:
//				break;
//			}
//		}
//			sum = sum + n * count + _count;
//			_count = 0;
//		return sum;
//	}
//};
//
//int main()
//{
//	Solution s;
//	s.NumberOf1Between1AndN_Solution(1);
//	return 0;
//}