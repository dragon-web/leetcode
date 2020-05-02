#define _CRT_SECURE_NO_WARNINGS 

/*#include<stdio.h>

#include<stdlib.h>

void Print(int N)
{
	//申请空间
	//那就申请个足够大的空间
	int arr[50][50] = { 0 };//数组全部初始化为0

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)//搭建循环框架
		{
			if (j == 0 || j == i)
			{
				arr[i][j] = 1; //判断特殊位置  看得懂？
				continue;
			}
			else//说明大于第一行
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];//上一行同列元素与前一列元素之和  看得懂？
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
	printf("请输入你要打印的行数");
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
	//名字比大小是首字母的ASCLL值比大小
	char* res = name1 > name2 ? name1 : name2;
	res = res > name3 ? res : name3;
	printf("%s", res);
	system("pause");
	return 0;
}
*/

//转置矩阵
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
	printf("请输入行数");
	scanf("%d", &row);
	printf("请输入列数");
	scanf("%d", &line);
	int arr[100][100];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < line; ++j)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("转置前的矩阵\n");
	print(arr, row, line);
	printf("转置后的矩阵\n");
	Des(arr,row, line);

	system("pause");
	return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(char str[10][20])//指向的是首元素的地址
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 10 - i - 1; ++j)
		{
			if (*(str[j]) > *(str[j+1]))
			{
				char* temp = NULL;
				temp = *(str[j]);//行指针
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
	printf("排序好的字符串\n");
	sort(str);
	for (i = 0; i < 10; i++)
		puts(*(str + i));
	system("pause");
	return 0;
}