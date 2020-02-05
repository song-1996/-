#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
//暴力法
/*
class Solution {
	bool Is_Palindrome(const string& str)
	{
		int left = 0;
		int right = str.size() - 1;
		while (left < right)
		{
			if (str[left] != str[right])
				return false;
			++left;
			--right;
		}
		return true;
	}
public:
	string longestPalindrome(string s)
	{
		string ret;
		for (int i = 0; i < (int)s.size(); i++)
		{
			if (ret.size() >= (s.size() - i))
				break;
			for (int j = s.size(); j > i; j--)
			{
				string str = s.substr(i, j - i);
				if (str.size() <= ret.size())
					break;
				if (Is_Palindrome(str) && str.size() > ret.size())
				{
					ret = str;
					break;
				}
			}
		}
		return ret;
	}
};
int main()
{
	Solution s;
	cout<<s.longestPalindrome("babad");
	system("pause");
	return 0;

}
*/

/*
#include<vector>
class Solution {
public:
	string longestPalindrome(string s)
	{
		vector<vector<bool>> buf(s.size(), vector<bool>(s.size(), false));
		for (int i = 0; i < (int)s.size(); i++)
			buf[i][i] = true;
		string ret;
		ret.push_back(s[0]);
		for (int i = s.size() - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < (int)s.size(); j++)
			{
				if ((s[i] == s[j] && buf[i + 1][j - 1])||
					(s[i] == s[j] && i+1==j ))
				{
					buf[i][j] = true;
					if (j - i + 1 > (int)ret.size())
						ret = s.substr(i, j - i + 1);
				}
			}
		}
		return ret;
	}
};
int main()
{
	Solution s;
	cout << s.longestPalindrome("babad");
	system("pause");
	return 0;
}
*/

//auto占位符
template<class T1,class T2>
auto Add(const T1& a, const T2& b)->decltype(a + b)
{
	return a + b;
}
int main()
{
	cout << Add(1, 2.0) << endl;
	return 0;
}