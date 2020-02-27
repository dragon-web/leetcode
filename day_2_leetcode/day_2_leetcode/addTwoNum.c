#include"common.h"
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。*/


struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* p1 = l1;
	struct ListNode* p2 = l2;
	int num1 = 0;
	int num2 = 0;
	int length = 0;
	while (p1 !=  NULL)
	{
		p1 = p1->next;
		num1++;
	}
	while (p2 != NULL)
	{
		p2 = p2->next;
		num2++;
	}
	p1 = l1;
	p2 = l2;
	length = num1 > num2 ? num1 : num2;
	struct ListNode *q = (struct ListNode*)malloc(sizeof(struct ListNode)*length);
	while (q != NULL)
	{
		if (p1 != NULL && p2 != NULL)
		{
			q->val = p1->val + p2->val;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1 == NULL)
		{
			q->val = 0 +  
		}
		else if (p2 == NULL)
		{
			q->val =
		}
	}



}
int main()
{

	system("pause");
	return 0;
}