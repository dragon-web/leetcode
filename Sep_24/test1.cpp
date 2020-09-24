#include<iostream>
#include<vector>

using namespace std;

//写出来的是连续最大正数的和

class Solution {
  public:
    int sumVector(vector<int> dp)
    {
      int sum = 0;
      auto it = dp.begin();
      while(it != dp.end())
      {
        sum+= *it;
        it++;

      }
      return sum;

    }
    int FindGreatestSumOfSubArray(vector<int> array) {
      vector<int> temp1;
      vector<int> temp2;
      vector<int>::iterator it = array.begin();
      while(it != array.end())
      {
        if(*it >= 0)
        {
          temp2.push_back(*it);

        }
        if(*it < 0)
        {
          temp2.clear();

        }
        if(sumVector(temp1) <= sumVector(temp2))
        {
          temp1 = temp2;

        }    
        it++;

      }   
      return sumVector(temp1);
    }

};

int main()
{
  int num = 13;
  Solution a;
  a.operator=




}


