#include <iostream>
int main(int argc, char** argv) {
	int N;
	int i,j;
	while(1)
	{
		printf("请输入查找项N：");
		scanf("%d",&N);
		i=j=1; 
		N=N-1;
		while(N)
		{
			
			if(i<=j)
			{
				if(N--)
				{
					j++;
				}

				while(j!=1&&N!=0)
				{
					N--;
					i++;
					j--;
				}
				continue;
			}
			
			if(i>=j)
			{
				if(N--)
				{
					i++;
				}
				while(i!=1&&N!=0)
				{
					N--;
					i--;
					j++;
				}
				continue;
			}

		}
		printf("%d/%d\n",i,j);
		
	}
	return 0;
}
