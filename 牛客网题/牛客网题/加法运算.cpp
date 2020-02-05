#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int Add(int num1, int num2)
{
	int ret = 0;
	do
	{
		ret = num2 ^ num1;
		num2 = ((num1&num2) << 1);
		num1 = ret;
	} while (num2);
	return ret;
}
int main()
{

	cout<<Add(20, 45)<<endl;
	return 0;

}