#define _CRT_SECURE_NO_WARNINGS 1

/*
994. 腐烂的橘子
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。



示例 1：



输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：

输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
*/
class Solution {
	queue<pair<int, int>> q;
	bool Is_Have(const vector<vector<int>>& grid)
	{
		for (size_t i = 0; i < grid.size(); i++)
		{
			for (size_t j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1)
					return true;
			}
		}
		return false;
	}
	bool Update(vector<vector<int>>& grid)
	{
		int size = q.size();
		int arr[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
		int flag = false;
		while (size--)
		{
			int x = q.front().first;
			int y = q.front().second;
			for (int i = 0; i < 4; i++)
			{
				int tx = x + arr[i][0];
				int ty = y + arr[i][1];
				if ((tx >= 0 && tx < grid.size()) && (ty >= 0 && ty < grid[0].size()))
				{
					if (grid[tx][ty] == 1)
					{
						grid[tx][ty] = 2;
						q.push(make_pair(tx, ty));
						flag = true;
					}
				}
			}
			q.pop();
		}
		return flag;
	}
public:
	int orangesRotting(vector<vector<int>>& grid)
	{
		for (size_t i = 0; i < grid.size(); i++)
		{
			for (size_t j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 2)
					q.push(make_pair(i, j));
			}
		}
		int count = 0;
		while (Update(grid))
			count++;
		if (Is_Have(grid))
			return -1;
		return count;
	}
};
/*
逆序对
*/

int sum = 0;
void Merge(vector<int>& nums, int left, int mid, int right)
{
	vector<int> buf;
	int lend = mid;
	int rend = right;
	int lstart = left;
	int rstart = mid + 1;
	while (lend >= lstart && rend >= rstart)
	{
		if (nums[lend] > nums[rend])
		{
			buf.push_back(nums[lend]);
			lend--;
			sum += rend - rstart + 1;
		}
		else
		{
			buf.push_back(nums[rend]);
			rend--;
		}
	}
	while (lend >= lstart)
	{
		buf.push_back(nums[lend]);
		lend--;
	}
	while (rend >= rstart)
	{
		buf.push_back(nums[rend]);
		rend--;
	}
	for (int i = 0; i < buf.size(); i++)
		nums[right--] = buf[i];
}
void _reversePairs(vector<int>& nums, int left, int right)
{
	if (left == right)
		return;
	int mid = left + ((right - left) >> 1);
	_reversePairs(nums, left, mid);
	_reversePairs(nums, mid + 1, right);
	Merge(nums, left, mid, right);
}