#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int i = 0;
		int j = 0;
		int index = 0;
		while (i < m && j < n)
		{
			if (nums1[i] <= nums2[j])
				nums1[index++] = nums1[i++];
			else
				nums1[index++] = nums2[j++];
		}
		while (i < m)
			nums1[index++] = nums1[i++];
		while (j < n)
			nums1[index++] = nums2[j++];
	}
};
int main()
{
	vector<int> v1{ 1,2,3,0,0,0 };
	vector<int> v2{ 2,5,6 };
	Solution s;
	s.merge(v1, 3, v2, 3);
	system("pause");
	return 0;

}