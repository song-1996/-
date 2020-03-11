#define _CRT_SECURE_NO_WARNINGS 1

/*
901. 股票价格跨度
编写一个 StockSpanner 类，它收集某些股票的每日报价，并返回该股票当日价格的跨度。

今天股票价格的跨度被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。

例如，如果未来7天股票的价格是 [100, 80, 60, 70, 60, 75, 85]，那么股票跨度将是 [1, 1, 1, 2, 1, 4, 6]。



示例：

输入：["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
输出：[null,1,1,1,2,1,4,6]
解释：
首先，初始化 S = StockSpanner()，然后：
S.next(100) 被调用并返回 1，
S.next(80) 被调用并返回 1，
S.next(60) 被调用并返回 1，
S.next(70) 被调用并返回 2，
S.next(60) 被调用并返回 1，
S.next(75) 被调用并返回 4，
S.next(85) 被调用并返回 6。

注意 (例如) S.next(75) 返回 4，因为截至今天的最后 4 个价格
(包括今天的价格 75) 小于或等于今天的价格。
*/
//单调栈解法
class StockSpanner {
	stack<pair<int, int>> s;
public:
	StockSpanner()
	{}

	int next(int price)
	{
		int ret = 1;
		while (!s.empty() && (s.top().first) <= price)
		{
			ret += s.top().second;
			s.pop();
		}
		s.push(make_pair(price, ret));
		return ret;
	}
};


/*
921. 使括号有效的最少添加
给定一个由 '(' 和 ')' 括号组成的字符串 S，我们需要添加最少的括号（ '(' 或是 ')'，可以在任何位置），以使得到的括号字符串有效。

从形式上讲，只有满足下面几点之一，括号字符串才是有效的：

它是一个空字符串，或者
它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
它可以被写作 (A)，其中 A 是有效字符串。
给定一个括号字符串，返回为使结果字符串有效而必须添加的最少括号数。



示例 1：

输入："())"
输出：1
示例 2：

输入："((("
输出：3
示例 3：

输入："()"
输出：0
示例 4：

输入："()))(("
输出：4


提示：

S.length <= 1000
S 只包含 '(' 和 ')' 字符。
*/

class Solution {
	stack<char> s;
public:
	int minAddToMakeValid(string S)
	{
		for (size_t i = 0; i < S.size(); i++)
		{
			if (!s.empty() && (S[i] == ')'&&s.top() == '('))
				s.pop();
			else
				s.push(S[i]);
		}
		return s.size();
	}
};