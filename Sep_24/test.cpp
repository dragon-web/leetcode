#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int Count_One(int &num)
    {
      int count = 0;
      while(num != 0)
      {
        if(num % 10 == 1)
        {
          count++;

        }
        num /= 10;

      }
      return count;

    }

    int NumberOf1Between1AndN_Solution(int n)
    {
      int sum = 0;
      int count = 0;
      for(int i = 1;i <= n;++i)
      {
        count = Count_One(i);
        sum += count;
        count = 0;

      }
      return sum;        
    }   
};

int main()
{
  int num = 13;
  Solution a;
  int res = a.NumberOf1Between1AndN_Solution(num);
  cout << res<<endl;
  return 0;
}

