//Test Code
#include "Problem403.h"

int main()
{
	int a[8]={0,1,3,5,6,8,12,17};
	int b[8]={0,1,2,3,4,8,9,11};
	int c[5]={0,1,3,6,7};
	vector<int>a1(a,a+8);
	vector<int>b1(b,b+8);
	vector<int>c1(c,c+8);
	Solution A;
	bool result=A.canCross2(a1);
	cout<<result<<endl;
}