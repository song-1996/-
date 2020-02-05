#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int Count_find(vector<int> v, int x)
{
	int key = x;
	int count = 0;
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		for (size_t k = i + 1; k < v.size(); k++)
		{
			key = x;
			key -= v[i];
			if (key == 0)
			{
				count++;
				break;
			}
			for (size_t j = k; j < v.size(); j++)
			{
				if (key >= v[j])
				{
					key -= v[j];
					if (key == 0)
					{
						count++;
						key = x;
						break;
					}
				}
				else
					continue;
			}
		}
	}
	return count;
}
int main()
{
	int n, x;
	while (cin >> n >> x)
	{
		vector<int> v;
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		cout << Count_find(v, x) << endl;
	}
	return 0;
}