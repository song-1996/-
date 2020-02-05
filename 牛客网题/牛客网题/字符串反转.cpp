#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}