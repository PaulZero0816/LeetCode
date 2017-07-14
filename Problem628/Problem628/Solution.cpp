#include "Solution.h"

 int Solution::maximumProduct(vector<int>& nums) {
		std::vector<int>positive;
		std::vector<int>negtive;
		int minpositive=2000;
		int maxnegtive=-2000;
		int product;
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]>=0)
			{
				if(positive.size()<3)
				{
					positive.push_back(nums[i]);
					if(nums[i]<minpositive)
					{
						minpositive=nums[i];
					}
				}
				else
				{
					if(nums[i]>minpositive)
					{
						for(int j=0;j<3;j++)
						{
							if(positive[j]==minpositive)
							{
								positive[j]=nums[i];
								break;
							}
						}
						minpositive=2000;
						for(int j=0;j<3;j++)
						{
							if(positive[j]<minpositive)
							{
								minpositive=positive[j];
							}
						}
					}
				}
			}
			else
			{
				if(negtive.size()<3)
				{
					negtive.push_back(nums[i]);
					if(nums[i]>maxnegtive)
					{
						maxnegtive=nums[i];
					}
				}
				else
				{
					if(nums[i]<maxnegtive)
					{
						
							if(negtive[0]==maxnegtive)
								negtive[0]=nums[i];
							else if(negtive[1]==maxnegtive)
								negtive[1]=nums[i];
							else
								negtive[2]=nums[i];
						
						maxnegtive=-2000;
						
							if(negtive[0]>maxnegtive)
								maxnegtive=negtive[0];
							if(negtive[1]>maxnegtive)
								maxnegtive=negtive[1];
							if(negtive[2]>maxnegtive)
								maxnegtive=negtive[2];
					}
				}
			}

		}
		if(positive.size()==0)
		{
			product=negtive[0]*negtive[1]*negtive[2];
		}
		else if(negtive.size()<2)
		{
			product=positive[0]*positive[1]*positive[2];
		}
		
		else
		{
			int max=0;
			for(int i=0;i<positive.size();i++)
			{
				if(positive[i]>max)
					max=positive[i];
			}
			if(negtive.size()==2)
			{
				if(positive.size()==2)
				{
				product=max*negtive[0]*negtive[1];
				}
				else
				{
				int a=max*negtive[0]*negtive[1];
				int b=positive[0]*positive[1]*positive[2];
				if(a>b)
					product=a;
				else
					product=b;
				}
			}
			else
			{
			int a=max*negtive[0]*negtive[1];
			int b=max*negtive[0]*negtive[2];
			int c=max*negtive[1]*negtive[2];
			int d=positive[0]*positive[1]*positive[2];
			product=a;
			if(b>product)
				product=b;
			if(c>product)
				product=c;
			if(d>product)
				product=d;
			}
		}
		return product;
		
		}