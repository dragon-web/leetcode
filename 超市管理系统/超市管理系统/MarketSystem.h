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
	char Name[20];     //��������
	char IDcard[18];       //������
	Date partingTime;      //���ʱ��
	Date Storage_time;     //����ʱ��
	int number;            //����
	int Soldout;
	double pPrice;   //����
	double sPrice;   //�ۼ�
	struct Node* next;
}Node;

typedef struct CycleList
{
	Node *first;
	Node *last;
	size_t  space;
}Nodelist;

void Login(Nodelist *plist);//��Ʒ���
bool NodeListIsFull(Nodelist *plist);//�ж���Ʒ�Ƿ�����ֿ�
Node* _Buynode(char* p, char* number, int Pnumber, int year, int month, int day, int hour, double PPRICE, double SPRICE);
void Change(Nodelist* myList);   
void ListInit(Nodelist *plist);  //��ʼ��
Node* Search(Nodelist* myList);  //������Ʒ���ƽ��в�ѯ
void Browse(Nodelist* myList);  //���
void PriceSum(Nodelist* plist);  //��ֵ�ܺ�
void Delete(Nodelist* plist);
void Sold(Nodelist* plist);
void Profit(Nodelist *plist);  //����
void menu();
void SetColor();

