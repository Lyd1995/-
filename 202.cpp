#include <iostream>
void encryption(int num);
void decode(void);
int num_en[4];
int num_de[4];
int main(int argc, char** argv) {
	int trans_num;
	while(1)
	{
		printf("请输出需要解密的数据：\n");
		scanf("%d",&trans_num);
		encryption(trans_num);
		printf("加密后：%d%d%d%d\n",num_en[3],num_en[2],num_en[1],num_en[0]);
		decode();
		printf("解密后：%d%d%d%d\n\n",num_de[3],num_de[2],num_de[1],num_de[0]);
	}
	return 0;
}
void encryption(int num)
{
	int i;
	int s;
	for(i=0;i<4;i++)
	{
		num_en[i]=((num%10)+7)%10;
		num/=10;
	}
	s=num_en[0];
	num_en[0]=num_en[2];
	num_en[2]=s;
	s=num_en[1];
	num_en[1]=num_en[3];
	num_en[3]=s;
}
void decode()
{
	int i,s;
	
	s=num_en[0];
	num_en[0]=num_en[2];
	num_en[2]=s;
	s=num_en[1];
	num_en[1]=num_en[3];
	num_en[3]=s;
	for(i=0;i<4;i++)
	{
		if(num_en[i]<=6)
		{
			num_de[i]=num_en[i]+3;
		}
		else
		{
			num_de[i]=num_en[i]-7;
		}
	}
}

