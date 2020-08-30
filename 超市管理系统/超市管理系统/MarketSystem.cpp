#include"MarketSystem.h"


void menu()
{
	printf("     ***********************************************************************     \n");
	printf("  ************************欢迎使用超市管理系统*********************************    \n");
	printf("|                          系统菜单显示如下                                     |\n");
	printf("|\t1.--新物品入库（规定入库量最大5000件商品）                              |\n");
	printf("|\t2.--物品信息删除                                                        |\n");
	printf("|\t3.--物品信息修改                                                        |\n");
	printf("|\t4.--物品信息查询                                                        |\n");
	printf("|\t5.--物品信息浏览                                                        |\n");
	printf("|\t6.--系统颜色设置                                                        |\n");
	printf("|\t7.--物品价值总和浏览                                                    |\n");
	printf("|\t8.--物品出售管理                                                        |\n");
	printf("|\t9.--物品预计利润                                                        |\n");
	printf("|\t0.--退出超市管理系统                                                    |\n");
	printf("|                                                                               |\n");
	printf("|*******************************************************************************|\n");
	printf("|********************>>>>>>>>>>>>>设计者：tacogi <<<<<<<<<<<<<******************|\n");
	printf("|*******************************************************************************|\n\n");
}

void SetColor()
{
	printf("请选择>颜色:\n");
	printf("0: 黑色\n");
	printf("1: 蓝色\n");
	printf("2: 绿色\n");
	printf("3: 湖蓝色\n");
	printf("4: 红色\n");
	printf("5: 紫色\n");
	printf("6: 黄色\n");
	printf("7: 白色\n");
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
		printf("输入有误,原颜色退出\n");
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
			printf("请输入货物名称\n");
			scanf("%s", name);
			_flushall();
			printf("请输入货物编号");
			scanf("%s", IDcard);
			getchar();
			printf("请输入入库时间(年,月,日,时(英文逗号))");
			scanf("%d,%d,%d,%d", &year, &month, &day, &hour);
			getchar();
			printf("请输入该商品数量\n");
			scanf("%d", &Number);
			getchar();
			printf("请输入进价\n");
			scanf("%lf", &PPRICE);
			getchar();	
			printf("请输入售价\n");
			scanf("%lf", &SPRICE);
			getchar();
			plist->space++;
			p = _Buynode(name, IDcard, Number, year, month, day, hour,PPRICE,SPRICE);
			plist->last->next = p;
			plist->last = p;
			plist->last->next = NULL;
			printf("货物入库登记成功\n");
			printf("\n");
		}
		else
		{
			printf("仓库已满，不能继续入库");
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
	char qname[20] = "初始化";
	char qnumber[18] = "初始化";
	Node* p = _Buynode(qname, qnumber, 0,0, 0, 0,0,0,0);
	p->Soldout = 0;
	plist->first = plist->last = p;
	plist->space = 0;
}



Node* Search(Nodelist* myList)  //根据商品名称进行查询
{
	int num = 0;
	printf("      查询商品信息\n");
	printf("请输入->\n");
	char name[20];
	printf("请输入要查询商品名称:\n");
	scanf("%s", name);
	Node* p = myList->first->next;
	while (p != NULL)
	{
		if (!strcmp(p->Name, name))
		{
			printf("查询成功\n");
			printf("该商品信息如下:\n");
			printf("商品名称:%s", p->Name);
			printf("商品编号:%s", p->IDcard);
			printf("该商品现库存:%d\n", p->number);
			printf("商品入库时间:%d年-%d月-%d日-%d时\n", p->partingTime.Day,p->partingTime.Month,p->partingTime.Day,p->partingTime.Hour);
			
			return p;
		}
		p = p->next;
	}
	return NULL;
}

Node* Search_Two_Parameter(Nodelist* myList,char *name)  //根据商品名称进行查询
{
	Node* p = myList->first->next;
	while (p != NULL)
	{
		if (!strcmp(p->Name, name))
		{
			printf("查询成功\n");
			printf("要删除商品信息如下:\n");
			printf("商品名称:%s", p->Name);
			printf("商品编号:%s", p->IDcard);
			printf("该商品现库存:%d\n", p->number);
			printf("商品入库时间:%d年-%d月-%d日-%d时\n", p->partingTime.Day, p->partingTime.Month, p->partingTime.Day, p->partingTime.Hour);
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void Change(Nodelist* myList)  //商品库存和入库时间进价不予修改
{
	char name[20];
	char idcard[18];
	int num = 0;
	int NewPrice;
	printf("请输入你要修改的商品名称:\n");
	scanf("%s", name);
	Node* p = myList->first->next;
	while (p != NULL)
	{
		if (!strcmp(name, p->Name))
		{
			printf("该商品信息如下:\n");
			printf("1:商品名称:%s", p->Name);
			printf("2:商品编号:%s", p->IDcard);
			printf("3:该商品现库存:%d\n", p->number);
			printf("商品入库时间:%d年-%d月-%d日-%d时\n", p->partingTime.Day, p->partingTime.Month, p->partingTime.Day, p->partingTime.Hour);
			printf("请输入你要修改的信息\n");
			printf("1->修改商品名称\n");
			printf("2->修改商品编号\n");
			printf("2->修改商品售价\n");
			scanf("%d", &num);
			switch (num)
			{
			case 1:
				printf("请输入商品新名称：\n");
				scanf("%s", name);
				strcpy(p->Name, name);
				printf("信息更改成功\n");
				break;
			case 2:
				printf("请输入商品新编号：\n");
				scanf("%s", idcard);
				strcpy(p->IDcard,idcard);
				printf("信息更改成功\n");
				break;
			case 3:
				printf("请输入商品新售价：\n");
				scanf("%d", &NewPrice);
				p->sPrice = NewPrice;
				printf("信息更改成功\n");
				break;
			default:
				printf("输入信息有误，退出\n");
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
		printf("第%d件商品信息如下:\n",count);
		printf("商品名称：%s", p->Name);
		printf("商品编号：%s", p->IDcard);
		printf("3:该商品现库存:%d\n", p->number);
		printf("商品入库时间:%d年-%d月-%d日-%d时\n", p->partingTime.Year, p->partingTime.Month, p->partingTime.Day, p->partingTime.Hour);
		printf("商品进价：%lf\n", p->pPrice);
		printf("商品售价：%lf\n", p->sPrice);
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
	printf("仓库库存总价值量:%lf\n", sum);

}

void Delete(Nodelist *plist)
{
	char name[20];
	printf("请输入要删除商品的名称\n");
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
				printf("删除信息成功\n");
				return;
			}
			p = p->next;
		}
		p->next = res->next;
		free(res);
		printf("信息删除成功\n");
	}
	else
	{
		printf("没有该商品\n");
	}
}



void Sold(Nodelist* plist)
{
	char name[20];
	int NUM;
	printf("请输入出售商品名称\n");
	scanf("%s", name);
	printf("请输入出售件数\n");
	scanf("%d", &NUM);
	Node* res = Search(plist);
	if (NUM > res->number)
	{
		printf("产品库存不足\n");
	}
	else
	{
		res->Soldout += NUM;
		res->number -= NUM;
		printf("所需要的价格:%lf\n",res->sPrice*NUM);

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
	printf("在所卖商品中利润为:%lf\n", profit);
}
