#include"SequenList.h"
int main()
{
	SequenList s;
	InitSequenList(&s);
	int x = 0;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &x);
		PushSequenList(&s, x);
	}
	int max=GetMax(&s);
	int maxpos=GetMaxPos(&s);
	printf("max=%d,maxpos=%d", max, maxpos);
	PushSequenListX(&s, 3, 1);
	DestroySequenList(&s);
	system("pause");
	return 0;

}