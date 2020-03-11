#define _CRT_SECURE_NO_WARNINGS 1

/*
209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例:

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
*/

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		size_t prev = 0, postv = 0;
		size_t Min = INT_MAX;
		while (postv < nums.size())
		{
			int sum = 0;
			for (size_t i = prev; i <= postv; i++)
				sum += nums[i];
			if (sum < s)
			{
				postv++;
			}
			else
			{
				size_t tmp = (postv - prev + 1);
				Min = min(Min, tmp);
				prev++;
			}
		}
		if (Min < INT_MAX)
			return Min;
		return 0;
	}
};

/*
278. 第一个错误的版本
你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例:

给定 n = 5，并且 version = 4 是第一个错误的版本。

调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true

所以，4 是第一个错误的版本。
*/

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n)
	{
		int al = 0;
		int left = 1, right = n;
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (isBadVersion(mid))
			{
				al = mid;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		return al;
	}
};
/*

你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。

示例：

输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]

*/

class Solution {
	queue<pair<int, int>> q;
	int arr[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0,},{1,-1},{0,-1},{-1,-1} };
	int Search_land(vector<vector<int>>& land)
	{
		int count = 0;
		while (!q.empty())
		{
			count++;
			int tx = q.front().first;
			int ty = q.front().second;
			land[tx][ty] = 1;
			for (int i = 0; i < 8; i++)
			{
				int nx = tx + arr[i][0];
				int ny = ty + arr[i][1];
				if ((nx >= 0 && nx < land.size()) && ny >= 0 && ny < land[0].size())
				{
					if (land[nx][ny] == 0)
					{
						q.push(make_pair(nx, ny));
						land[nx][ny] = 1;
					}
				}
			}
			q.pop();
		}
		return count;
	}
public:
	vector<int> pondSizes(vector<vector<int>>& land)
	{
		vector<int> ret;
		for (size_t i = 0; i < land.size(); i++)
		{
			for (size_t j = 0; j < land[0].size(); j++)
			{
				if (land[i][j] == 0)
				{
					q.push(make_pair(i, j));
					ret.push_back(Search_land(land));
				}
			}
		}
		sort(ret.begin(), ret.end());
		return ret;
	}
};