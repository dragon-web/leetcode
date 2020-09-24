#include<iostream>
#include<vector>

using namespace std;


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
  int arr[] = {1,-2,3,10,-4,7,2,-5};
  int sz = sizeof(arr)/sizeof(arr[0]);
   vector<int> res;
  for(int i = 0;i < sz ;++i)
  {
    res.push_back(arr[i]);
  }
  Solution test;
  test.FindGreatestSumOfSubArray(res);



  return 0;
}



