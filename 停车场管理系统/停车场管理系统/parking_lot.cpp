#include"parking_lot.h"

//�߼���ܲ�

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
		printf("�����복������\n");
		scanf("%s", name);
		getchar();
		_flushall();
		printf("�������Ա�(0�����У�1����Ů)");
		scanf("%d", &sex);
		getchar();
		printf("�����복������");
		scanf("%d", &age);
		getchar();
		printf("���������֤��");
		scanf("%s", IDcard);
		getchar();
		_flushall();
		printf("������ͣ��ʱ��(��,��,��,ʱ(Ӣ�Ķ���))");
		scanf("%d,%d,%d,%d", &year, &month, &day, &hour);
		getchar();
		printf("������Ҫͣ��λ��(λ��Ϊ1��1500)");
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
		printf("�Ǽǳɹ�\n");
		printf("\n");
	}
	else
	{
		printf("ͣ��λλ���������ܼ���ͣ��");
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
	char qname[20] = "������ʼ��";
	char qnumber[18] = "���֤��ʼ��";
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
	printf("      ��ѯ������Ϣ\n");
	printf("������Ҫ��ѯ��λ��:\n");
	scanf("%d", &num);
	CarNode* p = myCarList->first->next;
	while ((p) != NULL)
	{
		if (p->number == num)
		{
			printf("����������%s\n", p->Owner);
			(p)->Sex == 0 ? printf("��") : printf("Ů");
			printf("�������� %d\n", p->Age);
			printf("���������֤��Ϊ%s \n", p->IDcard);
			printf("ͣ��ʱ���� %d �� %d  ��  %d ��  %dʱ\n", p->partingTime.Year, p->partingTime.Month, p->partingTime.Day, p->partingTime.Hour);
			printf("ͣ��λ��Ϊ%d \n", p->number);
			printf("��ѯ�ɹ�\n");
			printf("\n");
			return true;
		}
		p = p->next;
	}
	system("cls");
	printf("��ѯʧ��,�˳�λ��δ��ͣ��\n");
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
	printf("��������Ҫ���ĵ���Ϣ�ĳ�λ��\n");
	scanf("%d", &num);
	getchar();
	CarNode *p = myCarList->first;
	CarNode* q = MyspaceList->first->next;
	while (p != NULL)
	{
		if (p->number == num)
		{
			printf("������ѯ����Ϣ����\n");
			SearchCar(myCarList);
			printf("��������Ҫ���ĵ���Ϣ\n");
			printf("1:��������\n");
			printf("2:�����Ա�\n");
			printf("3:��������\n");
			printf("4:�������֤��\n");
			scanf("%d", &temp);
			switch (temp)
			{
			case  1:
				_flushall();
				printf("�������µ�����\n");
				scanf("%s", Name);
				_flushall();
				sz1 = strlen(Name) + 1;
				memcpy(p->Owner, Name, sz1);
				printf("���ĳɹ����������˵�");
				printf("\n");
				return;
			case 2:
				printf("�������Ա𣺣�0�����У�\n");
				scanf("%d", &SEX);
				getchar();
				p->Sex = num;
				printf("���ĳɹ����������˵�");
				printf("\n");
				return;
			case 3:
				printf("����������\n");
				scanf("%d", &AGE);
				getchar();
				p->Age = AGE;
				printf("���ĳɹ����������˵�");
				printf("\n");
				return;
			case 4:
				printf("���������֤��\n");
				getchar();
				scanf("%s", Number);
				_flushall();
				sz2 = strlen(Number) + 1;
				memcpy(p->IDcard, Number, sz2);
				printf("���ĳɹ����������˵�");
				printf("\n");
				return;
			default:
				printf("��������,�������˵�\n");
				return;
			}
		}
		p = p->next;
	}
	if (p == NULL)
	{
		printf("�������󣬷������˵�");
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

void PickUpCar(Car_list* myCarList, Car_list* MyspaceList)//ȡ��
{
	int Year;
	int Month;
	int Day;
	int Hour;
	CarNode*p = Search_Car(myCarList);
	CarNode* q = p->next;
	if (p == NULL)
	{
		printf("û���ҵ���Ӧ�ĳ�λ\n");
		return;
	}
	printf("������ȡ������,��,��,ʱ��");
	scanf("%d,%d,%d,%d", &Year, &Month, &Day, &Hour);
	p->Storage_time.Year = Year;
	p->Storage_time.Month = Month;
	p->Storage_time.Day = Day;
	p->Storage_time.Hour = Hour;

	printf("���泵��ʱ���� %d�� %d�� %d�� %dʱ", (*p).partingTime.Year, (*p).partingTime.Month, (*p).partingTime.Day, (*p).partingTime.Hour);
	
	printf("����Ҫ���ɵķ���Ϊ%d\n\n", Count_Fee(p));
	DeleteCarNode(myCarList, p->number,MyspaceList);
	printf("ȡ���ɹ�,�������˵�\n");
	printf("\n");
}
CarNode* Search_Car(Car_list* myCarList)
{
	int num;
	printf("������Ҫ��ѯ��λ��:\n");
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
	printf("=============��ѯʣ�೵λ===================\n");
	CarNode* p = myCarList->first->next;
	CarNode* q  = SpaceList->first->next;
	assert(p != NULL);
	while (p != NULL)
	{
		printf("��ǰʹ���еĳ�λ���� %d\n", p->number);
		printf("��ǰ��λ��Ϣ��:\n");
		printf("��������%s\n", p->IDcard);
		printf("��������%d", p->Age);
		printf("�����Ա� %s", ((p->Sex) == 0 ? "��": "Ů"));
		printf("����ͣ��ʱ��%d �� %d �� %d �գ�%d ʱ",p->partingTime.Year,p->partingTime.Month,p->partingTime.Day,p->partingTime.Hour);
		p = p->next;
	}
	printf("ʣ�೵λ��Ϊ: %zu \n", Space - myCarList->space);
	printf("ʣ�೵λΪ===================================\n");
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


int getTotalDay(int year1,int month1, int day1, int year2, int month2, int day2)//��������
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
		res->Storage_time.Year, res->Storage_time.Month, res->Storage_time.Day); //��ȡ����
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
		Rmonth = fee % 30;  //��ȡ�����·�
		fee %= 30;
	}
	if (fee > 0 && fee < 30) //����Ʒ�
	{
		   Rday = fee;  //��ȡ����
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
		p->number = i + 1; // ��¼��λ��
		p->IsUsing = 0; 
		Spacelist->last->next = p;
		Spacelist->last = p;
		p->next = NULL;
	}
}

