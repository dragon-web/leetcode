#define _CRT_SECURE_NO_WARNINGS 

/*#include<stdio.h>

#include<stdlib.h>

void Print(int N)
{
	//����ռ�
	//�Ǿ�������㹻��Ŀռ�
	int arr[50][50] = { 0 };//����ȫ����ʼ��Ϊ0

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)//�ѭ�����
		{
			if (j == 0 || j == i)
			{
				arr[i][j] = 1; //�ж�����λ��  ���ö���
				continue;
			}
			else//˵�����ڵ�һ��
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];//��һ��ͬ��Ԫ����ǰһ��Ԫ��֮��  ���ö���
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}
int main()
{
	int row;
	printf("��������Ҫ��ӡ������");
	scanf_s("%d", &row);
	Print(row);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char name1[100];
	char name2[100];
	char name3[100];	
    scanf("%s",name1);
	scanf("%s", name2);
	scanf("%s", name3);
	//���ֱȴ�С������ĸ��ASCLLֵ�ȴ�С
	char* res = name1 > name2 ? name1 : name2;
	res = res > name3 ? res : name3;
	printf("%s", res);
	system("pause");
	return 0;
}
*/

//ת�þ���
/*
#include<stdio.h>
#include<stdlib.h>
void Des(int arr[100][100],int row,int line)
{
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			printf("%d ", arr[j][i]);
		}
		printf("\n");
	}

}
void print(int arr[100][100], int row, int line)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < line; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int row;
	int line;
	printf("����������");
	scanf("%d", &row);
	printf("����������");
	scanf("%d", &line);
	int arr[100][100];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < line; ++j)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("ת��ǰ�ľ���\n");
	print(arr, row, line);
	printf("ת�ú�ľ���\n");
	Des(arr,row, line);

	system("pause");
	return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(char str[10][20])//ָ�������Ԫ�صĵ�ַ
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 10 - i - 1; ++j)
		{
			if (*(str[j]) > *(str[j+1]))
			{
				char* temp = NULL;
				temp = *(str[j]);//��ָ��
				*(str[j]) = *(str[j + 1]);
				*(str[j + 1]) = temp;
			}
		}
	}
}
int main()
{
	char str[10][20];
	int i;
	for (i = 0; i < 10; i++)
		gets(*(str + i));
	printf("����õ��ַ���\n");
	sort(str);
	for (i = 0; i < 10; i++)
		puts(*(str + i));
	system("pause");
	return 0;
}