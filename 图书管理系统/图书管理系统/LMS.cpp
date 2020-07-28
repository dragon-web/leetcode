#include"IMS.h"
void menu()
{
	system("color 4");
	printf("     ***********************************************************************     \n");
	printf("  ************************欢迎使用图书管理系统*******************************   \n");
	printf("|                   注意：借书超出两个月每天2毛钱                          |\n");
	printf("|\t1.--图书入库                                                       |\n");
	printf("|\t2.--图书出库                                                       |\n");
	printf("|\t3.--图书查询（根据书号，书名）                                     |\n");
	printf("|\t4.--查询借阅信息                                                   |\n");
	printf("|\t5.--借书                                                           |\n");
	printf("|\t6.--还书（超出两个月罚款）                                         |\n");
	printf("|\t7.--信息写入文件                                                   |\n");
	printf("|\t0.--退出自行车管理系统                                             |\n");
	printf("|                                                                          |\n");
	printf("| **************************************************************************|\n");
	printf("|****************************************************************************|\n");
}

void BookListInit(BookList* List)//头结点初始完成
{
	Book *p = (Book*)malloc(sizeof(Book));	
	strcpy(p->BookNumber, "xxx");
	p->count = 0;
	strcpy(p->CateGray, "xxx");
	p->NLend = 0;
	strcpy(p->Press, "xxx");
	strcpy(p->Title, "xxx");
	strcpy(p->Writer, "xxx");
	List->first = List->last = p;
	List->last->next = NULL;
	List->Total = 0;
}
void StuListInit(StuList * myList)
{
	Student *p = (Student*)malloc(sizeof(Book));
	strcpy(p->Name, "头结点");
	strcpy(p->StudentNumber, "xxxxxx");
	strcpy(p->Book, "xxxxx");
	myList->first = myList->last = p;
	myList->last->borrow_book.Day = 0;
	myList->last->borrow_book.Month = 0;
	myList->last->borrow_book.Year = 0;
	myList->last->return_book.Day = 0;
	myList->last->return_book.Month = 0;
	myList->last->return_book.Year = 0;
	p->isReturn = 1;
	p->next = NULL;
	myList->num = 0;
}


void BookStorage(BookList* List)
{
	Book *Temp = (Book*)malloc(sizeof(Book));
	char BN[20];
	char NWriter[20];
	char pressPub[40];
	char Class[20];
	char Number[12];
	int num;
	printf("请输入你要入库的书名:\n");
	scanf("%s", BN);
	getchar();
	printf("请输入要入库书名的作者：\n");
	scanf("%s", NWriter);
	getchar();
	printf("请输入出版社:\n");
	scanf("%s", pressPub);
	getchar();
	printf("请输入书类别\n");
	scanf("%s", Class);
	getchar();
	printf("请输入书的编号\n");
	scanf("%s", Number);
	getchar();
	printf("要入库这本书的数量:\n");
	scanf("%d",&num);
	getchar();
	strcpy(Temp->BookNumber, Number);
	strcpy(Temp->CateGray, Class);
	strcpy(Temp->Writer, NWriter);
	strcpy(Temp->Press, pressPub);
	strcpy(Temp->Title, BN);
	Temp->count = num;
	Temp->NLend = 0;
	List->last->next = Temp;
	List->last = Temp;
	Temp->next = NULL;
	List->Total += Temp->count;
	printf("该图书入库成功，当前库存总量是%d\n", List->Total);
}


Book* Find_Book(BookList *List)//图书查询
{
	int num;
	Book *temp = List->first;
	char BN[12];
	char NAME[20];
	printf("请选择根据那种方式查询书籍:\n");
	printf("1:根据书编号:\n");
	printf("2:根据书名:\n");
	scanf("%d", &num);
	getchar();
	switch (num)
	{
	case 1:
		printf("请输入书编号:\n");
		scanf("%s", BN);
		getchar();
		while (temp != NULL)
		{
			if (!strcmp(BN, temp->BookNumber))
			{
				printf("该编号对应的书名是：%s\n", temp->Title);
				printf("该编号对应的出版社是：%s\n", temp->Press);
				printf("该编号对应的作者是：%s\n", temp->Writer);
				printf("该编号对应的类别是：%s\n", temp->CateGray);
				return temp;
			}
			temp = temp->next;
		}
		printf("没有该编号的书\n");
		break;
	case 2:
		printf("请输入书名字\n");
		scanf("%s", NAME);
		getchar();
		while (temp != NULL)
		{
			if (!strcmp(NAME,temp->Title))
			{
				printf("该编号对应的书名是：%s\n", temp->Title);
				printf("该编号对应的出版社是：%s\n", temp->Press);
				printf("该编号对应的作者是：%s\n", temp->Writer);
				printf("该编号对应的类别是：%s\n", temp->CateGray);
				return temp;
			}
			temp = temp->next;
		}
		printf("没有该名称的书\n");
		break;
	default:
		printf("输入有误\n");
		break;
	}
	return temp;
}


void Books_Out_Sortage(BookList *List)//图书出库
{
	char BN[12];
	printf("请输入出库书籍编号:");
	scanf("%s", BN);
	int num;
	Book *temp = List->first;
	Book *res = NULL;
	while (temp != NULL)
	{
		if (!strcmp(BN, temp->BookNumber))
		{
			res = temp;
		}
		temp = temp->next;
	}
	if (res != NULL)
	{
		printf("请输入出库的数量\n");
		scanf("%d", &num);
		getchar();
		if (num > res->count - res->NLend)
		{
			printf("输入数量超出库存量\n");
			return;
		}
		res->count -= num;
		printf("出库成功，当前该书剩余%d\n", res->count - res->NLend);
	}
	else
	{
		printf("没有该书，出库失败\n");
	}
}

int isYear(int year)
{
	return(year % 4 == 0) && (year % 400 == 0 || year % 100 != 0) ? 1 : 0;
}


int getDayOfMonth(int year, int month) {
	int dayArr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return(month == 2 && isYear(year) == 1) ? dayArr[month] + 1 : dayArr[month];
}


int getTotalDay(int year1, int month1, int day1, int year2, int month2, int day2)//处理日期
{

	long total = 0;

	for (int year = year1; year < year2; year++) {
		total = total + 365;
		if (isYear(year) == 1)
			total++;
	}

	for (int month = 1; month < month2; month++) {
		total = total + getDayOfMonth(year2, month);
	}

	total = total + day2;

	for (int month = 1; month < month1; month++) {
		total = total - getDayOfMonth(year1, month);
	}

	return(total - day1);

}




void Borrow_Books(BookList *List, StuList *myList)
{
	
	Student* p = (Student*)malloc(sizeof(Student));
	Book *res = Find_Book(List);
	if (res != NULL)
	{

		printf("请输入您的学号\n:");
		scanf("%s", p->StudentNumber);
		printf("请输入您的姓名\n:");
  	    scanf("%s", p->Name);
		getchar();
		do 
		{
			printf("\n 输入年-月-日(例如2012-12-12):");
			scanf("%d-%d-%d", &p->borrow_book.Year, &p->borrow_book.Month, &p->borrow_book.Day);
		} while (p->borrow_book.Year < 0 || p->borrow_book.Month < 1|| p->borrow_book.Day > 31);
		p->isReturn = 1;
		strcpy(p->Book, res->BookNumber);
	}
	myList->last->next = p;
	p->next = NULL;
	myList->last = p;
	myList->num += 1;
	res->count--;
	res->NLend++;
}

void Search_Borr_Info(StuList *List)
{
	Student *p = List->first;
	char SN[12];
	printf("请输入你要查询的借阅学生的学号:\n");
	scanf("%s", SN);
	getchar();
	while (p != NULL)
	{
		if (!strcmp(p->StudentNumber, SN))
		{
			printf("该学生是%s\n",p->Name);
			printf("借阅时间（%d-%d-%d）\n", p->borrow_book.Year, p->borrow_book.Month, p->borrow_book.Day);	
			if (p->isReturn == 0)
			{
				printf("该学生已经还书\n");
			}
			else
			{
				printf("该学生没有还书\n");
			}
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("没有查询到该学生的借书信息\n");
	}
}

void Return_Books(BookList *List, StuList *mylist)
{
	char SN[20];
	char Temp[12];
	double Money;
	int Total_days;
	printf("请输入学号：\n");
	scanf("%s", SN);
	getchar();
	Student *p = mylist->first->next;
	Book* q = List->first;
	while (p != NULL)
	{
		if (!strcmp(p->StudentNumber, SN))
		{
			strcmp(Temp, SN);//记录编号
			do {
				printf("还书时间\n");
				printf("\n 输入年-月-日(例如2012-12-12):");
				scanf("%d-%d-%d", &p->return_book.Year, &p->return_book.Month, &p->return_book.Day);
			} while (p->return_book.Year < 0 || p->return_book.Month < 1 || p->return_book.Day > 31);
			break;
		}
		p = p->next;
	}
	if (p != NULL)
	{
		Total_days = getTotalDay(p->borrow_book.Year, p->borrow_book.Month, p->borrow_book.Day,
			p->return_book.Year, p->return_book.Month, p->return_book.Day);
		if (Total_days > 60)
		{
			Money = (Total_days - 60)*0.2;
			printf("您借书超时，请缴纳罚金\n");
			printf("您应该缴纳的罚金为%.1lf\n", Money);
			p->isReturn = 0;
		}
		while (q != NULL)
		{
			if (strcmp(q->BookNumber, Temp))
			{
				q->count++;
				q->NLend--;
			}
			q = q->next;
		}
	}
}

 void FileWrite(BookList* myList)
{
	FILE *fp = fopen("Test.txt", "w+");
	Book *p = myList->first->next;
	while (p != NULL)
	{
		fprintf(fp,"%s %s %s %s %s %d %d",p->BookNumber, p->CateGray, p->Press, p->Writer, p->Title,p->count,p->NLend);
		p = p->next;
	}
	fclose(fp);
}