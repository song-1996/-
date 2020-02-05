#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int add = 0;
		bool flag = false;
		digits[digits.size() - 1] += 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			digits[i] += add;
			add = 0;
			if (digits[i] > 9)
			{
				digits[i] -= 10;
				add = 1;
				flag = true;
			}
			if (flag == false)
				break;
		}
		if (add == 1)
		{
			reverse(digits.begin(), digits.end());
			digits.push_back(1);
			reverse(digits.begin(), digits.end());
		}
		return digits;
	}
};
int main()
{
	vector<int> v{ 9 };
	Solution s;
	s.plusOne(v);
	system("pause");
	return 0;

}