#define _CRT_SECURE_NO_WARNINGS 1

/*
153. 寻找旋转排序数组中的最小值
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0
*/
class Solution {
public:
	int findMin(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		int anl = -1, anr = -1;
		while (left <= right && anl + 1 != anr)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] >= nums[0])
			{
				anl = mid;
				left = mid + 1;
			}
			else
			{
				anr = mid;
				right = mid - 1;
			}
		}
		if (left > nums.size() - 1)
			return nums[0];
		return nums[anr];
	}
};

/*
162. 寻找峰值
峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

示例 1:

输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
示例 2:

输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5
解释: 你的函数可以返回索引 1，其峰值元素为 2；
	 或者返回索引 5， 其峰值元素为 6。
*/

class Solution {
public:
	int findPeakElement(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] > nums[mid + 1])
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};

/*
154. 寻找旋转排序数组中的最小值 II
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例 2：

输入: [2,2,2,0,1]
输出: 0*/

class Solution {
public:
	int findMin(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] > nums[right])
				left = mid + 1;
			else if (nums[mid] < nums[right])
				right = mid;
			else
				right--;
		}
		return nums[left];
	}
};