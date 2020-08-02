#pragma once
#include"common.h"

#define Space 1500 

typedef struct Date
{
	int Year;
	int Month;
	int Day;
	int Hour;
}Date;

typedef struct Car
{
	char Owner[20];//车主名字
	int Sex;
	int Age;
	char IDcard[18];       //身份证号
	Date partingTime;      //存车时间
	Date Storage_time;     //取车时间
	int number;            //车位号
	struct Car* next;
}CarNode;

typedef struct CycleList
{
	CarNode *first;
	CarNode *last;
	size_t  space;
}Car_list;





void menu();
void LoginCar(Car_list *plist);//登记自行车函数
bool SearchCar(Car_list* myCarList);//按照车位号查询自行车
void ChangeCar(Car_list* myCarList);
void PickUpCar(Car_list* myCarList); //存车
void PrintResSpace(Car_list* myCarList);
void CarListInit(Car_list *plist);
CarNode*_Buynode(char* p, int sex, int age, char* number, int Pnumber, int year, int month, int day, int hour);
bool CarListIsFull(Car_list *plist);
CarNode* Search_Car(Car_list* myCarList);
void FileWrite(Car_list* myCarList);
void DeleteCarNode(Car_list* myCarList, int key);
int isYear(int year);
int Count_Fee(CarNode *res);