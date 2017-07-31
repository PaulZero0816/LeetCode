/*
Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways 
can you climb to the top?
Note: Given n will be a positive integer.
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        vector<int>selected;
		vector<int>unselected;
		selected.resize(n-1);
		unselected.resize(n-1);
		if(n==0)
			return 0;
		else if(n==1)
			return 1;
		else
		{
			selected[0]=1;
			unselected[0]=1;
			for(int i=1;i<n-1;i++) // last step is the top so n-1
			{
				selected[i]=selected[i-1]+unselected[i-1];
				unselected[i]=selected[i-1];
			}
			return selected[n-2]+unselected[n-2];
		}
    }
	int climbStairs2(int n){
		int a=1,b=1,c=1;
		if(n==0)
			return 0;
		else if(n==1)
			return 1;
		else
		{
			for(int i=1;i<n-1;i++)
			{
				c=a;
				a=a+b;
				b=c;
			}
			return a+b;
		}
	}
};

/*
//Test Code

#include "Problem70.h"

int main()
{
	int a=20;
	Solution A;
	int total=A.climbStairs(a);
	cout<<total<<endl;
}*/