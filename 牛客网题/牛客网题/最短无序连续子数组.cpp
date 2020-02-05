#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums)
	{
		vector<int> buf(nums);
		sort(buf.begin(), buf.end());
		size_t left = 0, right = nums.size() - 1;
		for (; left < nums.size(); left++)
		{
			if (buf[left] != nums[left])
				break;
		}
		for (; left < nums.size(); right--)
		{
			if (buf[right] != nums[right])
				break;
		}
		return right - left + 1;
	}
};
int main()
{
	vector<int> v{ 1,3,2,2,2 };
	Solution s;
	cout<<s.findUnsortedSubarray(v);
	system("pause");
	return 0;

}