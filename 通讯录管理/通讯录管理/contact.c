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
		//��̬
		if (pc->sz >= pc->count)
		{
			PeoInfo* str = NULL;
			str = (PeoInfo*)realloc(pc->pep, pc->count * 2 * sizeof(PeoInfo));
			if (str == NULL)
			{
				exit(1);
			}
			printf("���ݳɹ�\n");
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
	//��̬
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
	//��̬
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
	//��̬
	if (pc->sz >= pc->count)
	{
		PeoInfo* str = NULL;
		str = (PeoInfo*)realloc(pc->pep,pc->count*2 * sizeof(PeoInfo));
		if (str == NULL)
		{
			exit(1);
		}
		printf("���ݳɹ�\n");
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
		printf("����������:>");
		scanf("%s", name1);
		printf("����������:>");
		scanf("%d", &pc->pep[pc->sz].age);
		printf("�������Ա�:>");
		scanf("%s", sex1);
		printf("������סַ:>");
		scanf("%s", addr1);
		printf("������绰:>");
		scanf("%s", tele1);
		strcpy(pc->pep[pc->sz].name, name1);
		strcpy(pc->pep[pc->sz].sex, sex1);
		strcpy(pc->pep[pc->sz].addr, addr1);
		strcpy(pc->pep[pc->sz].tele, tele1);
		printf("��ӳɹ�\n");
		pc->sz++;
	}
	//��̬
	/*if (pc->sz >= 1000)
	{
		printf("�������������ܼ������\n");
		return;
	}
		static int i = 0;
		if (i < 1000)
		{
			char name1[20] = { 0 };
			char sex1[6] = { 0 };
			char addr1[25] = { 0 };
			char tele1[15] = { 0 };
			printf("����������:>");
			scanf("%s", name1);
			printf("����������:>");
			scanf("%d", &pc->pep[i].age);
			printf("�������Ա�:>");
			scanf("%s", sex1);
			printf("������סַ:>");
			scanf("%s", addr1);
			printf("������绰:>");
			scanf("%s", tele1);
			strcpy(pc->pep[i].name, name1);
			strcpy(pc->pep[i].sex, sex1);
			strcpy(pc->pep[i].addr, addr1);
			strcpy(pc->pep[i].tele, tele1);
			printf("��ӳɹ�\n");
			pc->sz++;
			i++;
		}*/
}
void SHOW_Info(contact *pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-s\t%-5s\t%-25s\t%-15s\n", "����","����","�Ա�","��ַ","�绰");
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
	printf("����������:>");
	char name1[20] = { 0 };
	scanf("%s", name1);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->pep[i].name, name1) == 0)
		{
			printf("�ҵ���\n");
			printf("%-20s\t", pc->pep[i].name);
			printf("%-d\t", pc->pep[i].age);
			printf("%-5s\t", pc->pep[i].sex);
			printf("%-25s\t", pc->pep[i].addr);
			printf("%-15s\n", pc->pep[i].tele);
			return i;
		}
	}
	return -1;
	printf("�Ҳ���\n");
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
		printf("ɾ���ɹ�\n");
	}
	else
		printf("Ҫɾ���ĳ�Ա������\n");
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
		printf("�������޸ĵ�����:>");
		scanf("%s", name1);
		printf("�������޸ĵ�����:>");
		scanf("%d", &pc->pep[ret].age);
		printf("�������޸ĵ��Ա�:>");
		scanf("%s", sex1);
		printf("�������޸ĵ�סַ:>");
		scanf("%s", addr1);
		printf("�������޸ĵĵ绰:>");
		scanf("%s", tele1);
		strcpy(pc->pep[ret].name, name1);
		strcpy(pc->pep[ret].sex, sex1);
		strcpy(pc->pep[ret].addr, addr1);
		strcpy(pc->pep[ret].tele, tele1);
		printf("�޸ĳɹ�\n");
	}
	else
		printf("Ҫ�޸ĵĳ�Ա������\n");

}
void EMPTY_Info(contact* pc)
{
	assert(pc);
	pc->sz = 0;
	printf("��ճɹ�\n");
}
int com_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
void SORT_Info(contact* pc)
{
	assert(pc);

	qsort(pc->pep, pc->sz, sizeof(pc->pep[0]), com_by_name);
	printf("����ɹ�!");
}

