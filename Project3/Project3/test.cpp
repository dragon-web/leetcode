#define _CRT_SECURE_NO_WARNINGS 
/*
#include<iostream>
#include<string>

using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		auto it1 = str1.begin();
		auto it2 = str2.begin();
		while (it2 != str2.end())
		{
			while (it1 != str1.end()&&it2 != str2.end())
			{
				if (*it1 == *it2)
				{
					str1.erase(it1);
					it1 = str1.begin();
					it2++;
				}
				else { it1++; }
			}
			if (it2 != str2.end())
			{
				it2++;
				it1 = str1.begin();
			}
		}
		cout << str1 << endl;
	}

	return 0;
}
#include<iostream>
#include<string>
using namespace std;

int hashtable[256];
void initTable(char *substr)
{
	memset(hashtable, 0, sizeof(hashtable));
	char *p = substr;
	while (*p != '\0')
	{
		hashtable[*p] = 1;
		p++;
	}
	p = NULL;
}
char *Delete(char *source, char *substr)
{
	char *fast = source;
	char *slow = source;

	while (*fast != '\0')
	{
		if (hashtable[*fast] != 1)
		{
			*slow = *fast;
			slow++;
		}
		fast++;
	}
	*slow = '\0';
	return source;
}

int main()
{
	int N = 20;
	char *source = (char *)malloc(sizeof(char)*N);
	char *substr = (char *)malloc(sizeof(char)*N);
	cin >> source;
	cin >> substr;
	initTable(substr);
	getchar();
	getchar();
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	int n, i = 0;
	cin >> n;
	int sum = 0;
	int temp = sum;
	int *p = new int[n]();
	while (i < n)
	{
		cin >> p[i];
		i++;
	}
	for (int j = 0; j < n; ++j)
	{
		if (temp > sum)
		{
			if (p[j] > 0)
			{
				sum += p[j];
			}
			else
			{
				temp = sum;
				sum = 0;
			}
		}
	}
	sum = sum > temp ? sum : temp;

	cout << sum <<endl;
	system("pause")
	return 0;
}


#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	unordered_set<char> hash;
	for (int i = 0; i < b.size(); i++) {
		hash.insert(b[i]);
	}
	string res;
	for (int i = 0; i < a.size(); i++) {
		if (hash.count(a[i]) == 0) res += a[i];
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	return 0;
}*/


#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int vec[4];
	int i = 0, j = 0;
	while (i < 4)
	{
		cin >> vec[i];
		++i;
	}
	int arr = 0;
	while (j < 4)
	{
		arr += vec[j];
		++j;
	}
	if (arr == 24)
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}