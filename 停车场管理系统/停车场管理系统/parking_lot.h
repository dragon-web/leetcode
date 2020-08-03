#pragma once
#include"common.h"

#define Space 50 

typedef struct Date
{
	int Year;
	int Month;
	int Day;
	int Hour;
}Date;

typedef struct Car
{
	char Owner[20];//��������
	int Sex;
	int Age;
	char IDcard[18];       //���֤��
	Date partingTime;      //�泵ʱ��
	Date Storage_time;     //ȡ��ʱ��
	int number;            //��λ��
	bool IsUsing;          //0��ʾδ��ʹ��
	struct Car* next;
}CarNode;

typedef struct CycleList
{
	CarNode *first;
	CarNode *last;
	size_t  space;
}Car_list;


void menu();
void LoginCar(Car_list *plist, Car_list* MyspaceList);//�Ǽ����г�����
bool SearchCar(Car_list* myCarList);//���ճ�λ�Ų�ѯ���г�
void ChangeCar(Car_list* myCarList, Car_list* MyspaceList);
void PickUpCar(Car_list* myCarList, Car_list* MyspaceList); //ȡ��
void PrintResSpace(Car_list* myCarList, Car_list *SpaceList);
void CarListInit(Car_list *plist);
CarNode*_Buynode(char* p, int sex, int age, char* number, int Pnumber, int year, int month, int day, int hour);
bool CarListIsFull(Car_list *plist);
CarNode* Search_Car(Car_list* myCarList);
void FileWrite(Car_list* myCarList);
void DeleteCarNode(Car_list* myCarList, int key, Car_list* Space_List);
int isYear(int year);
int Count_Fee(CarNode *res);
void Parking_Space_initialization(Car_list* Spacelist);
