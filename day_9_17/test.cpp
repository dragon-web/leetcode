#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
    val(x), next(NULL) {
    }
};
class Solution {
  public:
    bool Find(vector<int> & dp,ListNode* p)
    {
      auto it = dp.begin();
      int flag = 0;
      while(it != dp.end()) 
      {
        if(*it == p->val)
        {
          flag = 1;
          return false;  //说明找到重复的需要删除这个节点

        }
        it++;

      }
      if(flag == 0)  //说明没有找到
      {
        dp.push_back(p->val);
        return true;
      }
    }
    ListNode* deleteDuplication(ListNode* pHead)
    {
      if(pHead == NULL)
      {
        return pHead;

      }
      if(pHead != NULL)
      {
        vector<int> dp;
        ListNode* pst = pHead->next;
        ListNode* temp = pHead;
        while(pst != NULL)
        {
          if(!Find(dp,pst))
          {
            temp->next = pst->next;
            delete pst;
            pst = temp->next;

          }
          temp = temp->next;
          pst = pst->next;

        }
        return pHead;

      }        

    }

}; 


int main()
{
  Solution a;
  ListNode l1(1);
  ListNode l2(2);
  ListNode l3(1);
  ListNode l4(3);
  ListNode l5(2);
  ListNode l6(1);
  ListNode l7(3);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  l5.next = &l6;
  l6.next = &l7;
a.Solution::deleteDuplication(&l1);
  return 0;
}




