#include"MarketSystem.h"


void menu()
{
	printf("     ***********************************************************************     \n");
	printf("  ************************��ӭʹ�ó��й���ϵͳ*********************************    \n");
	printf("|                          ϵͳ�˵���ʾ����                                     |\n");
	printf("|\t1.--����Ʒ��⣨�涨��������5000����Ʒ��                              |\n");
	printf("|\t2.--��Ʒ��Ϣɾ��                                                        |\n");
	printf("|\t3.--��Ʒ��Ϣ�޸�                                                        |\n");
	printf("|\t4.--��Ʒ��Ϣ��ѯ                                                        |\n");
	printf("|\t5.--��Ʒ��Ϣ���                                                        |\n");
	printf("|\t6.--ϵͳ��ɫ����                                                        |\n");
	printf("|\t7.--��Ʒ��ֵ�ܺ����                                                    |\n");
	printf("|\t8.--��Ʒ���۹���                                                        |\n");
	printf("|\t9.--��ƷԤ������                                                        |\n");
	printf("|\t0.--�˳����й���ϵͳ                                                    |\n");
	printf("|                                                                               |\n");
	printf("|*******************************************************************************|\n");
	printf("|********************>>>>>>>>>>>>>����ߣ�tacogi <<<<<<<<<<<<<******************|\n");
	printf("|*******************************************************************************|\n\n");
}

void SetColor()
{
	printf("��ѡ��>��ɫ:\n");
	printf("0: ��ɫ\n");
	printf("1: ��ɫ\n");
	printf("2: ��ɫ\n");
	printf("3: ����ɫ\n");
	printf("4: ��ɫ\n");
	printf("5: ��ɫ\n");
	printf("6: ��ɫ\n");
	printf("7: ��ɫ\n");
	int color;
	scanf("%d", &color);
	switch (color)
	{
	case 0:
		break;
	case 1:
		system("color 1");
		break;
	case 2:
		system("color 2");
		break;
	case 3:
		system("color 3");
		break;
	case 4:
		system("color 4");
		break;
	case 5:
		system("color 5");
		break;
	case 6:
		system("color 6");
		break;
	case 7:
		system("color 7");
		break;
	default:
		printf("��������,ԭ��ɫ�˳�\n");
		break;
	}
}

void Login(Nodelist *plist)
{
		if (!NodeListIsFull(plist))
		{
			char name[20];
			char IDcard[18];
			int hour;
			int Number;
			double PPRICE;
			double SPRICE;
			int year;
			int month;
			int day;
			Node *p;
			printf("�������������\n");
			scanf("%s", name);
			_flushall();
			printf("�����������");
			scanf("%s", IDcard);
			getchar();
			printf("���������ʱ��(��,��,��,ʱ(Ӣ�Ķ���))");
			scanf("%d,%d,%d,%d", &year, &month, &day, &hour);
			getchar();
			printf("���������Ʒ����\n");
			scanf("%d", &Number);
			getchar();
			printf("���������\n");
			scanf("%lf", &PPRICE);
			getchar();	
			printf("�������ۼ�\n");
			scanf("%lf", &SPRICE);
			getchar();
			plist->space++;
			p = _Buynode(name, IDcard, Number, year, month, day, hour,PPRICE,SPRICE);
			plist->last->next = p;
			plist->last = p;
			plist->last->next = NULL;
			printf("�������Ǽǳɹ�\n");
			printf("\n");
		}
		else
		{
			printf("�ֿ����������ܼ������");
		}
}

bool NodeListIsFull(Nodelist *plist)
{
	if (plist->space > Space)
		return true;
	return false;
}

Node* _Buynode(char* p, char* number, int Pnumber, int year, int month, int day, int hour,double PPRICE,double SPRICE)
{
	Node *s = (Node*)malloc(sizeof(Node));
	size_t sz = strlen(p) + 1;
	size_t sz1 = strlen(number) + 1;
	if (s == NULL)
		return NULL;
	else
	{
		memcpy(s->Name, p, sz);
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
		s->pPrice = PPRICE;
		s->sPrice = SPRICE;
		s->Soldout = 0;
		s->next = NULL;
		return s;
	}
}
void ListInit(Nodelist *plist)
{
	char qname[20] = "��ʼ��";
	char qnumber[18] = "��ʼ��";
	Node* p = _Buynode(qname, qnumber, 0,0, 0, 0,0,0,0);
	p->Soldout = 0;
	plist->first = plist->last = p;
	plist->space = 0;
}



Node* Search(Nodelist* myList)  //������Ʒ���ƽ��в�ѯ
{
	int num = 0;
	printf("      ��ѯ��Ʒ��Ϣ\n");
	printf("������->\n");
	char name[20];
	printf("������Ҫ��ѯ��Ʒ����:\n");
	scanf("%s", name);
	Node* p = myList->first->next;
	while (p != NULL)
	{
		if (!strcmp(p->Name, name))
		{
			printf("��ѯ�ɹ�\n");
			printf("����Ʒ��Ϣ����:\n");
			printf("��Ʒ����:%s", p->Name);
			printf("��Ʒ���:%s", p->IDcard);
			printf("����Ʒ�ֿ��:%d\n", p->number);
			printf("��Ʒ���ʱ��:%d��-%d��-%d��-%dʱ\n", p->partingTime.Day,p->partingTime.Month,p->partingTime.Day,p->partingTime.Hour);
			
			return p;
		}
		p = p->next;
	}
	return NULL;
}

Node* Search_Two_Parameter(Nodelist* myList,char *name)  //������Ʒ���ƽ��в�ѯ
{
	Node* p = myList->first->next;
	while (p != NULL)
	{
		if (!strcmp(p->Name, name))
		{
			printf("��ѯ�ɹ�\n");
			printf("Ҫɾ����Ʒ��Ϣ����:\n");
			printf("��Ʒ����:%s", p->Name);
			printf("��Ʒ���:%s", p->IDcard);
			printf("����Ʒ�ֿ��:%d\n", p->number);
			printf("��Ʒ���ʱ��:%d��-%d��-%d��-%dʱ\n", p->partingTime.Day, p->partingTime.Month, p->partingTime.Day, p->partingTime.Hour);
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void Change(Nodelist* myList)  //��Ʒ�������ʱ����۲����޸�
{
	char name[20];
	char idcard[18];
	int num = 0;
	int NewPrice;
	printf("��������Ҫ�޸ĵ���Ʒ����:\n");
	scanf("%s", name);
	Node* p = myList->first->next;
	while (p != NULL)
	{
		if (!strcmp(name, p->Name))
		{
			printf("����Ʒ��Ϣ����:\n");
			printf("1:��Ʒ����:%s", p->Name);
			printf("2:��Ʒ���:%s", p->IDcard);
			printf("3:����Ʒ�ֿ��:%d\n", p->number);
			printf("��Ʒ���ʱ��:%d��-%d��-%d��-%dʱ\n", p->partingTime.Day, p->partingTime.Month, p->partingTime.Day, p->partingTime.Hour);
			printf("��������Ҫ�޸ĵ���Ϣ\n");
			printf("1->�޸���Ʒ����\n");
			printf("2->�޸���Ʒ���\n");
			printf("2->�޸���Ʒ�ۼ�\n");
			scanf("%d", &num);
			switch (num)
			{
			case 1:
				printf("��������Ʒ�����ƣ�\n");
				scanf("%s", name);
				strcpy(p->Name, name);
				printf("��Ϣ���ĳɹ�\n");
				break;
			case 2:
				printf("��������Ʒ�±�ţ�\n");
				scanf("%s", idcard);
				strcpy(p->IDcard,idcard);
				printf("��Ϣ���ĳɹ�\n");
				break;
			case 3:
				printf("��������Ʒ���ۼۣ�\n");
				scanf("%d", &NewPrice);
				p->sPrice = NewPrice;
				printf("��Ϣ���ĳɹ�\n");
				break;
			default:
				printf("������Ϣ�����˳�\n");
				break;
			}
		}
		p = p->next;
	}
}


void Browse(Nodelist* myList)
{
	int count = 1;
	Node* p = myList->first->next;
	while (p != NULL)
	{
		printf("��%d����Ʒ��Ϣ����:\n",count);
		printf("��Ʒ���ƣ�%s", p->Name);
		printf("��Ʒ��ţ�%s", p->IDcard);
		printf("3:����Ʒ�ֿ��:%d\n", p->number);
		printf("��Ʒ���ʱ��:%d��-%d��-%d��-%dʱ\n", p->partingTime.Year, p->partingTime.Month, p->partingTime.Day, p->partingTime.Hour);
		printf("��Ʒ���ۣ�%lf\n", p->pPrice);
		printf("��Ʒ�ۼۣ�%lf\n", p->sPrice);
		count++;
		p = p->next;
	}
}

void PriceSum(Nodelist* plist)
{
	double sum = 0;
	Node* p = plist->first->next;
	while (p != NULL)
	{
		sum += p->pPrice*p->number;
		p = p->next;
	}
	printf("�ֿ����ܼ�ֵ��:%lf\n", sum);

}

void Delete(Nodelist *plist)
{
	char name[20];
	printf("������Ҫɾ����Ʒ������\n");
	scanf("%s", name);
	Node* res = Search_Two_Parameter(plist,name);
	if (res != NULL)
	{
		Node* p = plist->first;
		while (p->next != res)
		{
			if (res = plist->first->next)
			{
				p->next = res->next;
				free(res);
				printf("ɾ����Ϣ�ɹ�\n");
				return;
			}
			p = p->next;
		}
		p->next = res->next;
		free(res);
		printf("��Ϣɾ���ɹ�\n");
	}
	else
	{
		printf("û�и���Ʒ\n");
	}
}



void Sold(Nodelist* plist)
{
	char name[20];
	int NUM;
	printf("�����������Ʒ����\n");
	scanf("%s", name);
	printf("��������ۼ���\n");
	scanf("%d", &NUM);
	Node* res = Search(plist);
	if (NUM > res->number)
	{
		printf("��Ʒ��治��\n");
	}
	else
	{
		res->Soldout += NUM;
		res->number -= NUM;
		printf("����Ҫ�ļ۸�:%lf\n",res->sPrice*NUM);

	}
}

void Profit(Nodelist *plist)
{
	double profit = 0;
	Node* p = plist->first->next;
	while (p != NULL)
	{
		profit += (p->sPrice - p->pPrice) * p->Soldout;
		p = p->next;
	}
	printf("��������Ʒ������Ϊ:%lf\n", profit);
}
