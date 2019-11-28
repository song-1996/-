#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
/*
int Is_digal(char c)
{
	int a = c - '0';
	if (a >= 0 && a <= 9)
		return 1;
	return 0;
}
int Is_char_D(char c)
{
	if (c >= 'a'&&c <= 'z')
		return 1;
	return 0;
}
int Is_char_U(char c)
{
	if (c >= 'A'&&c <= 'Z')
		return 1;
	return 0;
}
int  is_zchar(char c)
{
	if ((c >= '!'&&c <= '/') ||
		(c >= ':'&&c <= '@') ||
		(c >= '['&&c <= '`') ||
		(c >= '{'&&c <= '~'))
		return 1;
	return 0;

}
int len(char* s)
{
	int len=strlen(s);
	if (len <= 4)
		return 5;
	else if (len >= 5 && len <= 7)
		return 10;
	else
		return 25;
}
int ischar(char* s)
{
	int u = 0;
	int d = 0;
	while (*s)
	{
		if (Is_char_D(*s))
		{	
			d = 1;
		}
		if (Is_char_U(*s))
		{
			u = 1;
		}
		s++;
	}
	if (d == 1 && u == 1)
		return 20;
	else if ((d == 1 && u == 0) || (d == 0 && u == 1))
		return 10;
	else
		return 0;
}
int isdigal(char* s)
{
	int count = 0;
	while (*s)
	{
		if (Is_digal(*s))
		{
			count++;
		}
		s++;
	}
	if (count == 1)
		return 10;
	else if (count > 1)
		return 20;
	else
	return 0;
}
int iszchar(char* s)
{
	int count = 0;
	int ret = 0;
	while (*s)
	{	
		if (is_zchar(*s))
		{
			count++;
		}
		s++;
	}
	if (count == 1)
		ret= 10;
	else if (count > 1)
		ret= 25;
	else
		ret= 0;
	return ret;
}
int prize(char* s)
{
	int d = 0;
	int c = 0;
	int zc = 0;
	int ud = 0;
	int ret = 0;
	while (*s)
	{
		if (Is_digal(*s))
		{
			d = 1;
		}
		else if (Is_char_D(*s))
		{
			c = 1;
			ud = 1;
		}
		else if (Is_char_U(*s))
		{
			c = 1;
			ud = 1;
		}
		else
			if (is_zchar(*s))
			{
				zc = 1;
			}
		s++;
	}
	if (d == 1 && c == 1&&zc==0)
		ret= 2;
	else if (d == 1 && c == 1 && zc == 1&&ud==0)
		ret= 3;
	else if (ud == 1 && d == 1 && zc == 1)
		ret= 5;
	return ret;
}
int GetPwdSecurityLevel(char* pPasswordStr)
{
	assert(pPasswordStr);
	int sum = 0;
	sum+=len(pPasswordStr);
	sum += ischar(pPasswordStr);
	sum += isdigal(pPasswordStr);
	sum += iszchar(pPasswordStr);
	sum += prize(pPasswordStr);
	return sum;
}
int main()
{
	char pPasswordStr[10000] = { 0 };
	while (scanf("%s", pPasswordStr) != EOF)
	{
		int ret = GetPwdSecurityLevel(pPasswordStr);
		if (ret >= 90)
			printf("VERY_SECURE\n");
		else if (ret >= 80)
			printf("SECURE\n");
		else if (ret >= 70)
			printf("VERY_STRONG\n");
		else if (ret >= 60)
			printf("STRONG\n");
		else if (ret >= 50)
			printf("AVERAGE\n");
		else if (ret >= 25)
			printf("WEAK\n");
		else
			printf("VERY_WEAK\n");
	}
		system("pause");
		return 0;
}

*/

int Is_digal(char c)
{
	int a = c - '0';
	if (a >= 0 && a <= 9)
		return 1;
	return 0;
}
int Is_char_D(char c)
{
	if (c >= 'a'&&c <= 'z')
		return 1;
	return 0;
}
int Is_char_U(char c)
{
	if (c >= 'A'&&c <= 'Z')
		return 1;
	return 0;
}
int  is_zchar(char c)
{
	if ((c >= '!'&&c <= '/') ||
		(c >= ':'&&c <= '@') ||
		(c >= '['&&c <= '`') ||
		(c >= '{'&&c <= '~'))
		return 1;
	return 0;

}
int GetPwdSecurityLevel(char* pPasswordStr)
{
	assert(pPasswordStr);
	int sum = 0;
	int dg = 0;
	int ch = 0;
	int zch = 0;
	int flag_U = 0;
	int flag_D = 0;
	int len = strlen(pPasswordStr);
	if (len <= 4)
		sum += 5;
	else if (len >= 5 && len <= 7)
		sum += 10;
	else
		sum += 25;
	while (*pPasswordStr)
	{
		if (Is_digal(*pPasswordStr))
		{
			static int count_d = 0;
			if (count_d < 2)
				sum += 10;
			count_d++;
			dg = 1;
		}
		else if ((Is_char_D(*pPasswordStr)) || Is_char_U(*pPasswordStr))
		{
			static int d = 0;
			static int u = 0;
			static int count_c = 0;
			static int sz = 1;
			if (Is_char_D(*pPasswordStr))
			{
				d++;
				flag_D = 1;
			}
			if (Is_char_U(*pPasswordStr))
			{
				u++;
				flag_U = 1;
			}
			if (count_c < 1)
				sum += 10;
			count_c++;
			if (d != 0 && u != 0 && sz)
			{
				sum += 10;
				sz--;
			}
			ch = 1;
		}
		else
		{
			static int count_zch = 0;
			if (count_zch < 2)
			{
				sum += 10;
				if (count_zch == 1)
					sum += 5;
			}
			count_zch++;
			zch = 1;
		}
		pPasswordStr++;
	}
	if (dg == 1 && ch == 1 && zch == 0)
		sum += 2;
	else if (ch == 1 && dg == 1 && zch == 1 && (flag_U == 0 || flag_D == 0))
		sum += 3;
	else if (ch == 1 && dg == 1 && zch == 1 && flag_U == 1 && flag_D == 1)
		sum += 5;
	return sum;
}
int main()
{
	char pPasswordStr[1000] = { 0 };
	while (scanf("%s", pPasswordStr) != EOF)
	{
		int ret = GetPwdSecurityLevel(pPasswordStr);
		if (ret >= 90)
			printf("VERY_SECURE\n");
		else if (ret >= 80)
			printf("SECURE\n");
		else if (ret >= 70)
			printf("VERY_STRONG\n");
		else if (ret >= 60)
			printf("STRONG\n");
		else if (ret >= 50)
			printf("AVERAGE\n");
		else if (ret >= 25)
			printf("WEAK\n");
		else
			printf("VERY_WEAK\n");
		system("pause");
		return 0;
	}
}