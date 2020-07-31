#define _CRT_SECURE_NO_WARNINGS 
//øÏ≈≈  ≤Â≈≈  πÈ≈ƒ  ∂—≈≈  
/*
#include<stdio.h>
#include<Windows.h>


void Sift(int R[], int low, int high)
{
	int i = low, j = 2 * i;
	int temp = R[i];
	while (j <= high)
	{
		if (j < high&&R[j] < R[j + 1])
			++j;
		if (temp < R[j])
		{
			R[i] = R[j];
			i = j;
			j = 2 * i;
		}
		else
		{
			break;
		}
	}
	R[i] = temp;
}

void heapSort(int R[], int n)
{
	int i;
	int temp;
	for (i = n / 2; i >= 1; --i)
	{
		Sift(R, i, n);
	}
	for (i = n; i >= 2; --i)
	{
		temp = R[1];
		R[1] = R[i];
		R[i] = temp;
		Sift(R, 1, i - 1);
	}
}


int main()
{ 
	int arr[] = { 1,8,9,7,55,0,5,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, sz);
	for (int i = 0; i < sz; ++i)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
*/