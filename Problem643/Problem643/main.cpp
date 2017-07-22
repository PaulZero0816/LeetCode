#include "Solution.h"

int main()
{
	int a[5]={0,4,0,3,2};
	vector<int> nums(a,a+5);
	int k=1;
	Solution A;
	double b=A.findMaxAverage(nums,k);
	cout<<b<<endl;
}