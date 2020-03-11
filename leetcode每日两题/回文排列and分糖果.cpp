#define _CRT_SECURE_NO_WARNINGS 1

/*
面试题 01.04. 回文排列
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

回文串不一定是字典当中的单词。

示例1：

输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）
*/
//单调栈解法
class Solution {
public:
	bool canPermutePalindrome(string s)
	{
		char buf[128] = { 0 };
		for (size_t i = 0; i < s.size(); i++)
		{
			if (buf[s[i]] == 1)
				buf[s[i]]--;
			else
				buf[s[i]] = 1;
		}
		int count = 0;
		for (size_t i = 0; i < 128; i++)
		{
			if (buf[i] > 0)
				count++;
		}
		if (count == 0 || count == 1)
			return true;
		return false;
	}
};

/*
1103. 分糖果 II
排排坐，分糖果。

我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。

给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。

然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。

重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。

返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。



示例 1：

输入：candies = 7, num_people = 4
输出：[1,2,3,1]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0,0]。
第三次，ans[2] += 3，数组变为 [1,2,3,0]。
第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。
示例 2：

输入：candies = 10, num_people = 3
输出：[5,2,3]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0]。
第三次，ans[2] += 3，数组变为 [1,2,3]。
第四次，ans[0] += 4，最终数组变为 [5,2,3]。
*/

class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people)
	{
		vector<int> ret(num_people, 0);
		int k = 0;
		while (candies > 0)
		{
			for (int i = 0; candies > 0 && i < num_people; i++)
			{
				if (candies >= k + 1)
					ret[i%num_people] += k + 1;
				else
					ret[i%num_people] += candies;
				candies -= (k + 1);
				k++;
			}
		}
		return ret;
	}
};