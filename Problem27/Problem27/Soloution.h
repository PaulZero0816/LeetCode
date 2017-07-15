#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		std::vector<int>::iterator itor1;
		for(itor1=nums.begin();itor1!=nums.end();)
		{
			
			if(*itor1==val)
			{
				itor1=nums.erase(itor1);
			}
			else
			itor1++;
		}
		return nums.size();
    }
};