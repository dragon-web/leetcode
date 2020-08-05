#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;

int gcd(int a, int b) //求最大公约数
{
	int min = a > b ? b : a;
	int res = 1;
	for (int i = 1; i <= min; ++i)
	{
		if (a % i == 0 && b % i == 0)
		{
			res = i;
		}
	}
	return res;
}
//k是最大公约数
void Judge_Good_num(int sum,int k)
{
	int a = -1;
	int b = -1;
	int c = -1;
	for (int i = 1; i <= sum; ++i)
	{
		for (int j = 1; j <= sum; ++i)
		{
			for (int p = 1; p <= sum; ++p)
			{
				if (gcd(i, j) == k && gcd(i, p) == k && gcd(j, p) == k && i +j +p == sum)
				{
					a = i;
					b = j;
					c = p;
				}
			}
		}
	}
	cout << a << " " << b << " " << c << endl;
}
int main()
{



	system("pause");
	return 0;
}