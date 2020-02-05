#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
	bool binay_search(const vector<int>& v, const int key)
	{
		int left = 0;
		int right = v.size() - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (v[mid] == key)
				return true;
			else if (v[mid] > key)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return false;
	}
public:
	int nthUglyNumber(int n)
	{
		vector<int> v;
		for (int i = 0; i < 6; i++)
			v.push_back(i + 1);
		for (int i = 7; (int)v.size() < n; i++)
		{
			if (i % 2 == 0)
			{
				if (binay_search(v,i / 2))
					v.push_back(i);
			}
			else if (i % 3 == 0)
			{
				if (binay_search(v,i / 3))
					v.push_back(i);
			}
			else if (i % 5 == 0)
			{
				if (binay_search(v,i / 5))
					v.push_back(i);
			}
		}
		return v[n - 1];
	}
};
int main()
{
	Solution s;
	s.nthUglyNumber(400);
	system("pause");
	return 0;

}