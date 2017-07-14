#include "Solution.h"

ListNode* Solution::addTwoNumbers (ListNode* l1, ListNode* l2)
{
	ListNode* point1=l1;
	ListNode* point2=l2;
	int a=l1->val+l2->val;
	int b=a/10;
	a=a%10;
	point1=l1->next;
	point2=l2->next;
	
	ListNode* listhead=new ListNode(a);
	ListNode* point3=listhead;
	while(point1!=NULL||point2!=NULL)
	{
		if(point1!=NULL)
			{
				a=point1->val;
				point1=point1->next;
			}
		else
			a=0;
		if(point2!=NULL)
			{
				a=a+point2->val;
				point2=point2->next;
			}

		a=a+b;
		b=a/10;
		a=a%10;
		
		point3->next=new ListNode(a);
		point3=point3->next;
	}
	if (b==1)
	{
		
		point3->next=new ListNode(1);
	}
	return listhead;

}

ListNode* Solution::generateListNode(std::vector<int>data)
{
	
	ListNode* head=new ListNode(data[0]);
	ListNode* point=head;
	for(int i=1;i<data.size();i++)
	{
		// ListNode med(data[i]);
		ListNode* med=new ListNode(data[i]);
		point->next =med;
		point=point->next;
	}
	return head;
}

void Solution::showlist(ListNode*l)
{
	ListNode* point=l;
	while(point!=NULL)
	{
		std::cout<<point->val<<" ";
		point=point->next;
	}
	std::cout<<std::endl;
}