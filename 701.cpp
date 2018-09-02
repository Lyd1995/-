#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

typedef struct BTree
{
	int weight;
	char c;
	struct BTree *lchild,*rchild;
}BTree;

typedef struct findmin
{
	int wei,num;
}findmin;

	string translate[27];
    char str[1000];

void Createchart(BTree *root,char b[],int n,string code);
void printfchar(void);
BTree* Createhfmtree(int a[],char b[],int n);

int main(int argc, char** argv)
{	
	int i,n;
	int a[27];
	char b[27];
	string code="";

	BTree *root;
	
	printf("此处正常\n");
	
	printf("请输入需要编码的字符个数：");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个需要编码的字符和该字符的出现频率：",i+1) ;
	//	getchar();
		cin>>b[i];
		cin>>a[i] ;
//		getchar();
	//	scanf("%d",&a[i]);
	//	getchar();
	}
	
	root=Createhfmtree(a,b,n);
	
	printf("请输入需要译码的字符串：");
	cin>>str;
	Createchart(root,b,n,code);
	printfchar();

	return 0;
}

BTree* Createhfmtree(int a[],char b[],int n)
{
	BTree **p,*q;
	int i,j,k;
	findmin mi[2];//最小值与次小值的下角标
	
	p=(BTree**)malloc((n+5)*sizeof(BTree));//建立一个数组
	
//	printf("建立指针数组处正常\n");
//	p[3]->c=b[2];
//	p[3]->weight=a[2];
	
	 for(i=0;i<n;i++)    //输入权重和字符 
	 {
	 	p[i]=(BTree*)malloc(sizeof(BTree));
	 //	cout<<b[i]<<"  "<<a[i]<<"  "<<i<<endl;
	 	p[i]->c=b[i];
	// 	cout<<"b正常"<<endl; 
	 	p[i]->weight=a[i];
	 //	cout<<"a正常"<<endl; 
	 	p[i]->lchild=p[i]->rchild=NULL; 
	 //	cout<<"child正常"<<endl; 
	 //	printf("%c  %d\n",p[i]->c,p[i]->weight) ;
	 }
	 printf("\n");
//	 printf("权重处正常   n=%d\n",n);
//	i=0;
//	printf("i=%d\n",i);
	for(i=0;i<n-1;i++)  ///对n个数进行排序合并，直至出现根节点：
	{
	 //	printf("dsf\n");
	 	mi[0].num=-1;
		mi[1].num=-1;
		 
	//	 printf("正常进入外循环   i=%d\n",i);
		//同时找出最小值与次小值
		for(j=0;j<n;j++)
		{
			if(p[j]==NULL)
			{
				continue;
			}
	//		printf("正常进入内循环\n");
			if(mi[0].num<0)///最小值 
			{
				mi[0].num=j;
				mi[0].wei=p[j]->weight;
				continue;
			}
			printf("最小字符：%c  频率：%d\n",p[mi[0].num]->c,p[mi[0].num]->weight);
			
			if(mi[1].num<0)///次最小值 
			{
				mi[1].num=j;
				mi[1].wei=p[j]->weight;
			}
			printf("次最小字符：%c  频率：%d\n",p[mi[1].num]->c,p[mi[1].num]->weight);
			
//			printf("mi[0].wei=%d     p[%d]->weight=%d\n",mi[0].wei,j,p[j]->weight);

			if(mi[0].wei>p[j]->weight)//当前找到的最小值是否为最小 
			{
				mi[1].num=mi[0].num;
				mi[1].wei=mi[0].wei;
			//	printf("T\n");
				mi[0].num=j;
				mi[0].wei=p[j]->weight;
			//	printf("T\n");
			}
			else
			{
				if(mi[1].wei>p[j]->weight)//当前找到的次最小值是否为次最小 
				{
					mi[1].num=j;
					mi[1].wei=p[j]->weight; 
				//	printf("T\n");
				}	
			}
		//	printf("\n");
		//	printf("最小字符：%c  频率：%d\n",p[mi[0].num]->c,p[mi[0].num]->weight);
		//	printf("次最小字符：%c  频率：%d\n",p[mi[1].num]->c,p[mi[1].num]->weight);
			
		}  
		
		printf("第%d次合并，最小的字符和频率为：%c  %d     次小的字符和频率为：%c  %d\n",i+1,p[mi[0].num]->c,p[mi[0].num]->weight,p[mi[1].num]->c,p[mi[1].num]->weight);
		//找到最小与次小，合并
		q=(BTree*)malloc(sizeof(BTree));
		q->weight=p[mi[0].num]->weight+p[mi[1].num]->weight;
		q->lchild=p[mi[0].num];
		q->rchild=p[mi[1].num];
		
		p[mi[0].num]=q;
		p[mi[1].num]=NULL;
		printf("\n");
 
	} 
//	free(p);
	return q; 	 
}
//先序遍历哈夫曼树，与之比对 
void Createchart(BTree *root,char b[],int n,string code)
{
	if(root->lchild==NULL && root->rchild==NULL)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(root->c==' ')
			{
				translate[26]=code;
				printf("空格有效\n");
				continue; 
			}
			if(b[i]==root->c)
			{
				translate[b[i]-'A']=code;
			}
		}
	}
	else
	{
		if(root->lchild!=NULL)
		{
			Createchart(root->lchild,b,n,code+"0");
		}
		if(root->rchild!=NULL)
		{
			Createchart(root->rchild,b,n,code+"1");
		}
	}
	return;
}

void printfchar(void)
{
	int i,len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			cout<<translate[26]<<" ";
			continue;
		}
		cout<<translate[str[i]-'A']<<" ";
	}
}
