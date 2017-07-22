#include "Solution.h"

double Solution::findMaxAverage(vector<int>& nums, int k)
{
	int length=nums.size();
	int total=0;
	int index=0;
	for(;index<k;index++)
	{
		total=nums[index]+total;
	}
	index=1;
	int med=total;
	for(;index<length-k+1;index++)
	{
		med=med-nums[index-1]+nums[index+k-1];
		if(med>total)
			total=med;

	}
	double a=double(total)/k;
	return a;
}