
#include"parking_lot.h"


int main()
{
	int input = 0;
	Car_list mylist;
	CarListInit(&mylist);
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			system("cls");
			printf("ͣ��������ϵͳ�Ѿ��˳�\n");
			break;
		case 1:
			system("cls");
			LoginCar(&mylist);
			break;
		case 2:
			system("cls");
			SearchCar(&mylist);
			break;
		case 3:
			system("cls");
			ChangeCar(&mylist);
			break;
		case 4:
			system("cls");
			PickUpCar(&mylist);
			_flushall();
			break;
		case 5:
			system("cls");
			PrintResSpace(&mylist);
			break;
		case 6:
			_flushall();
			system("cls");
			FileWrite(&mylist);
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
