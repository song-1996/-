#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void Get_Max_award(vector<int>& di, vector<int>& ai)
{
	vector<pair<int, int>> tmp;
	for (size_t i = 0; i < di.size(); i += 2)
		tmp.push_back(make_pair(di[i+1], di[i]));
	sort(tmp.begin(), tmp.end());
	for (size_t i = 0; i < ai.size(); i++)
	{
		for (int j = tmp.size() - 1; j >= 0; j--)
		{
			if (ai[i] >= tmp[j].second)
			{
				ai[i] = tmp[j].first;
				break;
			}
		}
	}
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> di(2 * n, 0);
		vector<int> ai(m, 0);
		for (int i = 0; i < 2 * n; i++)
			cin >> di[i];
		for (int i = 0; i < m; i++)
			cin >> ai[i];
		Get_Max_award(di, ai);
		for (int i = 0; i < m; i++)
			cout << ai[i] << endl;
	}
	return 0;
}