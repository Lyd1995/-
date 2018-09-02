#include <iostream>

int findnum(int n,int min);//        n的因式分解个数 
int isprime(int a);

int main(int argc, char** argv) {
	
	int n,num;
	while(1) 
	{
		printf("请输入n：\n");
		scanf("%d",&n); 
		num=findnum(n,2);
		printf("有%d种分解方法\n\n",num);
	}
	return 0;
}

int findnum(int n,int min) 
{

	if(n==1 || n<min)
	{
		return 0;
	}
	if(isprime(n))
	{
		return 1;
	}
	int i=min,count=0;
	while(i<=n/2)
	{
		if(n%i==0)/// i is n's factor
		{
			int c=n/i;
			count+=findnum(c,i);
		}
		i++;
	}
	return count+1;
}

int isprime(int a)
{
	for(int i=2;i<=a/2;i++)
	{
		if(a%i==0)
		{
			return 0;
		}
	}
	return 1;
}
