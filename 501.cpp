#include <iostream>

int prime[1000];

int findprime(int n);/// return length
void findprimedouble(int len); // find sushudui from prime and print

int main(int argc, char** argv) {
	
	int n,len;
	while(1)
	{
		printf("请输入范围n：\n");
		scanf("%d",&n);
		len=findprime(n);
		findprimedouble(len);
	} 
	return 0;
}

int findprime(int n)
{
	if(n==1)
	{
		return 0;
	}
    if(n<=0)
    {
	   	return -1;
    } 
    prime[0]=2;
    int k=2,j=1;
    while(k<=n)
    {
    	int i,flag=1;
    	for(i=2;i<=k/2;i++)
		{
			if(k%i==0)
			{
				flag=0;
				break;
			}
		} 
		if(flag)
		{
			prime[j++]=k;
		}
    	k++;
	}
	return j;
}

void findprimedouble(int len)
{
	if(len==0)
	{
		printf("没有素数对！\n\n\n");
	}
	if(len==-1)
	{
		printf("输入不合法！\n\n\n"); 
	}
	
	int i,j,flag=1;
	for(i=0,j=1;j<len;i++,j++)
	{
		if((prime[j]-prime[i])==2)
		{
			printf("素数对：%d  %d\n",prime[i],prime[j]);
			flag=0;
		}
		
	}
	if(flag)
	{
		printf("没有素数对！\n\n\n"); 
	}
}

