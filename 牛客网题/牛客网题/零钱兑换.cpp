#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector<int> buf(amount + 1, amount);
		buf[0] = 0;
		for (int i = 1; i < amount + 1; i++)
		{
			for (size_t j = 0; j < coins.size(); j++)
			{
				if (i - coins[j] >= 0)
					buf[i] = min(buf[i - coins[j]], buf[i]);
				buf[i] += 1;
			}
		}
		if (buf[amount] >= amount)
			return -1;
		return buf[amount];
	}
};
int main()
{
	vector<int> v{2};
	Solution s;
	s.coinChange(v, 3);
	system("pause");
	return 0;

}