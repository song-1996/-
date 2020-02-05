#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> ret;
vector<int> v(2, 0);
void dfs(const vector<vector<int>>& vv, vector<vector<int>>& book,
	int x, int y, vector<vector<int>>& step)
{
	int next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int tx, ty;
	if (x == (int)vv.size() - 1 && y == vv[(int)vv.size() - 1].size() - 1)
	{
		if (step.size() < ret.size())
			ret = step;
		return;
	}
	for (int k = 0; k < 4; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx < 0 || tx >= (int)vv.size() || ty < 0 || ty >= (int)vv[0].size())
			continue;
		if (vv[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			v[0] = tx;
			v[1] = ty;
			step.push_back(v);
			dfs(vv, book, tx, ty, step);
			step.pop_back();
			book[tx][ty] = 0;
		}
	}
	return;
}
void min_step(const vector<vector<int>>& vv, vector<vector<int>>& book)
{
	book[0][0] = 1;
	vector<vector<int>> step;
	int x = 0;
	int y = 0;
	v[0] = x;
	v[1] = x;
	step.push_back(v);
	dfs(vv, book, x, y, step);
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		ret.resize(100);
		vector<vector<int>> vv(n, vector<int>(m, 0));
		vector<vector<int>> book(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> vv[i][j];
		}
		min_step(vv, book);
		for (int i = 0; i < (int)ret.size(); i++)
			cout << "(" << ret[i][0] << "," << ret[i][1] << ")" << endl;
	}
	return 0;
}