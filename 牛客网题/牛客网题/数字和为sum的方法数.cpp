#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
long long Count_find(vector<int> v, int x)
{
	vector<vector<long long>> buf(v.size() + 1, vector<long long>(x + 1));
	for (int i = 0; i < (int)v.size() + 1; i++)
		buf[i][0] = 1;
	for (int i = 1; i < (int)v.size() + 1; i++)
	{
		for (int j = 1; j < x + 1; j++)
		{
			if (v[i - 1] > j)
				buf[i][j] = buf[i - 1][j];
			else
				buf[i][j] = buf[i - 1][j] + buf[i - 1][j - v[i - 1]];
		}
	}
	return buf[v.size()][x];
}
int main()
{
	int n, x;
	while (cin >> n >> x)
	{
		vector<int> v;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << Count_find(v, x) << endl;
	}
	return 0;
}