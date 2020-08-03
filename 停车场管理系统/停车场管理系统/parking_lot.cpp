#include"parking_lot.h"

//逻辑框架层

void LoginCar(Car_list *plist ,Car_list* MyspaceList)
{
	if (!CarListIsFull(plist))
	{
		char name[20];
		int age;
		int sex;
		char IDcard[18];
		int hour;
		int Number;
		int year;
		int month;
		int day;
		CarNode *p;
		CarNode *q = MyspaceList->first->next;
		printf("请输入车主姓名\n");
		scanf("%s", name);
		getchar();
		_flushall();
		printf("请输入性别(0代表男，1代表女)");
		scanf("%d", &sex);
		getchar();
		printf("请输入车主年龄");
		scanf("%d", &age);
		getchar();
		printf("请输入身份证号");
		scanf("%s", IDcard);
		getchar();
		_flushall();
		printf("请输入停车时间(年,月,日,时(英文逗号))");
		scanf("%d,%d,%d,%d", &year, &month, &day, &hour);
		getchar();
		printf("请输入要停的位号(位号为1到1500)");
		scanf("%d", &Number);
		getchar();
		plist->space++;
		p = _Buynode(name, sex, age, IDcard, Number, year, month, day, hour);
		plist->last->next = p;
		plist->last = p;
		plist->last->next = NULL;
		while (q != NULL)
		{
			if (q->number == Number)
			{
				strcpy(q->IDcard, p->IDcard);
				strcpy(q->Owner, p->Owner);
				q->Age = p->Age;
				q->IsUsing = 1;
				q->Sex = p->Sex;
				q->partingTime.Day = p->partingTime.Day;
				q->partingTime.Year = p->partingTime.Year;
				q->partingTime.Month = p->partingTime.Month;
				q->partingTime.Hour = p->partingTime.Hour;
				break;
			}
			q = q->next;
		}
		printf("登记成功\n");
		printf("\n");
	}
	else
	{
		printf("停车位位已满，不能继续停车");
	}
}

CarNode* _Buynode(char* p, int sex, int age, char* number, int Pnumber, int year, int month, int day, int hour)
{
	CarNode *s = (CarNode*)malloc(sizeof(CarNode));
	size_t sz = strlen(p) + 1;
	size_t sz1 = strlen(number) + 1;
	if (s == NULL)
		return NULL;
	else
	{
		memcpy(s->Owner, p, sz);
		s->Age = age;
		s->Sex = sex;
		s->partingTime.Year = year;
		s->partingTime.Month = month;
		s->partingTime.Hour = hour;
		s->partingTime.Day = day;
		s->Storage_time.Day = 0;
		s->Storage_time.Year = 0;
		s->Storage_time.Hour = 0;
		s->Storage_time.Month = 0;
		memcpy(s->IDcard, number, sz1);
		s->number = Pnumber;
		s->IsUsing = 1;
		s->next = NULL;
		return s;
	}
}
void CarListInit(Car_list *plist)
{
	char qname[20] = "姓名初始化";
	char qnumber[18] = "身份证初始化";
	CarNode* p = _Buynode(qname, 0, 0, qnumber, 0, 0, 0, 0, 0);
	plist->first = plist->last = p;
	plist->space = 0;
}
bool CarListIsFull(Car_list *plist)
{
	if (plist->space > Space)
		return true;
	return false;
}
bool SearchCar(Car_list* myCarList)
{
	int num;
	printf("      查询车辆信息\n");
	printf("请输入要查询车位号:\n");
	scanf("%d", &num);
	CarNode* p = myCarList->first->next;
	while ((p) != NULL)
	{
		if (p->number == num)
		{
			printf("车主姓名：%s\n", p->Owner);
			(p)->Sex == 0 ? printf("男") : printf("女");
			printf("车主年龄 %d\n", p->Age);
			printf("车主的身份证号为%s \n", p->IDcard);
			printf("停车时间是 %d 年 %d  月  %d 日  %d时\n", p->partingTime.Year, p->partingTime.Month, p->partingTime.Day, p->partingTime.Hour);
			printf("停车位号为%d \n", p->number);
			printf("查询成功\n");
			printf("\n");
			return true;
		}
		p = p->next;
	}
	system("cls");
	printf("查询失败,此车位还未被停车\n");
	return false;
}

void ChangeCar(Car_list* myCarList, Car_list* MyspaceList)
{
	int num;
	int temp;
	char Name[20];
	char Number[18];
	size_t sz1;
	size_t sz2;
	FILE *fp = fopen("Test.txt", "wt");
	int SEX;
	int AGE;
	printf("请输入你要更改的信息的车位号\n");
	scanf("%d", &num);
	getchar();
	CarNode *p = myCarList->first;
	CarNode* q = MyspaceList->first->next;
	while (p != NULL)
	{
		if (p->number == num)
		{
			printf("您所查询的信息如下\n");
			SearchCar(myCarList);
			printf("请输入你要更改的信息\n");
			printf("1:更改姓名\n");
			printf("2:更改性别\n");
			printf("3:更改年龄\n");
			printf("4:更改身份证号\n");
			scanf("%d", &temp);
			switch (temp)
			{
			case  1:
				_flushall();
				printf("请输入新的姓名\n");
				scanf("%s", Name);
				_flushall();
				sz1 = strlen(Name) + 1;
				memcpy(p->Owner, Name, sz1);
				printf("更改成功，返回主菜单");
				printf("\n");
				return;
			case 2:
				printf("请输入性别：（0代表男）\n");
				scanf("%d", &SEX);
				getchar();
				p->Sex = num;
				printf("更改成功，返回主菜单");
				printf("\n");
				return;
			case 3:
				printf("请输入年龄\n");
				scanf("%d", &AGE);
				getchar();
				p->Age = AGE;
				printf("更改成功，返回主菜单");
				printf("\n");
				return;
			case 4:
				printf("请输入身份证号\n");
				getchar();
				scanf("%s", Number);
				_flushall();
				sz2 = strlen(Number) + 1;
				memcpy(p->IDcard, Number, sz2);
				printf("更改成功，返回主菜单");
				printf("\n");
				return;
			default:
				printf("输入有误,返回主菜单\n");
				return;
			}
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("输入有误，返回主菜单");
		printf("\n");
	}

	while (q != NULL)
	{
		if (q->number == num)
		{
			strcpy(q->IDcard, p->IDcard);
			strcpy(q->Owner, p->Owner);
			q->Age = p->Age;
			q->IsUsing = 1;
			q->Sex = p->Sex;
			q->partingTime.Day = p->partingTime.Day;
			q->partingTime.Year = p->partingTime.Year;
			q->partingTime.Month = p->partingTime.Month;
			q->partingTime.Hour = p->partingTime.Hour;
			break;
		}
		q = q->next;
	}
}

void PickUpCar(Car_list* myCarList, Car_list* MyspaceList)//取车
{
	int Year;
	int Month;
	int Day;
	int Hour;
	CarNode*p = Search_Car(myCarList);
	CarNode* q = p->next;
	if (p == NULL)
	{
		printf("没有找到相应的车位\n");
		return;
	}
	printf("请输入取车（年,月,日,时）");
	scanf("%d,%d,%d,%d", &Year, &Month, &Day, &Hour);
	p->Storage_time.Year = Year;
	p->Storage_time.Month = Month;
	p->Storage_time.Day = Day;
	p->Storage_time.Hour = Hour;

	printf("您存车的时间是 %d年 %d月 %d日 %d时", (*p).partingTime.Year, (*p).partingTime.Month, (*p).partingTime.Day, (*p).partingTime.Hour);
	
	printf("您需要缴纳的费用为%d\n\n", Count_Fee(p));
	DeleteCarNode(myCarList, p->number,MyspaceList);
	printf("取车成功,返回主菜单\n");
	printf("\n");
}
CarNode* Search_Car(Car_list* myCarList)
{
	int num;
	printf("请输入要查询车位号:\n");
	scanf("%d", &num);
	CarNode* p = myCarList->first;
	while (p != NULL)
	{
		if (p->number == num)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void PrintResSpace(Car_list* myCarList,Car_list *SpaceList )
{
	printf("=============查询剩余车位===================\n");
	CarNode* p = myCarList->first->next;
	CarNode* q  = SpaceList->first->next;
	assert(p != NULL);
	while (p != NULL)
	{
		printf("当前使用中的车位号是 %d\n", p->number);
		printf("当前车位信息是:\n");
		printf("车主名字%s\n", p->IDcard);
		printf("车主年龄%d", p->Age);
		printf("车主性别 %s", ((p->Sex) == 0 ? "男": "女"));
		printf("车主停车时间%d 年 %d 月 %d 日，%d 时",p->partingTime.Year,p->partingTime.Month,p->partingTime.Day,p->partingTime.Hour);
		p = p->next;
	}
	printf("剩余车位数为: %zu \n", Space - myCarList->space);
	printf("剩余车位为===================================\n");
	while (q != NULL)
	{
		if (q->IsUsing == 0)
		{
			printf("====  %d  ======\n", q->number);
		}
		q = q->next;
	}
	printf("=============================================\n");
}

void DeleteCarNode(Car_list* myCarList, int key,Car_list* Space_List)
{
	CarNode* p = myCarList->first;
	CarNode* q = p->next;
	CarNode* temp1 = Space_List->first;
	CarNode* temp2 = temp1->next;
	while (q != NULL)
	{
		if (q->number == key)
		{
			break;
		}
		p = p->next;
		q = q->next;
	}
	while (temp2 != NULL)
	{
		if (temp2->number == key)
		{
			temp2->IsUsing = 0;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
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


int getTotalDay(int year1,int month1, int day1, int year2, int month2, int day2)//处理日期
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

int Count_Fee(CarNode *res)
{
	int fee = getTotalDay(res->partingTime.Year, res->partingTime.Month, res->partingTime.Day,
		res->Storage_time.Year, res->Storage_time.Month, res->Storage_time.Day); //获取天数
	int temp = res->Storage_time.Hour -  res->partingTime.Hour;
	int Rday = 0;
	int Rhour = temp;
	int Rmonth = 0;
	int Ryear = 0;
	int FEE = 0;
	
	if (fee > 365)
	{
		Ryear = fee % 365;
		fee %= 365;
	}
	if (fee > 30)
	{
		Rmonth = fee % 30;  //获取到了月份
		fee %= 30;
	}
	if (fee > 0 && fee < 30) //按天计费
	{
		   Rday = fee;  //获取天数
			if (temp < 0)
			{
				Rday--;
				Rhour = (24 + temp);
			}
			else
			{
				Rhour = temp;
			}
	}

	FEE = Ryear * 12 * 800 + Rmonth * 800 + Rday * 40 + Rhour * 2;
	return FEE;
}
void Parking_Space_initialization(Car_list* Spacelist)
{
	CarNode* p;
	for (int i = 0; i < Space; ++i)
	{
		p = (CarNode*)malloc(sizeof(CarNode));
		p->number = i + 1; // 记录车位号
		p->IsUsing = 0; 
		Spacelist->last->next = p;
		Spacelist->last = p;
		p->next = NULL;
	}
}

