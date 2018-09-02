#include <iostream>

int factor[1000];//因子 

int findfactor(int num); //返回因子个数 
int adds(int len);//相加 

int main(int argc, char** argv) {
	
	int num=3,sum,len,i;
	int n=1000;
	while(n--)
	{
		len=findfactor(num);
		sum=adds(len);
		if(sum==num)
		{
			printf("%d  ",num);
		}
		num++;
	}
	
	return 0;
}

int findfactor(int num)
{
	int i=1,j=0;
	
	while(i<num)
	{
		if(num%i==0)
		{
			factor[j++]=i;
		}
		i++;
	}
	return j;
}

int adds(int len)
{
	int i,sum=0;
	for(i=0;i<len;i++)
	{
		sum+=factor[i];
	}
	return sum;
}
