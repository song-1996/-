#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<stdlib.h>
#include<vector>
using namespace std;

//class MinStack {
//public:
//	stack<int> s1;
//	stack<int> s2;
//	/** initialize your data structure here. */
//	MinStack()
//	{
//	}
//
//	void push(int x)
//	{
//		if (s1.empty() && s2.empty())
//		{
//			s1.push(x);
//			s2.push(x);
//		}
//		else
//		{
//			if (x <= s2.top())
//			{
//				s2.push(x);
//			}
//			s1.push(x);
//		}
//
//	}
//
//	void pop()
//	{
//		if (s2.top() == s1.top())
//			s2.pop();
//		s1.pop();
//	}
//
//	int top()
//	{
//		return s1.top();
//	}
//
//	int getMin()
//	{
//		return s2.top();
//	}
//};

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.empty() && popV.empty())
			return true;
		size_t i = 0;
		size_t j = 0;
		while (i < pushV.size())
		{
			if (pushV[i] == popV[j])
			{
				pushV.erase(pushV.begin()+i);
				i = i - 1;
				j++;
			}
			i++;
		}
		while (popV[j] == pushV.back())
		{
			i--;
			pushV.erase(pushV.begin() +i);
			j++;
			if (j >= popV.size())
				break;
		}
		if (pushV.empty())
			return true;
		else
			return false;
	}
};
int main()
{
	int arr[] = { 1,2,3,4,5 };
	int arr1[] = { 4,3,5,1,2 };
	vector<int> v1(arr,arr+5);
	vector<int> v2(arr1,arr1+5);
	Solution s;
	cout << s.IsPopOrder(v1, v2) << endl;
	system("pause");
	return 0;

}