#include<iostream>
#include<string.h>
#define N 10

int num[N+5];

int main(int argc, char** argv)
{
	int i,j,k,temp,inter;
	
		for(i=0;i<N;i++)
    	{
			printf("请输入一个数：");
	    	scanf("%d",&num[i]);
	    	temp=num[i];
	    	
	    	for(j=i-1;j>=0;j--)
	    	{
		    	if(temp<num[j])
	    		{
			    	num[j+1]=num[j];
			    	if(j==0)
			    	{
			    		num[j]=temp;
					}
		    	}
		    	else
		    	{
		     		num[j+1]=temp;
					break;
		    	}
	    	}

    	}

    	printf("请插入一个数：");
    	scanf("%d",&inter);
    	temp=inter;
    	
    	for(j=N-1;j>=0;j--)
    	{
    		if(temp<num[j])
	    		{
			    	num[j+1]=num[j];
			    	if(j==0)
			    	{
			    		num[j]=temp;
					}
		    	}
		    	else
		    	{
		     		num[j+1]=temp;
					break;
		    	}
		}	
		
		printf("\n\n排序结果：\n");
		for(i=0;i<=N;i++)
		{
			printf("%d\n",num[i]);
		}

	return 0;
	
}
