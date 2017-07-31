#include "Problem644.h"

double Solution::findMaxAverage(vector<int>& nums, int k)
{
	if(nums.size()<k)
		return -10001; // NegInfinite
	
	int length=nums.size();
	int med=length/2;
	vector<int>left;
	vector<int>right;
	for(int i=0;i<med+1;i++)
		left.push_back(nums[i]);
	for(int i=med+1;i<length;i++)
		right.push_back(nums[i]);
	double maxleft=this->findMaxAverage(left,k);
	double maxright=this->findMaxAverage(right,k);
	double maxmid=0;
	double maxmidleft=-10001,maxmidright=-10001;
	double a=0;
	int number=0;
	int leftnum=0,rightnum=0;
	for(int i=med;i>=0;i--)
	{
		a=a+nums[i];
		number++;
		if(a/double(number)>maxmidleft)
		{
			maxmidleft=a/double(number);
			leftnum=number;
		}
	}
	a=0;
	number=0;
	for(int i=med+1;i<=length;i++)
	{
		a=a+nums[i];
		number++;
		if(a/double(number)>maxmidright)
		{
			maxmidright=a/double(number);
			rightnum=number;
		}
	}
	if(rightnum+leftnum>=k)
	{
	maxmid=(maxmidleft*leftnum+maxmidright*rightnum)/(leftnum+rightnum);
	if(maxleft>maxmid)
		if(maxleft>maxright)
			return maxleft;
		else
			return maxright;
	else
		if(maxmid>maxright)
			return maxmid;
		else 
			return maxright;
	}
	else
	{
	
	}
}