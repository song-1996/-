#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Up_Down_arr(vector<int>& v, int k)
{
	vector<int> ret;
	size_t i, j;
	while (k--)
	{
		ret.clear();
		for (i = v.size() / 2 - 1, j = v.size() - 1; j >= v.size() / 2; i--, j--)
		{
			ret.push_back(v[j]);
			ret.push_back(v[i]);
		}
		reverse(ret.begin(), ret.end());
		v = ret;
	}
	for (i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v;
		v.resize(2*n);
		for (int i = 0; i < 2*n; i++)
			cin >> v[i];
		Up_Down_arr(v, k);
	}
	return 0;
}