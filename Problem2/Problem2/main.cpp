#include "Solution.h"


int main()
{
	int a[1]={1};
	int b[1]={2};
	std::vector<int>a2(a,a+1);
	std::vector<int>b2(b,b+1);
	Solution A;
	ListNode* l1=A.generateListNode(a2);
	ListNode* l2=A.generateListNode(b2);
	A.showlist(l1);
	A.showlist(l2);
	ListNode* l3=A.addTwoNumbers(l1,l2);
	A.showlist(l3);
}
