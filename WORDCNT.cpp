#include<stdio.h>
#include<iostream>

#define MAXLEN 20010
using namespace std;
int main()
{
	int c,count,max,prev,justStarted,wordLen,i;
	static int numTests;
	
	scanf("%d",&numTests);
	fgetc(stdin);
	for(i=0;i<numTests;i++)
	{
		wordLen = 0;
		prev = 0;
		max = 1;
		justStarted = 1;
		count = 1;
		while(1)
		{
			c = fgetc(stdin);
			if(c!=' ' && c!='\n')
			{
				wordLen++;
			}
			else
			{
				//printf("%d\n",wordLen);
				if(wordLen == prev)
					count++;
				else
				{
					count = 1;
				}
				if(count > max)
					max = count;
				prev = wordLen;
				wordLen = 0;
			}
			if(c == '\n')
				break;
		}
		printf("%d\n",max);
	}
}
