#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
void Cursor_Status(int n, const string& str)
{
	int cur = 1;
	int k = 0;
	int top = 1;
	if (n <= 4)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == 'U'&&cur == 1)
				cur = n;
			else if (str[i] == 'D'&&cur == n)
				cur = 1;
			else
			{
				if (str[i] == 'U')
					cur--;
				else
					cur++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ' ';
		}
		cout << endl;
		cout << cur << endl;
	}
	else
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == 'U'&&cur == 1 && top == 1)
			{
				top = n - 3;
				cur = n;
			}
			else if (str[i] == 'D'&&cur == n && top == n - 3)
			{
				top = 1;
				cur = 1;
			}
			else if (str[i] == 'U' && top != 1 && cur == top)
			{
				top--;
				cur--;
			}
			else if (str[i] == 'D'&&top != n - 3&&cur == top + 3)
			{
				top++;
				cur++;
			}
			else if (str[i] == 'U')
				cur--;
			else
				cur++;
		}
		int i;
		for (i = top; i < top + 3; i++)
		{
			cout << i << ' ';
		}
		cout << i << endl;
		cout << cur << endl;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		string str;
		cin >> str;
		Cursor_Status(n, str);
	}
	return 0;
}