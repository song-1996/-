#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int> Max_(vector<int>& v, int w)
{
	if (w <= 0 || v.size() < w||v.size()==0)
		return v;
	deque<int> d;
	vector<int> ret;
	for (size_t i = 0; i < v.size(); i++)
	{
		while(!d.empty()&&v[d.back()] <= v[i])
			d.pop_back();
		d.push_back(i);
		if (d.front() == i - w)
			d.pop_front();
		if (i >= w - 1)
			ret.push_back(v[d.front()]);
	}
	return ret;
}
int main()
{
	int n, w;
	cin >> n >> w;
	vector<int> v;
	while (n--)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	vector<int> ret = Max_(v, w);
	for (size_t i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;
	system("pause");
	return 0;

}