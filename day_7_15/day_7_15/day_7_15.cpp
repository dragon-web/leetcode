#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
/*
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int count1 = 0, count2 = 0;
		while (l1 != NULL)
		{
			l1 = l1->next;
			count1++;
		}
		while (l2 != NULL)
		{
			l2 = l2->next;
			count2++;
		}
		int count = count1 > count2 ? count1 : count2;
		static ListNode* p = (ListNode*)malloc(count * sizeof(ListNode));
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		while (l1 != NULL && l2 != NULL)
		{
			p->val = l1->val + l2->val;
			p = p->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		return p;
	}
};

int  test()
{
	static int* p = (int*)malloc(sizeof(int));
	*p = 4;
	return *p;
}
*/

void* helloworld(char* argc)
{
	int *p;
	p = (int *)malloc(100);
	printf("the message is %s\n", argc);
	return (void*)p;
}

int ***** add()
{
	int *****p = NULL;
	return p;
}
int main()
{
	char p[10] = "45";
	helloworld(p);
	//printf("*p = %x, p = %x\n", *helloworld, helloworld);
	add();
	cout << add << endl;
	cout << *add << endl;
	system("pause");
	return 0;
}