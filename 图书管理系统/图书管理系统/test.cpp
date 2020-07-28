#include"IMS.h"


int main()
{
	BookList List;//图书的链表
	StuList STULIST;//学生链表
	StuListInit(&STULIST);
	BookListInit(&List);
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			system("cls");
			printf("图书管理系统已经退出\n");
			break;
		case 1:
			system("cls");
			BookStorage(&List);
			break;
		case 2:
			system("cls");
			Books_Out_Sortage(&List);
			break;
		case 3:
			system("cls");
			Find_Book(&List);
			break;
		case 4:
			system("cls");
			Search_Borr_Info(&STULIST);
			_flushall();
			break;
		case 5:
			system("cls");
			Borrow_Books(&List,&STULIST);
			break;
		case 6:
			system("cls");
			Return_Books(&List, &STULIST);
			break;
		case 7:
			system("cls");
			FileWrite(&List);
			break;	
		default:
			system("cls");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}


