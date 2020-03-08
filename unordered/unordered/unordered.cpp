#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> v(arr,arr+9);
	map<int, int> m1;
	for (int i = 0; i < (int)v.size(); i++)
	{
		m1.insert(pair<int, int>(v[i], i));
	}
	system("pause");
	return 0;

}