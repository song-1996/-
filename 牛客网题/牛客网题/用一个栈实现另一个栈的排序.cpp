#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;
void Sort(stack<int>& s1, stack<int>& s2)
{
	s2.push(s1.top());
	s1.pop();
	int tmp = 0;
	while (!s1.empty())
	{
		if (s1.top() < s2.top())
		{
			tmp = s1.top();
			s1.pop();
			while (!s2.empty() && s2.top() > tmp)
			{
				s1.push(s2.top());
				s2.pop();
			}
			do {
				s2.push(tmp);
				tmp = s1.top();
				s1.pop();
			} while (!s1.empty() && tmp < s1.top());
			s2.push(tmp);
		}
	}
}
int main()
{
	int N;
	stack<int> s1;
	stack<int> s2;
	cin >> N;
	while (N--)
	{
		int x;
		cin >> x;
		s1.push(x);
	}
	Sort(s1, s2);
	while (!s2.empty())
	{
		cout << s2.top();
		s2.pop();
		if (!s2.empty())
			cout << " ";
	}
	cout << endl;
	return 0;
}