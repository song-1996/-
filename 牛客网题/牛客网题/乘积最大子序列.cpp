#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums)
	{
		int _max = nums[0];
		vector<int> buf(nums);
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] < 0)
				swap(nums[i - 1], buf[i - 1]);
			nums[i] = max(nums[i] * nums[i - 1], nums[i]);
			buf[i] = min(buf[i] * buf[i - 1], buf[i]);
			if (nums[i] < 0)
				swap(nums[i - 1], buf[i - 1]);
		}
		for (size_t i = 1; i < nums.size(); i++)
			_max = max(_max, nums[i]);
		return _max;
	}
};
#include<stdlib.h>
int main()
{
	vector<int> v{ -1,-2,-3,0 };
	Solution s;
	s.maxProduct(v);
	system("pause");
	return 0;

}