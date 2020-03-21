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
void LoginRoom()     //�Ǽǿͷ���Ϣ����
{
	int i, n, k;
	n = 0;
	system("cls");
	printf("                                     �û��Ǽ�\n");
	for (k = 0;; k++)
	{
		printf("������ͷ���:\n");
		scanf("%d", &i);
		if (Room[i - 1].Sign == 1)
		{
			printf("�Բ��𣬸÷�������ס,���������롣\n");
			n = n + 1;
		}
		if (n == 5)
		{
			printf("\n���ѯ����ͷ���ס��Ϣ�������Ǽǣ�лл");
			Sleep(1500);
			system("cls");
			return;
		}
		if (Room[i - 1].Sign != 1)
			break;
	}
	printf("����ţ�%d\n", i);
	printf("�ͻ�����:");
	scanf("%s", (char *)&Room[i - 1].Clientlist.Name);
	printf("�Ա�:");
	scanf("%d", &Room[i - 1].Clientlist.Sex);
	printf("����:");
	scanf("%d", &Room[i - 1].Clientlist.Age);
	printf("���֤����:");
	scanf("%s", (char *)&Room[i - 1].Clientlist.IDcard);
	printf("��ϵ�绰:");
	scanf("%s", (char *)&Room[i - 1].Tel);
	printf("��סʱ��:");
	scanf("%s", (char *)&Room[i - 1].Clientlist.date);
	printf("ס��ʱ��:");
	scanf("%d", &Room[i - 1].Clientlist.hour);
	Room[i - 1].RoomID = i;
	Room[i - 1].Price = (Room[i - 1].Clientlist.hour) * 40;
	Room[i - 1].Sign = 1;
	save();
	printf("��ϲ,�Ǽǳɹ�!!\nҪ������ҳ��(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		LoginRoom();
	}
	system("cls");
}
void save()      //���ͷ���ס��Ϣ���浽�ļ���
{
//	int i;
	FILE *fp;
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}
	fwrite(Room, sizeof(struct room), NUM, fp);
	printf("�ļ�д�����\n");
	fclose(fp);
}
void SearchRoom()    //��ѯ�ͷ���Ϣ
{
	int k;
	system("cls");
	printf("                                  ��ѯ�ͷ���Ϣ\n");
	printf("������Ҫ��ѯ�ķ������:\n");
	scanf("%d", &k);
	if (k <= 0 || k > 100)
	{
		printf("�Բ���û����Ӧ�ķ��䡣\n");
		SearchRoom();
	}
	if (Room[k - 1].Sign == 1)
	{
		printf("����:%s\n", Room[k - 1].Clientlist.Name);
		if (Room[k - 1].Clientlist.Sex == 1)
		{
			printf("�Ա�:��\n");
		}
		else
		{
			printf("�Ա�Ů\n");
		}
		printf("����:%d\n", Room[k - 1].Clientlist.Age);
		printf("���֤��:%s\n", Room[k - 1].Clientlist.IDcard);
		printf("��ϵ�绰:%s\n", Room[k - 1].Tel);
		printf("��סʱ��:%s\n", Room[k - 1].Clientlist.date);
		printf("��סʱ��:%d\n", Room[k - 1].Clientlist.hour);
		printf("����:%ld\n", Room[k - 1].Price);
	}
	else
	{
		system("cls");
		printf("�ܱ�Ǹ,û���ҵ��÷���Ǽǵ������Ϣ!!\n\n");
	}
	printf("Ҫ������ҳ��(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		SearchRoom();
	}
	system("cls");
}
void load()      //���ļ��ж�ȡ�ͷ���ס��Ϣ
{
	FILE *fp;
	int i;
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		return;
	}
	for (i = 0; !feof(fp); i++)
	{
		fread(&Room[i], sizeof(struct room), 1, fp);
	}
	fclose(fp);
	system("cls");
	printf("�ļ���ȡ�ɹ�\n");
}
void ChangeRoom()      //�޸Ŀͷ���ס��Ϣ
{
	int i, n;
	system("cls");
	printf("                                  �޸Ŀͷ���Ϣ\n");
	printf("�����뷿���:\n");
	scanf("%d", &i);
	if (Room[i - 1].Sign == 1)
	{
		printf("\t1.--�޸Ŀͻ�����\n");
		printf("\t2.--�޸Ŀͻ��Ա�\n");
		printf("\t3.--�޸Ŀͻ�����\n");
		printf("\t4.--�޸�ס��ʱ��\n");
		printf("\t5.--�޸�ס��ʱ������ס��\n");
		printf("\t6.--�޸Ŀͻ��绰����\n");
		printf("\t7.--�޸Ŀͻ����֤��\n");
		printf("������Ҫ�޸ĵ��");
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
		default:printf("������������ѡ��");
			break;
		}
		save();
		printf("�޸ĳɹ���");
	}
	else
	{
		system("cls");
		printf("�÷���Ϊ�շ�!!\n");
	}
	printf("\nҪ������ҳ��(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		ChangeRoom();
	}
	system("cls");
}
void OutRoom()      //�˷�����
{
	int i, j;
	system("cls");
	printf("                                    �˷�����\n");
	printf("�����뷿���:\n");
	scanf("%d", &i);
	printf("ȷ��Ҫ��%d�ŷ���(1:Y/0:N)", i);
	scanf("%d", &j);
	if (j == 1)
	{
		if (Room[i - 1].Sign == 1)
		{
			Room[i - 1] = Room[101];
			save();
			system("cls");
			printf("�˷��ɹ�\n");
		}
		else
		{
			system("cls");
			printf("�÷���Ϊ�շ�\n");
		}
	}
	printf("Ҫ������ҳ��(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		OutRoom();
	}
	system("cls");
}
void FreeRoom()     //��ѯ�ͷ�������ס��Ϣ
{
	int f, sum;
	sum = 0;
	system("cls");
	printf("                                  �ͷ���ס��Ϣ\n");
	for (f = 0; f < NUM; f++)
	{
		if (Room[f].Sign == 1)
		{
			printf("%d�ŷ�����ס\n", f + 1);
			sum = sum + 1;
		}
	}
	printf("\n�ܹ��ܹ�1~100�ŷ�������%d����������ס��ʣ��%d������Ϊ�շ��� \n", sum, NUM - sum);
	printf("Ҫ������ҳ��(1:Y,0:N)");
	scanf("%d", &j);
	if (j == 0)
	{
		FreeRoom();
	}
	system("cls");
}
int main()      //������
{
	int i, j;
	system("mode con cols=82");
		load();
	system("cls");
	for (j = 0; j < NUM; j++)   //Ϊ����״̬��ֵΪ0����������סʱ����ֵ�ı�Ϊ1
	{
		Room[j].RoomID = j + 1;
	}
	do                  //�˵���
	{
		printf("\n");
		printf("     ***********************************************************************     \n");
		printf("   ************************��ӭʹ�ÿͷ��Ǽ�ϵͳ*******************************   \n");
		printf(" ***********************����Ϣ!!!!�ؼ��ӵ㷿40Ԫ/Сʱ*************************** \n");
		printf("|                                                                               |\n");
		printf("|\t1.--�Ǽǿͷ���Ϣ                                                        |\n");
		printf("|\t2.--��ѯ�ͷ���Ϣ                                                        |\n");
		printf("|\t3.--�޸Ŀͷ���Ϣ                                                        |\n");
		printf("|\t4.--�û��˷�����                                                        |\n");
		printf("|\t5.--��ʾ��ǰ�շ���Ϣ                                                    |\n");
		printf("|\t6.--�˳��ͷ�����ϵͳ                                                    |\n");
		printf("|                                                                               |\n");
		printf("|*******************************************************************************|\n");
		printf("|********************>>>>��骣�2����-20151101134<<<<*********************|\n");
		printf("|*******************************************************************************|\n\n");
		printf("������Ҫѡ��Ĺ���:");
		scanf("%d", &i);
		switch (i)            //ͨ��������Ӧ���ֵ��ò�ͬ����������Ӧ����
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
		case 6:printf("ллʹ�ÿͷ��Ǽ�ϵͳ,�����˳�..........\n�˳��ɹ�����������رճ���!!\n");
			break;
		default:
			system("cls");
			printf("\n ������������ѡ��\n");
			break;
		}
	} while (i != 6);
	return 0;
}
