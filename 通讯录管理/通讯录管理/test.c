#include"contact.h"
void menu()
{
	printf("****************************\n");
	printf("*** 1.add        2.del	 ***\n");
	printf("*** 3.search     4.modify***\n");
	printf("*** 5.show       6.empty ***\n");
	printf("*** 7.sort       0.exit  ***\n");
	printf("****************************\n");
}
enum menu
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	EMPTY,
	SORT,
};
int main()
{
	int input = 0;
	contact con;
	Init_Info(&con);
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			EXIT_Info(&con);
			printf("�˳���\n");
			break;
		case ADD:
			ADD_Info(&con);
			break;
		case DEL:
			DEL_Info(&con);
			break;
		case SEARCH:
			SEARCH_Info(&con);
			break;
		case MODIFY:
			MODIFY_Info(&con);
			break;
		case SHOW:
			SHOW_Info(&con);
			break;
		case EMPTY:
			EMPTY_Info(&con);
			break;
		case SORT:
			SORT_Info(&con);
			break;
		default :
			printf("�������������ѡ��!");
			break;
		}
	} while (input);
	system("pause");
	return 0;

}