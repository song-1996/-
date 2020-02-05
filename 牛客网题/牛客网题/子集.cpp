#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> ret;
		vector<int> tmp;
		ret.push_back(tmp);
		int end = 1;
		for (size_t j=0;j<nums.size();j++)
		{
			for (int i = 0; i < end; i++)
			{
				tmp = ret[i];
				tmp.push_back(nums[j]);
				ret.push_back(tmp);
			}
			end *= 2;
		}
		return ret;
	}
};
int main()
{
	vector<int> v{ 1,2,3 ,4};
	Solution s;
	s.subsets(v);
	system("pause");
	return 0;

}