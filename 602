#include <iostream>
#include<string.h>


int num[10001];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,M;
	while(1)
	{
		printf("总人数n：");
		scanf("%d",&n);
		printf("报数M：");
		scanf("%d",&M);
		
		
		int i,j=1,m=n;
		memset(num,0,sizeof(num));
		printf("顺序输出：\n");
		while(m)
		{
			for(i=1;i<=n;i++)
			{
				if(!num[i])
				{
					if(j==M)
					{
						printf("%d\n",i);
				    	m--;
				    	num[i]=1;
				    	j=1;
				    	continue;
					}
					j++;
				}
			}
		}
		printf("\n");		
	}
	return 0;
}
