#define _CRT_SECURE_NO_WARNINGS 1

/*
1249. 移除无效的括号
给你一个由 '('、')' 和小写字母组成的字符串 s。

你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

请返回任意一个合法字符串。

有效「括号字符串」应当符合以下 任意一条 要求：

空字符串或只包含小写字母的字符串
可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」


示例 1：

输入：s = "lee(t(c)o)de)"
输出："lee(t(c)o)de"
解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
示例 2：

输入：s = "a)b(c)d"
输出："ab(c)d"
示例 3：

输入：s = "))(("
输出：""
解释：空字符串也是有效的
示例 4：

输入：s = "(a(b(c)d)"
输出："a(b(c)d)"


提示：

1 <= s.length <= 10^5
s[i] 可能是 '('、')' 或英文小写字母
*/

class Solution {
	stack<int> sk;
public:
	string minRemoveToMakeValid(string s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a'&&s[i] <= 'z')
				continue;
			if (sk.empty() || s[i] == '(')
				sk.push(i);
			else
			{
				if (!sk.empty() && s[sk.top()] == '(')
					sk.pop();
				else
					sk.push(i);
			}
		}
		while (!sk.empty())
		{
			s[sk.top()] = 'X';
			sk.pop();
		}
		for (size_t i = 0; i < s.size();)
		{
			if (s[i] == 'X')
				s.erase(i, 1);
			else
				i++;
		}
		return s;
	}
};


/*
1190. 反转每对括号间的子串
给出一个字符串 s（仅含有小写英文字母和括号）。

请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。

注意，您的结果中 不应 包含任何括号。
示例 1：

输入：s = "(abcd)"
输出："dcba"
示例 2：

输入：s = "(u(love)i)"
输出："iloveu"
示例 3：

输入：s = "(ed(et(oc))el)"
输出："leetcode"
示例 4：

输入：s = "a(bcdefghijkl(mno)p)q"
输出："apmnolkjihgfedcbq"
 

提示：

0 <= s.length <= 2000
s 中只有小写英文字母和括号
我们确保所有括号都是成对出现的

*/

class Solution {
	stack<int> sk;
public:
	string reverseParentheses(string s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a'&&s[i] <= 'z')
				continue;
			if (sk.empty() || s[i] == '(')
			{
				sk.push(i);
			}
			else
			{
				if (!sk.empty() && s[sk.top()] == '(')
				{
					auto left = s.begin() + (sk.top() + 1);
					auto right = s.begin() + i;
					reverse(left, right);
				}
				s[i] = 'X';
				s[sk.top()] = 'X';
				sk.pop();
			}
		}
		for (size_t i = 0; i < s.size();)
		{
			if (s[i] == 'X')
				s.erase(i, 1);
			else
				i++;
		}
		return s;
	}
};