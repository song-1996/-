#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k)
	{
		vector<int> buf;
		int i = nums.size() - 1;
		k = k % nums.size();
		int ck = k;
		while (k--)
		{
			buf.push_back(nums[i]);
			i--;
		}
		for (; i >= 0; i--)
			nums[i + ck] = nums[i];
		int j = 0;
		for (int i = buf.size() - 1; i >= 0; i--)
			nums[j++] = buf[i];
	}
};
int main()
{
	vector<int> v{ 1,2 };
	Solution s;
	s.rotate(v, 3);
	system("pause");
	return 0;

}