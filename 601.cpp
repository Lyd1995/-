#include <iostream>

#define N 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[N+5];
int num_e[N+5];
int num_o[N+5];

int main(int argc, char** argv) {
	int i,n,j=0;
	printf("请输入%d个数：\n",N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&n);

		num[i]=n;
		for(j=i-1;j>=0;j--)
		{
			if(num[j]>n)
			{
				num[j+1]=num[j];
				if(j==0)
				{
					num[j]=n;
				}
			}
			else
			{
				num[j+1]=n;
				break;
			}
		}
	 } 
	 
	 printf("输入后排序：\n");
	 for(i=0;i<N;i++)
	 {
	 	printf("%d\n",num[i]);
	 }

	 
	 int odd=0,even=0;
	 for(i=0;i<N;i++)
	 {
	 	if(num[i]%2==0)
	 	{
	 		num_e[even++]=num[i];
		}
		 else
		{
		 	num_o[odd++]=num[i];
		}
	} 
	for(i=0;i<odd;i++)
	{
		num[i]=num_o[i];
	}
	j=0;
	for(i=odd;i<odd+even;i++)
	{
		num[i]=num_e[j++];
	}
	
	 printf("\n奇数偶数分离：\n");
	for(i=0;i<N;i++)
	 {
	 	printf("%d\n",num[i]);
	 }
	 
	return 0;
}

