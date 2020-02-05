#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class Solution {
public:
	int myAtoi(string str)
	{
		int sign = 1;
		long long sum = 0;
		int count = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
			{
				if (count != 0)
					return 0;
				if (str[i] == '+' || str[i] == '-')
				{
					count++;
					if (str[i] == '-')
						sign = -1;
				}
				continue;
			}
			if (str[i] >= '0'&&str[i] <= '9')
				sum = sum * 10 + (str[i] - '0');
			else
			{
				if (sum == 0)
					return 0;
				else
					break;
			}
		}
		if (sign == -1)
			sum *= -1;
		if (sum < INT_MIN)
			return INT_MIN;
		else if (sum > INT_MAX)
			return  INT_MAX;
		else
			return sum;
	}
};
int main()
{
	Solution s;
	cout<<s.myAtoi("  -42");
	system("pause");
	return 0;

}