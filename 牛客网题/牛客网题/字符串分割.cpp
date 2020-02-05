#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
	bool Find_str(const string& str, unordered_set<string> &dict)
	{
		auto it = dict.find(str);
		if (it != dict.end())
			return true;
		return false;
	}
public:
	bool wordBreak(string s, unordered_set<string> &dict)
	{
		bool flag = false;
		for (size_t i = 0, j = 1; i < s.size();j++)
		{
			string str = s.substr(i, j-i);
			flag = Find_str(str, dict);
			if (j < s.size())
				str = s.substr(j);
			if (flag && Find_str(str, dict))
				return true;
			if (flag)
				i = j;
		}
		return false;
	}
};

int main()
{
	Solution s;
	string str = "leetcodehello";
	unordered_set<string> dict = { "leet", "code","hello" };
	cout<<s.wordBreak(str, dict)<<endl;
	return 0;
}