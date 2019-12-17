#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//int* addToArrayForm(int *arr, int sz, int k,int *arr1)
//{
//	assert(arr);
//	assert(arr1);
//	int* end = arr;
//	int sz1 = sz;
//	int t = 1;
//	int s = 0;
//	int n = 0;
//	while (sz--)
//	{
//		n=*(end + sz) * t;
//		s = s + n;
//		t = t * 10;
//	}
//	s = s + k;
//	int* right = arr1;
//	while (sz1--)
//	{
//		*(arr1 + sz1) = s % 10;
//		s = s / 10;
//	}
//	return arr1;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 1 };
//	int arr1[10];
//	int k = 34;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	addToArrayForm(arr, sz, k,arr1);
//	system("pause");
//	return 0;
//
//}

//int lengthOfLastWord(char* s)
//{
//	assert(s);
//	char* cur = s;
//	char* start = s;
//	int count = 0;
//	while (*cur)
//	{
//		start = cur;
//		while (*cur != ' '&&*cur!='\0')
//		{
//			cur++;
//		}
//		count = cur - start;
//		while (*cur == ' ')
//		{
//			cur++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	char* a = "a   ";
//	lengthOfLastWord(a);
//	system("pause");
//	return 0;
//}
//int isLongPressedName(char* name, char* typed)
//{
//	assert(name);
//	assert(typed);
//		while (*name == *typed)
//		{
//			typed++;
//			if (*(name + 1) == *typed)
//			{
//				name++;
//				if (*name == '/0'&&*typed == '\0')
//				{
//					return 1;
//				}
//			}
//		}
//	return 0;
//}
//int main()
//{
//	char* s1 = "saeed";
//	char* s2 = "ssaaedd";
//	isLongPressedName(s1, s2);
//	system("pause");
//	return 0;
//}
//char* reverseOnlyLetters(char* S)
//{
//	assert(S);
//	int sz = strlen(S);
//	char* right = S + sz - 1;
//	char* left = S;
//	while (left < right)
//	{
//		if (((*left >= 'a'&&*left <= 'z') || (*left >= ' A '&& *left <='Z')) &&
//			((*right>='a'&&*right<='z') || (*right >= 'A'&&*right <= 'Z')))
//		{
//			char tmp = *left;
//			*left = *right;
//			*right = tmp;
//		}
//		else if (!((*left >= 'a'&&*left <= 'z') || (*left >= ' A '&& *left <= 'Z')) &&
//			((*right >= 'a'&&*right <= 'z') || (*right >= 'A'&&*right <= 'Z')))
//		{
//			left++;
//		}
//		else if (((*left >= 'a'&&*left <= 'z') || (*left >= ' A '&& *left <= 'Z')) &&
//			!((*right >= 'a'&&*right <= 'z') || (*right >= 'A'&&*right <= 'Z')))
//		{
//			right++;
//		}
//		else
//		{
//			left++;
//			right--;
//		}
//	}
//	return  S;
//}
//int main()
//{
//	char* s = "a-bC-dEf-ghIj";
//	reverseOnlyLetters(s);
//	system("pause");
//	return 0;
//}

//char* reverseOnlyLetters(char* S)
//{
//	assert(S);
//	int sz = strlen(S);
//	int lift = 0;
//	int right = sz - 1;
//	while (lift < right)
//	{
//		if ((S[lift]<'a'&&S[lift]>'z') || (S[lift]<'A'&&S[lift]>'Z'))
//			continue;
//		if ((S[right]<'a'&&S[right]>'z') || (S[right]<'A'&&S[right]>'Z'))
//			continue;
//		char tmp = S[lift];
//		S[lift] = S[right];
//		S[right] = tmp;
//		lift++;
//		right++;
//	}
//	return  S;
//}
//int main()
//{
//	char* s = "a-bC-dEf-ghIj";
//	reverseOnlyLetters(s);
//	system("pause");
//	return 0;
//}

//int removeElement(int* nums, int numsSize, int val)
//{
//	if (numsSize == 0)
//		return 0;
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	int count = 0;
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		flag = 0;
//		for (j = 0; j < numsSize - 1 - i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				int tmp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = tmp;
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//			break;
//	}
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == val)
//		{
//			count++;
//		}
//	}
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == val)
//		{
//			for (j = i; j < numsSize; j++)
//			{
//				if (nums[j] != nums[i])
//				{
//					nums[i] = nums[j];
//					i++;
//				}
//			}
//			break;
//		}
//	}
//	return numsSize-count;
//
//}
//int main()
//{
//	int arr[] = { 0,1,2,2,3,0,4,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int key = 2;
//	printf("%d\n", removeElement(arr, sz,key));
//	system("pause");
//	return 0;
//}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	returnSize = (int*)malloc(sizeof(int)*digitsSize);
	int i = 0;
	int n = 0;
	for (i = 0; i < digitsSize; i++)
	{
		int sz = digitsSize;
		while (sz - i - 1 > 0)
		{
			digits[i] = digits[i] * 10;
			sz--;
		}
		n = n + digits[i];
	}
	n = n + 1;
	for (i = digitsSize - 1; i >= 0; i--)
	{
		returnSize[i] = n % 10;
		n = n / 10;
	}
	return returnSize;
}
int main()
{
	int arr[] = { 4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	plusOne(arr, sz, 100);
	system("pause");
	return 0;
}