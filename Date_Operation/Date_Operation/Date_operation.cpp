#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<Windows.h>
int isYear(int year) 
{
	return(year % 4 == 0) && (year % 400 == 0 || year % 100 != 0) ? 1 : 0;
}

//返回该年 year 该月bai month 的最大天数 
int getDayOfMonth(int year,int month) {

	int dayArr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	return(month == 2 && isYear(year) == 1) ? dayArr[month] + 1 : dayArr[month];
}

//获取两个日du期之间的天数，第一个日期必须比第二个日期小  ：) 
int getTotalDay(int year1,int month1,int day1,int year2,int month2,int day2) {

	long total = 0;

	for (int year = year1; year < year2 ;year++) {
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

int main() {

	int year1, month1, day1;
	int year2, month2, day2;

	do {//控制日期输进合法，同时year1应该小于year2 
		printf("\n Input year1-month1-day1\n(such as 2012-12-12):");
		scanf("%d-%d-%d", &year1, &month1, &day1);
	} while (year1 < 0 || month1 < 1 || month1>12 || day1<1 || day1 > getDayOfMonth(year1, month1));


	do {//控制日期输进合法 
		printf("\n\n\nInput year2-month2-day2\n(such as 2014-12-12) : ");
		scanf("%d-%d-%d", &year2, &month2, &day2);
	} while (year2 < 0 || year2  < year1 || month2 < 1 || month2>12 || day2<1 || day2 > getDayOfMonth(year2, month2));

	printf("\n Between two date have: %ld days \n\n\n", getTotalDay(year1, month1, day1, year2, month2, day2));
	system("pause");
	return 0;
}