#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	 *  ����λ�϶�����������ż��λ�϶���ż��
	 *  ���룺����arr�����ȴ���2
	 *  len��arr�ĳ���
	 *  ��arr����������λ�϶�����������ż��λ�϶���ż��
	 */
	void oddInOddEvenInEven(vector<int>& arr, int len)
	{
		bool flag = false;
		for (int i = 0; i < len - 1; i += 2)
		{
			if (arr[i] % 2 != 0)
			{
				for (int j = i + 1; j < len; j += 2)
				{
					if (arr[j] % 2 == 0)
					{
						swap(arr[i], arr[j]);
						flag = true;
						break;
					}
				}
				if (flag == false)
					return;
			}
		}
	}
};
int main()
{
	int arr[] = { 1,6,8,9,7,3,2,4,5,10 };
	vector<int> v(arr,arr+10);
	Solution s;
	s.oddInOddEvenInEven(v, 10);
	system("pause");
	return 0;

}