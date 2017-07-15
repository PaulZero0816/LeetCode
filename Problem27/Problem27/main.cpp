#include "Soloution.h"

int main()
{
	int a[9]={2,3,1,2,3,1,2,3,3};
	std::vector<int> a1(a,a+9);
	Solution A;
	int b=A.removeElement(a1,3);
	std::cout<<b<<std::endl;
}