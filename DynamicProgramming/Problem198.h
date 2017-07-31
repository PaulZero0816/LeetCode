/*
House Robber

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money
of each house, determine the maximum amount of money you can rob 
tonight without alerting the police.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int length=nums.size();
		vector<int> selected;
		vector<int> unselected;
		selected.resize(length);
		unselected.resize(length);
		if(length!=0)
		{
		selected[0]=nums[0];
		unselected[0]=0;
		for(int i=1;i<length;i++)
		{
			selected[i]=unselected[i-1]+nums[i];
			if(selected[i-1]>unselected[i-1])
				unselected[i]=selected[i-1];
			else
				unselected[i]=unselected[i-1];
		}
		if(selected[length-1]>unselected[length-1])
			return selected[length-1];
		else
			return unselected[length-1];
		}
		else if(length!=1)
			return 0;
        else 
            return selected[0];
    }
};

// Test code
/*
#include "Problem198.h"

int main()
{
	int a[10]={5,2,4,8,3,5,1,2,4,5};
	vector<int>nums(a,a+10);
	Solution A;
	int total=A.rob(nums);
	cout<<total<<endl;
}
*/
