#include"common.h"
int j;
void LoginRoom();
void SearchRoom();
void ChangeRoom();
void OutRoom();
void save();
void load();
struct Client
{
	char Name[20];
	int Sex;
	int Age;
	char IDcard[18];
	int hour;
	char date[7];
};
struct room
{
	int RoomID;
	char Tel[11];
	long Price;
	int Sign;
	struct Client Clientlist;
}Room[NUM];
void LoginRoom()     //登记客房信息函数
{
	int i, n, k;
	n = 0;
	system("cls");
	printf("                                     用户登记\n");
	for (k = 0;; k++)
	{
		printf("请输入客房号:\n");
		scanf("%d", &i);
		if (Room[i - 1].Sign == 1)
		{
			printf("对不起，该房间已入住,请重新输入。\n");
			n = n + 1;
		}
		if (n == 5)
		{
			printf("\n请查询清楚客房入住信息后再来登记，谢谢");
			Sleep(1500);
			system("cls");
			return;
		}
		if (Room[i - 1].Sign != 1)
			break;
	}
	printf("房间号：%d\n", i);
	printf("客户姓名:");
	scanf("%s", (char *)&Room[i - 1].Clientlist.Name);
	printf("性别:");
	scanf("%d", &Room[i - 1].Clientlist.Sex);
	printf("年龄:");
	scanf("%d", &Room[i - 1].Clientlist.Age);
	printf("身份证号码:");
	scanf("%s", (char *)&Room[i - 1].Clientlist.IDcard);
	printf("联系电话:");
	scanf("%s", (char *)&Room[i - 1].Tel);
	printf("入住时间:");
	scanf("%s", (char *)&Room[i - 1].Clientlist.date);
	printf("住房时长:");
	scanf("%d", &Room[i - 1].Clientlist.hour);
	Room[i - 1].RoomID = i;
	Room[i - 1].Price = (Room[i - 1].Clientlist.hour) * 40;
	Room[i - 1].Sign = 1;
	save();
	printf("恭喜,登记成功!!\n要返回首页吗？(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		LoginRoom();
	}
	system("cls");
}
void save()      //将客房入住信息保存到文件中
{
//	int i;
	FILE *fp;
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		printf("无法打开文件\n");
		return;
	}
	fwrite(Room, sizeof(struct room), NUM, fp);
	printf("文件写入完成\n");
	fclose(fp);
}
void SearchRoom()    //查询客房信息
{
	int k;
	system("cls");
	printf("                                  查询客房信息\n");
	printf("请输入要查询的房间号码:\n");
	scanf("%d", &k);
	if (k <= 0 || k > 100)
	{
		printf("对不起，没有相应的房间。\n");
		SearchRoom();
	}
	if (Room[k - 1].Sign == 1)
	{
		printf("姓名:%s\n", Room[k - 1].Clientlist.Name);
		if (Room[k - 1].Clientlist.Sex == 1)
		{
			printf("性别:男\n");
		}
		else
		{
			printf("性别：女\n");
		}
		printf("年龄:%d\n", Room[k - 1].Clientlist.Age);
		printf("身份证号:%s\n", Room[k - 1].Clientlist.IDcard);
		printf("联系电话:%s\n", Room[k - 1].Tel);
		printf("入住时间:%s\n", Room[k - 1].Clientlist.date);
		printf("入住时长:%d\n", Room[k - 1].Clientlist.hour);
		printf("费用:%ld\n", Room[k - 1].Price);
	}
	else
	{
		system("cls");
		printf("很抱歉,没有找到该房间登记的相关信息!!\n\n");
	}
	printf("要返回首页吗？(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		SearchRoom();
	}
	system("cls");
}
void load()      //从文件中读取客房入住信息
{
	FILE *fp;
	int i;
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("不能打开文件\n");
		return;
	}
	for (i = 0; !feof(fp); i++)
	{
		fread(&Room[i], sizeof(struct room), 1, fp);
	}
	fclose(fp);
	system("cls");
	printf("文件读取成功\n");
}
void ChangeRoom()      //修改客房入住信息
{
	int i, n;
	system("cls");
	printf("                                  修改客房信息\n");
	printf("请输入房间号:\n");
	scanf("%d", &i);
	if (Room[i - 1].Sign == 1)
	{
		printf("\t1.--修改客户姓名\n");
		printf("\t2.--修改客户性别\n");
		printf("\t3.--修改客户年龄\n");
		printf("\t4.--修改住房时间\n");
		printf("\t5.--修改住房时长（续住）\n");
		printf("\t6.--修改客户电话号码\n");
		printf("\t7.--修改客户身份证号\n");
		printf("请输入要修改的项：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:scanf("%s", (char *)&Room[i - 1].Clientlist.Name);
			break;
		case 2:scanf("%d", &Room[i - 1].Clientlist.Sex);
			break;
		case 3:scanf("%d", &Room[i - 1].Clientlist.Age);
			break;
		case 4:scanf("%s", (char *)&Room[i - 1].Clientlist.date);
			break;
		case 5:
			scanf("%d", &Room[i - 1].Clientlist.hour);
			Room[i - 1].Price = (Room[i - 1].Clientlist.hour) * 40;
			break;
		case 6:scanf("%s", (char *)&Room[i - 1].Tel);
			break;
		case 7:scanf("%s", (char *)&Room[i - 1].Clientlist.IDcard);
			break;
		default:printf("输入错误，请从新选择");
			break;
		}
		save();
		printf("修改成功！");
	}
	else
	{
		system("cls");
		printf("该房间为空房!!\n");
	}
	printf("\n要返回首页吗？(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		ChangeRoom();
	}
	system("cls");
}
void OutRoom()      //退房函数
{
	int i, j;
	system("cls");
	printf("                                    退房管理\n");
	printf("请输入房间号:\n");
	scanf("%d", &i);
	printf("确认要退%d号房吗？(1:Y/0:N)", i);
	scanf("%d", &j);
	if (j == 1)
	{
		if (Room[i - 1].Sign == 1)
		{
			Room[i - 1] = Room[101];
			save();
			system("cls");
			printf("退房成功\n");
		}
		else
		{
			system("cls");
			printf("该房间为空房\n");
		}
	}
	printf("要返回首页吗？(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		OutRoom();
	}
	system("cls");
}
void FreeRoom()     //查询客房整体入住信息
{
	int f, sum;
	sum = 0;
	system("cls");
	printf("                                  客房入住信息\n");
	for (f = 0; f < NUM; f++)
	{
		if (Room[f].Sign == 1)
		{
			printf("%d号房已入住\n", f + 1);
			sum = sum + 1;
		}
	}
	printf("\n总共总共1~100号房间中有%d个房间已入住，剩余%d个房间为空房。 \n", sum, NUM - sum);
	printf("要返回首页吗？(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		FreeRoom();
	}
	system("cls");
}
int main()      //主函数
{
	int i, j;
	system("mode con cols=82");
		load();
	system("cls");
	for (j = 0; j < NUM; j++)   //为房间状态赋值为0，当有人入住时，其值改变为1
	{
		Room[j].RoomID = j + 1;
	}
	do                  //菜单栏
	{
		printf("\n");
		printf("     ***********************************************************************     \n");
		printf("   ************************欢迎使用客房登记系统*******************************   \n");
		printf(" ***********************好消息!!!!特价钟点房40元/小时*************************** \n");
		printf("|                                                                               |\n");
		printf("|\t1.--登记客房信息                                                        |\n");
		printf("|\t2.--查询客房信息                                                        |\n");
		printf("|\t3.--修改客房信息                                                        |\n");
		printf("|\t4.--用户退房管理                                                        |\n");
		printf("|\t5.--显示当前空房信息                                                    |\n");
		printf("|\t6.--退出客房管理系统                                                    |\n");
		printf("|                                                                               |\n");
		printf("|*******************************************************************************|\n");
		printf("|********************>>>>李楠（2）班-20151101134<<<<*********************|\n");
		printf("|*******************************************************************************|\n\n");
		printf("输入需要选择的功能:");
		scanf("%d", &i);
		switch (i)            //通过输入相应数字调用不同函数进行相应工作
		{
		case 1:LoginRoom();
			break;
		case 2:SearchRoom();
			break;
		case 3:ChangeRoom();
			break;
		case 4:OutRoom();
			break;
		case 5:FreeRoom();
			break;
		case 6:printf("谢谢使用客房登记系统,正在退出..........\n退出成功，按任意键关闭程序!!\n");
			break;
		default:
			system("cls");
			printf("\n 输入错误，请从新选择\n");
			break;
		}
	} while (i != 6);
	return 0;
}
