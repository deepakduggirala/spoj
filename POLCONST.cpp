/*
	Author:Deepak Duggirala
	Date:14-08-2015
	Description: POLCONST - http://www.spoj.com/problems/POLCONST/
*/
#include<stdio.h>
#include<math.h>
using namespace std;

int isPowerOfTwo (unsigned int x)
{
	while (((x & 1) == 0) && x > 1) /* While x is even and > 1 */
		x >>= 1;
	return (x == 1);
}

int main()
{
	static int numTests;
	int n;
	int fermat[5] = {3,5,17,257,65537};
	scanf("%d",&numTests);
	for(int i=0;i<numTests;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<5;j++)
		{
			if(n%fermat[j]==0)
				n=n/fermat[j];
		}
		if(isPowerOfTwo(n))
			printf("Yes\n");
		else
			printf("No\n");
	}
}
