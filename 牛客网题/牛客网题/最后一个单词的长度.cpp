#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s)
	{
		string ret;
		reverse(s.begin(), s.end());
		s.push_back(' ');
		size_t i = 0;
		while (i < s.size())
		{
			int pos = s.find(' ', i);
			if (pos != string::npos)
			{
				ret = s.substr(i, pos - i);
				if (ret.size() != 0)
					break;
			}
			i = pos + 1;
		}
		return ret.size();
	}
};
int main()
{
	string s("a b c");
	string ret;
	stringstream ss(s);
	for(size_t i=0;i<s.size();i++)
		ss >> ret;
	system("pause");
	return 0;

}