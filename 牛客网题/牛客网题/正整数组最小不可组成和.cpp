#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int Min_No_Sum(vector<int> v, int n)
{
	int max = v[0];
	int min = v[0];
	for (int i = 1; i < n; i++)
	{
		if (v[i] < min)
			min = v[i];
		max += v[i];
	}
	vector<vector<int>> buf(n + 1, vector<int>(max + 1, 0));
	for (int i = 0; i < n + 1; i++)
		buf[i][0] = 1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < max + 1; j++)
		{
			if (v[i - 1] > j || buf[i - 1][j] != 0)
				buf[i][j] = buf[i - 1][j];
			else
				buf[i][j] = buf[i - 1][j - v[i - 1]];

		}
	}
	for (int i = min; i < max + 1; i++)
	{
		if (buf[n][i] == 0)
			return i;
	}
	return max + 1;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << Min_No_Sum(v, n) << endl;
	}
	return 0;
}