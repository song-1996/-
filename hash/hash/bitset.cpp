#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<bitset>
using namespace std;
int main()
{

	int arr[] = { 1,3,7,4,12,16,19,13,22,18 };
	bitset<23> bs;
	cout << bs.none() << endl;
	for (auto e : arr)
		bs.set(e);
	cout << bs[3] << endl;
	cout << bs.all() << endl;
	system("pause");
	return 0;

}