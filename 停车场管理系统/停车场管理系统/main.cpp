
#include"parking_lot.h"


int main()
{
	int input = 0;
	Car_list mylist;
	Car_list Space_List;
	CarListInit(&mylist);
	CarListInit(&Space_List);
	Parking_Space_initialization(&Space_List);
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			system("cls");
			printf("停车场管理系统已经退出\n");
			break;
		case 1:
			system("cls");
			LoginCar(&mylist,&Space_List);
			break;
		case 2:
			system("cls");
			SearchCar(&mylist);
			break;
		case 3:
			system("cls");
			ChangeCar(&mylist,&Space_List);
			break;
		case 4:
			system("cls");
			PickUpCar(&mylist,&Space_List);
			_flushall();
			break;
		case 5:
			system("cls");
			PrintResSpace(&mylist,&Space_List);
			break;
		case 6:
			_flushall();
			system("cls");
			FileWrite(&mylist);
			break;
		default:
			_flushall();
			system("cls");
			printf("输入有误请重新选择\n");
			break;
		}
	} while (input);

	system("pause");
	return 0;
}
