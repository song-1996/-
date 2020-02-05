#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b)
	{
		int step = 0;
		if (a.size() < b.size())
			a.swap(b);
		string ret;
		int sum = 0;
		for (int i = a.size() - 1, j = b.size() - 1; i >= 0; i--, j--)
		{
			if (j >= 0)
				sum += (b[j] - '0');
			sum += (a[i] - '0') + step;
			step = 0;
			if (sum > 1)
			{
				if (sum == 2)
					sum = 0;
				else if (sum == 3)
					sum = 1;
				step = 1;
			}
			ret.push_back(sum + '0');
			sum = 0;
		}
		if (step == 1)
			ret.push_back(1 + '0');
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
int main()
{
	Solution s;
	cout<<s.addBinary("1010", "1011");
	system("pause");
	return 0;

}