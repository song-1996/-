#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
////A选手说：B第二，我第三；
////B选手说：我第二，E第四；
////C选手说：我第一，D第二；
////D选手说：C最后，我第三；
////E选手说：我第四，A第一；
//int main()
//{
//	int A, B, C, D, E;
//	for (A = 1; A <= 5; A++)
//	{
//		for (B = 1; B <= 5; B++)
//		{
//			for (C = 1; C <= 5; C++)
//			{
//				for (D = 1; D <= 5; D++)
//				{
//					for (E = 1; E <= 5; E++)
//					{
//						/*if (((B == 2 && A != 3) || (B != 2 && A == 3)) &&
//							((B == 2 && E != 4) || (B != 2 && E == 4)) &&
//							((C == 1 && D != 2) || (C != 1 && D == 2)) &&
//							((C == 5 && D != 3) || (C != 5 && D == 3)) &&
//							((E == 4 && A != 1) || (E != 4 && A == 1)))*/
//						if(((B==2)+(A==3)==1)
//							&&((B==2)+(E==4)==1)
//							&&((C==1)+(D==2)==1)
//							&&((C==5)+(D==3)==1)
//							&&((E==4)+(A==1)==1))
//							if(A*B*C*D*E==120)
//							printf("A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);
//
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//
//}


//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//int main()
//{
//	char a;
//	for (a = 'A'; a < 'E'; a++)
//	{
//		if((a!='A'&&a=='C'&&a=='D'&&a=='D')
//			||(a != 'A'&&a == 'C'&&a != 'D'&&a != 'D')
//			|| (a != 'A'&&a != 'C'&&a == 'D'&&a != 'D')
//			|| (a == 'A'&&a == 'C'&&a == 'D'&&a != 'D'))
//			printf("%c\n", a);
//	}
//	
//	system("pause");
//	return 0;
//}


//#define N 10
//int main()
//{
//	int a[N][N];
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < N; i++)
//	{
//		a[i][0] = 1;
//		a[i][i] = 1;
//	}
//	for (i = 2; i < N; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//		}
//	}
//	for (i = 0; i < N; i++)
//	{
//		int k = 0;
//		for (k = 0; k < 4*(N - i) / 2; k++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%-4d", a[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}