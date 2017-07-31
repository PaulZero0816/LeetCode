/*
Frog Jump

A frog is crossing a river. The river is divided into x units 
and at each unit there may or may not exist a stone. The frog 
can jump on a stone, but it must not jump into the water.
Given a list of stones' positions (in units) in sorted ascending
order, determine if the frog is able to cross the river by 
landing on the last stone. Initially, the frog is on the first 
stone and assume the first jump must be 1 unit.
If the frog's last jump was k units, then its next jump must be 
either k - 1, k, or k + 1 units. Note that the frog can only jump 
in the forward direction.

Note:
The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
	unordered_map <int,bool>h;
	// TLE
    bool canCross(vector<int>& stones,int pos=0,int k=0) {
		
        for(int i=pos+1;i<stones.size();i++)
		{
			int med=stones[i]-stones[pos];
			if(med<k-1)
				continue;
			if(med>k+1)
				return false;
			if(canCross(stones,i,med))
				return true;
		}
		if(pos==stones.size()-1)
			return true;
		else
			return false;
    } 
	// use unordered_map to solve TLE
	bool canCross2(vector<int>& stones,int pos=0,int k=0)
	{
		int key=pos|k<<11;
		 // 因为k<=1100<2048，这么做是为了把k和pos
		// 用一个int类型的key存在unordered map中
		if(h.count(key)!=0)  //算过了的就不用再算
			return h[key];
		for(int i=pos+1;i<stones.size();i++)
		{
			int med=stones[i]-stones[pos];
			if(med<k-1)
				continue;
			if(med>k+1)
			{
				h[key]=false;
				return false;
			}
			if(canCross2(stones,i,med))
			{
				h[key]=true;
				return true;
			}
		}
		if(pos==stones.size()-1)
		{
			h[key]=true;
			return true;
		}
		else
		{
			h[key]=false;
			return false;
		}
	}
};

/*
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
*/