#include <iostream>

int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int b[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int isleapyear(int y);
int sum_mon(int m,int isleap);
int istrue_input(int y,int m,int d); 

int main(int argc, char** argv) {
	int y,m,d;
	printf("请输入年月日：") ;
	scanf("%d %d %d",&y,&m,&d);
	if(istrue_input(y,m,d))
	{
		int sum;
		if(isleapyear(y))
		{
			sum=sum_mon(m,1);
			sum+=d;
		}
		else
		{
			sum=sum_mon(m,0);
			sum+=d;
		}
		printf("%d\n",sum);
    }
    else
    {
    	printf("输入错误！！");
	}
	return 0;
}

int isleapyear(int y)
{
	if(y%100==0)
	{
		if(y%400==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(y%4==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int sum_mon(int m,int isleap)
{
	int i,sum=0;
	if(isleap)
	{
		for(i=0;i<m-1;i++)
		{
			sum+=a[i];
		}
	}
	else
	{
		for(i=0;i<m-1;i++)
		{
			sum+=b[i];
		}
	}
	return sum;
}

int istrue_input(int y,int m,int d)
{
	if(m>12)
	{
		return 0;
	}
	if(d>31)
	{
		return 0;
	}
	if(m==4 || m==6 || m==9 || m==11)
	{
		if(d>30)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if(m==2)
		{
			if(isleapyear(y))
			{
				if(d>29)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else
			{
				if(d>28)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
		else
		{
			return 1;
		}
	}
}
