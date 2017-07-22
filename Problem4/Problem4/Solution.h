#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m=nums1.size();
		int n=nums2.size();
		int point1=0,point2=0;
		double median;
		if((m+n)%2!=0)
		{
			if(m==0)
			{
				point2=n/2+1;
				median=nums2[point2];
			}
			else if(n==0)
			{
				point2=m/2+1;
				median=nums2[point2];
			}
			else
			{
				if(m<n&&nums1[m-1])
				{
					
				}
			}
		}
		else
		{
			if(m==0)
			{
				point1=n/2;
				point2=point1+1;
				median=(nums1[point1]+nums1[point2])/2;
			}
			else if(n==0)
			{
				point1=m/2;
				point2=point1+1;
				median=(nums1[point1]+nums1[point2])/2;
			}
			else
			{
			
			}		
		}
    }
};