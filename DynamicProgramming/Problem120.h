/*
Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step
you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/

#include <iostream>
#include <vector>
using namespace std;
#define min(a,b) (a>b?b:a);

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		int length=triangle.size();
		if(length==0)
			return 0;
		else if(length==1)
			return triangle[0][0];
		else
		{
			int med=triangle[0][0];
			vector<int>sum;
			sum.resize(length);
			sum[0]=med;
			for(int i=1;i<triangle.size();i++)
			{
				med=triangle[i][0]+sum[0];
				for(int j=1;j<triangle[i].size()-1;j++)
				{
					int a=min(sum[j-1],sum[j]);
					a=a+triangle[i][j];
					sum[j-1]=med;
					med=a;
				}
				sum[triangle[i].size()-1]=sum[triangle[i].size()-2]+triangle[i][triangle[i].size()-1];
				sum[triangle[i].size()-2]=med;
			}
			int minsum=sum[0];
			for(int i=1;i<length;i++)
			{
				minsum=min(minsum,sum[i]);
			}
			return minsum;
		}
    }
};

/*
//Test Code

#include "Problem120.h"

int main()
{
	int a1[1]={2};
	int a2[2]={3,4};
	int a3[3]={6,5,7};
	int a4[4]={4,1,8,3};
	// int a5[5]={};
	vector<int>b1(a1,a1+1);
	vector<int>b2(a2,a2+2);
	vector<int>b3(a3,a3+3);
	vector<int>b4(a4,a4+4);
	vector<vector<int>>triangle;
	triangle.push_back(b1);
	triangle.push_back(b2);
	triangle.push_back(b3);
	triangle.push_back(b4);
	Solution A;
	int total=A.minimumTotal(triangle);
	cout<<total<<endl;
}
*/