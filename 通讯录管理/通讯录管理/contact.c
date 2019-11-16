#include"contact.h"
void save_Info(contact* pc)
{
	assert(pc);
	FILE* p = fopen("contact.dat", "wb");
	if (p == NULL)
	{
		return;
	}
	while (pc->sz)
	{
		fwrite(pc->pep, sizeof(PeoInfo), 1, p);
		(pc->sz)--;
	}
	fclose(p);
	p = NULL;
}
void EXIT_Info(contact* pc)
{
	save_Info(pc);
	assert(pc);
	free(pc->pep);
	pc->pep = NULL;
}
void read_Info(contact* pc)
{
	assert(pc);
	PeoInfo tmp = { 0 };
	FILE* p = fopen("contact.dat", "rb");
	if (p == NULL)
	{
		return;
	}
	while (fread(&tmp, sizeof(PeoInfo), 1, p))
	{
		//动态
		if (pc->sz >= pc->count)
		{
			PeoInfo* str = NULL;
			str = (PeoInfo*)realloc(pc->pep, pc->count * 2 * sizeof(PeoInfo));
			if (str == NULL)
			{
				exit(1);
			}
			printf("扩容成功\n");
			pc->pep = str;
			str = NULL;
			pc->count = pc->count * 2;
		}
		pc->pep[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(p);
	p = NULL;
}
void Init_Info(contact* pc)
{
	assert(pc);
	int i = 0;
	//动态
	pc->count = 3;
	pc->pep = (PeoInfo*)malloc(pc->count* sizeof(PeoInfo));
	if (pc->pep == NULL)
	{
		exit(1);
	}
	pc->sz = 0;
	for (i = 0; i < pc->count; i++)
	{
		pc->pep[i].name[20] = 0;
		pc->pep[i].age = 0;
		pc->pep[i].sex[5] = 0;
		pc->pep[i].addr[25] = 0;
		pc->pep[i].tele[15] = 0;
	}
	read_Info(pc);
	//静态
	//for (i=0; i < 1000; i++)
	//{
	//	pc->pep[i].name[20] = 0;
	//	pc->pep[i].age = 0;
	//	pc->pep[i].sex[5] = 0;
	//	pc->pep[i].addr[25] = 0;
	//	pc->pep[i].tele[15] = 0;
	//}
	//pc->sz = 0;
}
void ADD_Info(contact* pc)
{
	assert(pc);
	//动态
	if (pc->sz >= pc->count)
	{
		PeoInfo* str = NULL;
		str = (PeoInfo*)realloc(pc->pep,pc->count*2 * sizeof(PeoInfo));
		if (str == NULL)
		{
			exit(1);
		}
		printf("扩容成功\n");
		pc->pep = str;
		str = NULL;
		pc->count = pc->count * 2;
	}
	else
	{
		char name1[20] = { 0 };
		char sex1[6] = { 0 };
		char addr1[25] = { 0 };
		char tele1[15] = { 0 };
		printf("请输入姓名:>");
		scanf("%s", name1);
		printf("请输入年龄:>");
		scanf("%d", &pc->pep[pc->sz].age);
		printf("请输入性别:>");
		scanf("%s", sex1);
		printf("请输入住址:>");
		scanf("%s", addr1);
		printf("请输入电话:>");
		scanf("%s", tele1);
		strcpy(pc->pep[pc->sz].name, name1);
		strcpy(pc->pep[pc->sz].sex, sex1);
		strcpy(pc->pep[pc->sz].addr, addr1);
		strcpy(pc->pep[pc->sz].tele, tele1);
		printf("添加成功\n");
		pc->sz++;
	}
	//静态
	/*if (pc->sz >= 1000)
	{
		printf("人数已满，不能继续添加\n");
		return;
	}
		static int i = 0;
		if (i < 1000)
		{
			char name1[20] = { 0 };
			char sex1[6] = { 0 };
			char addr1[25] = { 0 };
			char tele1[15] = { 0 };
			printf("请输入姓名:>");
			scanf("%s", name1);
			printf("请输入年龄:>");
			scanf("%d", &pc->pep[i].age);
			printf("请输入性别:>");
			scanf("%s", sex1);
			printf("请输入住址:>");
			scanf("%s", addr1);
			printf("请输入电话:>");
			scanf("%s", tele1);
			strcpy(pc->pep[i].name, name1);
			strcpy(pc->pep[i].sex, sex1);
			strcpy(pc->pep[i].addr, addr1);
			strcpy(pc->pep[i].tele, tele1);
			printf("添加成功\n");
			pc->sz++;
			i++;
		}*/
}
void SHOW_Info(contact *pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-s\t%-5s\t%-25s\t%-15s\n", "姓名","年龄","性别","地址","电话");
	for (i = 0; i < (pc->sz); i++)
	{
		printf("%-20s\t", pc->pep[i].name);
		printf("%-d\t", pc->pep[i].age);
		printf("%-5s\t", pc->pep[i].sex);
		printf("%-25s\t", pc->pep[i].addr);
		printf("%-15s\n", pc->pep[i].tele);
	}
}
int SEARCH_Info(contact *pc)
{
	assert(pc);
	printf("请输入姓名:>");
	char name1[20] = { 0 };
	scanf("%s", name1);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->pep[i].name, name1) == 0)
		{
			printf("找到了\n");
			printf("%-20s\t", pc->pep[i].name);
			printf("%-d\t", pc->pep[i].age);
			printf("%-5s\t", pc->pep[i].sex);
			printf("%-25s\t", pc->pep[i].addr);
			printf("%-15s\n", pc->pep[i].tele);
			return i;
		}
	}
	return -1;
	printf("找不到\n");
}
void DEL_Info(contact* pc)
{
	assert(pc);
	int i = 0;
	int ret=SEARCH_Info(pc);
	if (ret != -1)
	{
		for (i = ret ; i < pc->sz-1; i++)
		{
			pc->pep[i] = pc->pep[i + 1];
		}
		(pc->sz)--;
		printf("删除成功\n");
	}
	else
		printf("要删除的成员不存在\n");
}
void MODIFY_Info(contact* pc)
{
	assert(pc);
	int ret = SEARCH_Info(pc);
	if (ret != -1)
	{
		char name1[20] = { 0 };
		char sex1[6] = { 0 };
		char addr1[25] = { 0 };
		char tele1[15] = { 0 };
		printf("请输入修改的姓名:>");
		scanf("%s", name1);
		printf("请输入修改的年龄:>");
		scanf("%d", &pc->pep[ret].age);
		printf("请输入修改的性别:>");
		scanf("%s", sex1);
		printf("请输入修改的住址:>");
		scanf("%s", addr1);
		printf("请输入修改的电话:>");
		scanf("%s", tele1);
		strcpy(pc->pep[ret].name, name1);
		strcpy(pc->pep[ret].sex, sex1);
		strcpy(pc->pep[ret].addr, addr1);
		strcpy(pc->pep[ret].tele, tele1);
		printf("修改成功\n");
	}
	else
		printf("要修改的成员不存在\n");

}
void EMPTY_Info(contact* pc)
{
	assert(pc);
	pc->sz = 0;
	printf("清空成功\n");
}
int com_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
void SORT_Info(contact* pc)
{
	assert(pc);

	qsort(pc->pep, pc->sz, sizeof(pc->pep[0]), com_by_name);
	printf("排序成功!");
}

