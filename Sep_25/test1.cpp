#include<iostream>
#include<vector>
#include<stack>
using namespace std;


struct TreeLinkNode {
  int val;
  struct TreeLinkNode *left;
  struct TreeLinkNode *right;
  struct TreeLinkNode *next;
  TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

  }
};

class Solution {
  public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
        return NULL;
      if(pNode!= NULL)
      {
      vector<TreeLinkNode*> res;
      stack<TreeLinkNode*> dp;
      TreeLinkNode *p = pNode;
      TreeLinkNode* Top;
      while(dp.size() || p != NULL)
      {
        while(p != NULL)
        {
          dp.push(p);
          p = p->left;
        }       
       Top = dp.top();
        dp.pop();
        if(Top != NULL)
        res.push_back(Top);
          p = Top->right; 
      }
    auto it = res.begin();
    while(*it != )



      }



    }
};




int main()
{



  return 0;
}
