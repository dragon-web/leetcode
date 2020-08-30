#pragma once
#include"common.h"


typedef struct Date
{
	int Year;
	int Month;
	int Day;
	int Hour;
}Date;

typedef struct Node
{
	char Name[20];     //货物名字
	char IDcard[18];       //货物编号
	Date partingTime;      //存库时间
	Date Storage_time;     //出库时间
	int number;            //数量
	int Soldout;
	double pPrice;   //进价
	double sPrice;   //售价
	struct Node* next;
}Node;

typedef struct CycleList
{
	Node *first;
	Node *last;
	size_t  space;
}Nodelist;

void Login(Nodelist *plist);//物品入库
bool NodeListIsFull(Nodelist *plist);//判断物品是否堆满仓库
Node* _Buynode(char* p, char* number, int Pnumber, int year, int month, int day, int hour, double PPRICE, double SPRICE);
void Change(Nodelist* myList);   
void ListInit(Nodelist *plist);  //初始化
Node* Search(Nodelist* myList);  //根据商品名称进行查询
void Browse(Nodelist* myList);  //浏览
void PriceSum(Nodelist* plist);  //价值总和
void Delete(Nodelist* plist);
void Sold(Nodelist* plist);
void Profit(Nodelist *plist);  //利润
void menu();
void SetColor();

