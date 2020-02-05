#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
class NumArray {
private:
	vector<int> buf;
public:
	NumArray(vector<int>& nums)
	{
		buf.resize(nums.size());
		memcpy(&buf, &nums, sizeof(nums[0])*nums.size());
		for (size_t i = 1; i < nums.size(); i++)
			buf[i] += buf[i - 1];
	}

	int sumRange(int i, int j)
	{
		if (i == 0)
			return buf[j];
		return buf[j] - buf[i - 1];
	}
};
int main()
{
	vector<int> v{ -2, 0, 3, -5, 2, -1 };
	NumArray n(v);
	cout << n.sumRange(0, 2) << endl;
	cout << n.sumRange(2,5) << endl;
	cout << n.sumRange(0, 5) << endl;
	return 0;
}