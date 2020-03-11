#define _CRT_SECURE_NO_WARNINGS 1

/*
1209. 删除字符串中的所有相邻重复项 II
给你一个字符串 s，「k 倍重复项删除操作」将会从 s 中选择 k 个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。

你需要对 s 重复进行无限次这样的删除操作，直到无法继续为止。

在执行完所有删除操作后，返回最终得到的字符串。

本题答案保证唯一。



示例 1：

输入：s = "abcd", k = 2
输出："abcd"
解释：没有要删除的内容。
示例 2：

输入：s = "deeedbbcccbdaa", k = 3
输出："aa"
解释：
先删除 "eee" 和 "ccc"，得到 "ddbbbdaa"
再删除 "bbb"，得到 "dddaa"
最后删除 "ddd"，得到 "aa"
示例 3：

输入：s = "pbbcggttciiippooaais", k = 2
输出："ps"


提示：

1 <= s.length <= 10^5
2 <= k <= 10^4
s 中只含有小写英文字母。
*/
//解法1
class Solution {
	stack<pair<char, int>> sk;
public:
	string removeDuplicates(string s, int k)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			if (sk.empty() || s[i] != (sk.top().first))
			{
				sk.push(make_pair(s[i], 1));
			}
			else
			{
				if (s[i] == (sk.top().first))
					(sk.top().second)++;
				if ((sk.top().second) == k)
					sk.pop();
			}
		}
		string ret;
		while (!sk.empty())
		{
			int c = sk.top().second;
			string tmp;
			for (int i = 0; i < c; i++)
				tmp.push_back(sk.top().first);
			sk.pop();
			tmp += ret;
			ret = tmp;
		}
		return ret;
	}
};

//解法2
class Solution {
	stack<int> sk;
public:
	string removeDuplicates(string s, int k)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			if (sk.empty() || s[i] != s[i - 1])
				sk.push(1);
			else
			{
				sk.top()++;
				if (sk.top() == k)
				{
					s.erase(i - k + 1, k);
					sk.pop();
					i -= k;
				}
			}
		}
		return s;
	}
};

/*
面试题59 - I. 滑动窗口的最大值
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		multiset<int> mset;
		vector<int> ret;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (i >= k)
				mset.erase(mset.find(nums[i - k]));
			mset.insert(nums[i]);
			if (i >= k - 1)
				ret.push_back(*mset.rbegin());
		}
		return ret;
	}
};

/*
面试题59 - II. 队列的最大值
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入:
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入:
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]


限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5

*/

class MaxQueue {
	queue<int> q;
	deque<int> d;
public:
	MaxQueue() {}

	int max_value()
	{
		if (d.empty())
			return -1;
		return d.front();
	}

	void push_back(int value)
	{
		q.push(value);
		while (!d.empty() && value > d.back())
			d.pop_back();
		d.push_back(value);
	}

	int pop_front()
	{
		if (q.empty())
			return -1;
		int tmp = q.front();
		q.pop();
		if (tmp == d.front())
			d.pop_front();
		return tmp;
	}
};