#include<stdio.h>

#define parent(i) i/2


int color(unsigned long long int i)
{
	int c;
	if(i==1) return 0;
	if(i%2 != 0)	//right child
	{
		c = color(parent(i));
	}
	else
	{
		c = !color(parent(i));
	}
	printf("%lld\n",i);
	if(c)
		printf("blue\n");
	else
		printf("red\n");
	return c;
}
int main()
{
	unsigned long long int Y,P,i,ONE,c;
	ONE = 1;
	scanf("%lld",&Y);
	scanf("%lld",&P);
	//color: 0-Red, 1-Blue
	//(2^Y)-1+P
	i = (ONE<<Y)-1+P;
	c = color(i);
	if(c)
		printf("blue\n");
	else
		printf("red\n");
}
