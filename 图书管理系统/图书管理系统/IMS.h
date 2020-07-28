#pragma once
#include"common.h"

typedef struct B
{
	char Title[20];
	char BookNumber[12];
	char CateGray[20];//类别
	int count;//库存
	char Press[40];//出版社
	char Writer[20];
	int NLend;//出借册数
	struct B* next;
}Book;

typedef struct 
{
	Book *first;
	Book *last;
	size_t  Total; //总共库存量
}BookList;  

typedef struct Date
{
	int Year;
	int Month;
	int Day;
}Date;


typedef struct Stu
{
	char StudentNumber[20]; //学生学号
	char Name[18];//学生姓名
	char Book[12];//借书编号
	Date borrow_book;
	Date return_book;
	bool isReturn;
	struct Stu* next;
}Student;

typedef struct StuList
{
	Student *first;
	Student *last;
	size_t num;
}StuList;


void menu();
void BookListInit(BookList* List);//初始化书库链表
void BookStorage(BookList* List);//入库Book* Find_Book(BookList *List)
void Books_Out_Sortage(BookList *List);
Book* Find_Book(BookList *List);
void Search_Borr_Info(StuList *List);
void Borrow_Books(BookList *List,StuList *mylist);
void Return_Books(BookList *List, StuList *mylist);
int isYear(int year);
int getDayOfMonth(int year, int month);
int getTotalDay(int year1, int month1, int day1, int year2, int month2, int day2);
void StuListInit(StuList * myList);
void FileWrite(BookList* myList);