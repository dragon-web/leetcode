#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>

using namespace std;
/*
class Solution {
public:
	string longestPalindrome(string s) {
		auto it1 = s.begin();
		string temp;
		auto it2 = it1;
		while (it2 != s.end())
		{

			string temp1(it1, it2);
			auto t1 = temp1.begin();
			auto t2 = temp1.end() - 1;
			while (t1 < t2)
			{
				if (*t1 == *t2)
				{
					temp.push_back(*it1);
				}
				else
				{
					temp.clear();
				}
				t1++;
				t2--;
			}
		}

	}
};
*/
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0)
			return "\0";
		int i, j;
		int max = 1;
		int temp;
		int k = 0;
		for (i = 0; i < s.size(); i++)
		{
			temp = 1;
			for (j = 1; j <= i; j++)  // 当为奇数的
			{
				if (j + i >= s.size())
					break;
				else if (s[i - j] == s[i + j])
					temp += 2;
				else
				{
					break;
				}
			}
			if (temp > max)
			{
				max = temp;
				k = i - max / 2;
			}
			temp = 0;
			for (j = 0; j <= i; j++)
			{
				if (j + i + 1 >= s.size())
					break;
				else if (s[i - j] == s[i + j + 1])
					temp += 2;
				else {
					break;
				}
			}
			if (temp > max)
			{
				max = temp;
				k = i + 1 - max / 2;
			}
		}
		return s.substr(k, max);
	}
};

int main()
{







	system("pause");
	return 0;
}