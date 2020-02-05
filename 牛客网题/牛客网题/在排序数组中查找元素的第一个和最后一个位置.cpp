#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> ret(2, -1);
		if (nums.size() == 0)
			return ret;
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		bool flag = false;
		while (left <= right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] >= target)
			{
				if(nums[mid]==target)
					flag = true;
				right--;
			}
			else if (nums[mid] < target)
				left++;
		}
		if (!flag)
			return ret;
		size_t i = left;
		int count = 0;
		for (; i < nums.size()-1; i++)
		{
				if (nums[i] != nums[i + 1])
					break;
		}
		ret[0] = left;
		ret[1] = i;
		return ret;
	}
};
int main()
{
	vector<int> v{ 2,2 };
	Solution s;
	s.searchRange(v,3);
	system("pause");
	return 0;

}