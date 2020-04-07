#include <stdio.h>
#include<stdlib.h>
/*int main()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		if ('A' <= c && 'Z' >= c)
		{
			c = (c > 'E') ? (c - 5) : (c + 21);
		}
		putchar(c);
	}
	system("pause");
	return 0;
}
//自动对齐，ctrl +A  ctrl+K+F
//找因子



//需要注意就是这个是sqrt(x)
#include <iostream>
#include<math.h> 
using namespace std; 
int main()
{

int n, k, i;
while (cin >> n) {
	k = 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if ((n % i) == 0) {
			while ((n % i) == 0) { n = n / i; }
			k++;
		}
	}
	if (n != 1)
		k++;
	cout << k << endl;
}
system("pause");
return 0;
 }
 */
//两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。 
//许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。



#include <string> 
#include <iostream>
#include <vector>
using namespace std;

int minDistance(string word1, string word2)
{        // word与空串之间的编辑距离为word的长度        if (word1.empty() || word2.empty()) {            return max(word1.size(), word2.size());        }

	int len1 = word1.size();  
	int len2 = word2.size();        // F(i,j)初始化
	vector<vector<int> >  f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i) { f[i][0] = i; }    
	for (int i = 0; i <= len2; ++i) { f[0][i] = i; }

	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {        
			// F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-1,j-1) +                      //(w1[i]==w2[j]?0:1) }                 // 判断word1的第i个字符是否与word2的第j个字符相等                if (word1[i - 1] == word2[j - 1]) {                    f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);                    // 字符相等，F(i-1,j-1)编辑距离不变                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);                }                else {                    f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);                    // 字符不相等，F(i-1,j-1)编辑距离 + 1                    f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);                }            }        }

			return f[len1][len2];
		}
		int main()
		{
			string a, b; while (cin >> a >> b)
			{
				cout << minDistance(a, b) << endl;
			}
			return 0;
		}