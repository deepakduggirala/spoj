#include<stdio.h>
#include<math.h>

#define parent(i) i/2

using namespace std;

float wealthRoot;

float wealth(int i)
{
	if(i==1) return wealthRoot;
	if(parent(i)%2 !=0 && i%2 != 0)	//female parent and female child
		return wealth(parent(i))/4;
	else
		return wealth(parent(i))/2;
}

float wealth_root(int x,float W)
{
	int i = x;
	float wealth = W;
	while(i!=1)
	{
		if(parent(i)%2 !=0 && i%2 != 0)	//female parent and female child
			wealth = wealth*4;
		else
			wealth = wealth*2;
		i=i/2;
	}
	return wealth;
}

int main()
{
	static int numTests;
	int x,y;
	float W;	
	scanf("%d",&numTests);
	for(int i=0;i<numTests;i++)
	{
		scanf("%d%d%f",&x,&y,&W);
		wealthRoot = wealth_root(x,W);
		printf("%.6lf\n",round(1000000*wealth(y))/1000000.0);
	}
}
