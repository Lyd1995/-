#include<iostream>
#include<string.h>
char str[10005];
char d[]="debug";

int finddebug(void);


int main(int argc, char** argv)
{
	while(1)
	{
		gets(str);
		int num=finddebug();
		if(num)
		{
			printf("包含\n");
		}
		else
		{
			printf("不包含\n");
		}
	}
	return 0;
	
}

int finddebug()
{
	int len=strlen(str);
	int i=0,j,flag;
	while(len)
	{
		if(str[i]==d[0])
		{
			for(j=i+1;j<i+5;j++)
			{
				if(str[j]!=str[j-i])
				{
					flag=0;
					break;
				}
				flag=1;
			}
			if(flag)
			{
				return 1;
			}
			else
			{
				i++;
				len--;
			}
		}
		else
		{
			i++;
			len--;
		}
	}
	return 0;
}
