#include"MarketSystem.h"


int main()
{
	int input = 0;
	Nodelist mylist;
	ListInit(&mylist);
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			system("cls");
			printf("���й���ϵͳ�Ѿ��˳�\n");
			break;
		case 1:
			system("cls");
			Login(&mylist);
			break;
		case 2:
			system("cls");
			Delete(&mylist);
			break;
		case 3:
			system("cls");
			Change(&mylist);
			break;
		case 4:
			system("cls");//��������
			Search(&mylist);
			_flushall();  //���������
			break;
		case 5:
			system("cls");
			Browse(&mylist);
			break;
		case 6:
			SetColor();
			_flushall();
			system("cls");
			break;
		case 7:
			_flushall();
			system("cls");
			PriceSum(&mylist);
			break;	
		case 8:
			_flushall();
			system("cls");
			Sold(&mylist);
			break;
		case 9:
			_flushall();
			system("cls");
			Profit(&mylist);
			break;
		default:
			_flushall();
			system("cls");
			printf("��������������ѡ��\n");
			break;
		}
	} while (input);

	system("pause");
	return 0;
}