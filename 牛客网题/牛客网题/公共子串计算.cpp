#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void StringToUppper(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
}
int GetCommonStrLength(string& str1, string& str2)
{
	string ret;
	if (str1.size() < str2.size())
		str1.swap(str2);
	for (size_t j = 0; j < str2.size() - 1; j++)
	{
		for (size_t i = str2.size(); i > 0; i--)
		{
			string key = str2.substr(j, i - j);
			size_t pos = str1.find(key);
			if (string::npos != pos)
			{
				if (key.size() > ret.size())
					ret = key;
			}
		}
	}
	return (int)ret.size();
}
int main()
{
	string str1;
	string str2;
	while (cin>>str1>>str2)
	{
		StringToUppper(str1);
		StringToUppper(str2);
		cout << GetCommonStrLength(str1, str2) << endl;
	}
	return 0;
}