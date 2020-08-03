#define _CRT_SECURE_NO_WARNINGS 

/*
#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int N, M, T;
	cin >> N >> M >> T;
	vector<int> lunch1;
	vector<int> lunch2;
	vector<int> dinner1;
	vector<int> dinner2;
	int Xi;
	int Yi;
	int Xj;
	int Yj;
	int min = 10000;
	for (int i = 0; i < N; ++i)
	{
		cin >> Xi >> Yi;
		lunch1.push_back(Xi);
		lunch2.push_back(Yi);
	}
	for (int j = 0; j < M; ++j)
	{
		cin >> Xj >> Yj;
		dinner1.push_back(Xj);
		dinner2.push_back(Yj);
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (lunch2[i] + dinner2[j] >= T)
			{
				min = lunch1[i] + dinner1[j] < min ? lunch1[i] + dinner1[j] : min;
			}
		}
	}
	if (min == 1000)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << min << endl;
	}
	system("pause");
	return 0;
}
*/


#include<iostream>
#include<vector>
using namespace std;



int main()
{



	system("pause");
	return 0;
}