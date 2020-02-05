#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.empty())
			return 0;
		vector<int> buf(prices);
		vector<int> Max(prices);
		Max[0] = 0;
		int profit = 0;
		int curmax = 0;
		for (size_t i = 1; i < prices.size(); i++)
		{
			if (prices[i] < prices[i - 1])
			{
				profit += curmax;
				curmax = 0;
				Max[i] = 0;
				buf[i] = prices[i];
			}
			else
			{
				Max[i] -= min(buf[i - 1], prices[i]);
				curmax = max(Max[i], curmax);
				if (prices[i - 1] <= prices[i])
					buf[i] = buf[i - 1];
			}
		}
		profit += curmax;
		return profit;
	}
};
int main()
{
	vector<int> v{ 0,5,5,6,2,1,1,3 };
	Solution s;
	cout<<s.maxProfit(v);
	system("pause");
	return 0;

}