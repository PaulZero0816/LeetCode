/*
Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path 
from top left to bottom right which minimizes the sum of all numbers
along its path.

Note: You can only move either down or right at any point in time.
*/

#include <iostream>
#include <vector>
using namespace std;
#define min(a,b) (a>b?b:a)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
		int n=grid[0].size();
		if(m==0&&n==0)
			return 0;
		else
		{
			vector<int>total1,total2;
			total1.resize(n);
			total2.resize(n);
			total1[0]=grid[0][0];
			for(int i=1;i<n;i++)
			{
				total1[i]=total1[i-1]+grid[0][i];
			}
			for(int i=1;i<m;i++)
			{
				if(i%2==0)
				{
					total1[0]=total2[0]+grid[i][0];
					for(int j=1;j<n;j++)
					{
						total1[j]=min(total2[j],total1[j-1]);
						total1[j]=total1[j]+grid[i][j];
					}	
				}
				else
				{
					total2[0]=total1[0]+grid[i][0];
					for(int j=1;j<n;j++)
					{
						total2[j]=min(total1[j],total2[j-1]);
						total2[j]=total2[j]+grid[i][j];
					}
				}		
			}
			if(m%2==0)
				return total2[n-1];
			else
				return total1[n-1];
		}
    }
};

/*
//Test Code
#include "Problem64.h"

int main()
{
	
	int a1[4]={2,3,4,5};
	int a2[4]={3,4,5,2};
	int a3[4]={6,5,4,3};
	int a4[4]={4,1,4,3};

	// int a5[5]={};
	vector<int>b1(a1,a1+4);
	vector<int>b2(a2,a2+4);
	vector<int>b3(a3,a3+4);
	vector<int>b4(a4,a4+4);
	vector<vector<int>>grid;
	grid.push_back(b1);
	grid.push_back(b2);
	grid.push_back(b3);
	grid.push_back(b4);
	Solution A;
	int total=A.minPathSum(grid);
	cout<<total<<endl;
}
*/