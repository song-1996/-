#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> countBits(int num)
	{
		vector<int> ret(num + 1, 0);
		int tmp = 0;
		for (int i = 1; i < num + 1; i++)
		{
			int cur_i = i;
			while (cur_i % 2 == 0)
				cur_i /= 2;
			if (cur_i == 1)
			{
				ret[i] = 1;
				tmp = i;
				continue;
			}
			ret[i] = ret[tmp] + ret[i - tmp];
		}
		return ret;
	}
};
int main()
{
	Solution s;
	s.countBits(17);
	system("pause");
	return 0;

}