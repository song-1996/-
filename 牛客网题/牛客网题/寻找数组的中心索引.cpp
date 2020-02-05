#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
	int pivotIndex(vector<int>& nums)
	{
		if (nums.size() == 0)
			return -1;
		int left = 0;
		int right = nums.size() - 1;
		int tmp = nums[right]-nums[left];
		while (left < right)
		{
			if (tmp == 0)
			{
				if (left + 1 == right-1)
					return left+1;
				left++;
				tmp -= nums[left];
			}
			else if (tmp > 0)
			{
				if (nums[left + 1] >= 0)
				{
					left++;
					tmp -= nums[left];
				}
				else if (nums[right - 1] <= 0)
				{
					right--;
					tmp += nums[right];
				}
				else if (nums[left + 1] < 0)
				{
					right--;
					tmp += nums[right];
				}
				else if(nums[right - 1] > 0)
				{
					left++;
					tmp -= nums[left];
				}
			}
			else if (tmp < 0)
			{
				if (nums[right - 1] >= 0)
				{
					right--;
					tmp += nums[right];
				}
				else if (nums[left + 1] <= 0)
				{
					left++;
					tmp -= nums[left];
				}
				else if (nums[right - 1] < 0)
				{
					left++;
					tmp -= nums[left];
				}
				else if (nums[left + 1] > 0)
				{
					right--;
					tmp += nums[right];
				}
			}	
		}
		return -1;
	}
};
int main()
{
	vector<int> v{ -1,-1,-1,-1,1,-1 };
	Solution s;
	cout<<s.pivotIndex(v);
	system("pause");
	return 0;

}