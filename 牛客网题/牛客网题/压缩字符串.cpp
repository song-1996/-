#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
class Solution {
	void Midy(int count, vector<char>& chars, int& j)
	{
		if (count > 0)
		{
			int r = count % 10;
			Midy(count / 10, chars, j);
			chars[j++] = r + '0';
		}
	}
public:
	int compress(vector<char>& chars)
	{
		int sum = 0;
		int count = 0;
		int j = 0;
		char tmp = chars[0];
		for (size_t i = 0; i < chars.size(); i++)
		{
			if (tmp == chars[i])
				count++;
			else
			{
				sum += 1;
				chars[j++] = tmp;
				tmp = chars[i];
				if (count > 1)
				{
					int pos = j;
					Midy(count, chars, j);
					sum += j - pos;
				}
				count = 1;
			}
		}
		sum += 1;
		chars[j++] = tmp;
		if (count > 1)
		{
			int pos = j;
			Midy(count, chars, j);
			sum += j - pos;
		}
		return sum;
	}
};
int main()
{
	vector<char> v{ 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
	Solution s;
	s.compress(v);
	system("pause");
	return 0;

}