#include <iostream>
#include<stdlib.h>

#define maxsize 12

typedef struct ArcNode// 边节点 
{
	int adjv;  //该边所指向的顶点
	struct ArcNode *nextarc;  //下一条边的位置（如果存在则指出，不存在则为空） 
}ArcNode; 

typedef struct VNode// 顶点 
{
	int in;   //记录入度 
	char num[5];    //记录编号 
	ArcNode *first;//第一条边 
} VNode;

typedef struct//  图
{
	VNode adjlist[maxsize];
	int n,e;//12  14
}AGraph;

void creategraph(AGraph *g);
void topsort(AGraph *g);

int main(int argc, char** argv) {
	
	AGraph g;
	creategraph(&g);
	topsort(&g);
	
	return 0;
}

void creategraph(AGraph *g)
{
	int i,j,k;
	ArcNode *edge;
	printf("请输入顶点数与边数： ");
	scanf("%d %d",&g->n,&g->e); 
	
	for(i=0;i<g->n;i++)
	{
		printf("请输入第%d个顶点的编号与入度：",i+1);
		scanf("%s",&g->adjlist[i].num);
		getchar();
		scanf("%d",&g->adjlist[i].in);
		g->adjlist[i].first=NULL;	 
	}
	
	for(k=0;k<g->e;k++)
	{
		printf("请输入第%d条有向边（vi,vj）上的顶点序号：\n",k+1);
		printf("i=");
		scanf("%d",&i);
		i--; 
		printf("j=");
		scanf("%d",&j);
		j--;
		edge=(ArcNode *)malloc(sizeof(ArcNode));
		edge->adjv=j;
		edge->nextarc=g->adjlist[i].first;
		g->adjlist[i].first=edge;

	}
}

void topsort(AGraph *g)
{
	int top1=0,top2=0,i,j=1,k,top_num1,top_num2,count=g->n;
	ArcNode *edge;
	int *stack1,*stack2;        ///建立2个栈，里面存放度为0的顶点       1:存入前一层的顶点   2：存入下一层的顶点 
	stack1=(int *)malloc(g->n*sizeof(int));
	stack2=(int *)malloc(g->n*sizeof(int));
	
	
	for(i=0;i<g->n;i++)  ///寻找图中入度为0的顶点 
	{
		if(g->adjlist[i].in==0)
		{
			stack1[++top1]=i;
		} 
	}
	
	while(count!=0)  ////每次循环，先输出stack1，再输出stack2     当所有顶点都输出了，循环结束 
	{
		printf("\n");
     	printf("优先级为%d的课程编号：\n",j++);
		while(top1!=0)
		{

			top_num1=stack1[top1--];

			printf("%s  ",g->adjlist[top_num1].num);
			count--;

			edge=g->adjlist[top_num1].first;
			
	    	for(edge=g->adjlist[top_num1].first;edge!=NULL;edge=edge->nextarc)
	    	{
	    		k=edge->adjv;
		    	g->adjlist[k].in--;  //对应的入度减一 
		    	if(g->adjlist[k].in==0)//若减完后，入度为0；入栈 
		    	{
			    	stack2[++top2]=k;
		      	}
    		}
		}
		
		if(count==0) 
		{
			break;
		}
		
		printf("\n");

	  	printf("优先级为%d的课程编号：\n",j++);
		while(top2!=0)
		{
			top_num2=stack2[top2--];
			printf("%s  ",g->adjlist[top_num2].num);
			count--;
			
	    	for(edge=g->adjlist[top_num2].first;edge!=NULL;edge=edge->nextarc)
	    	{
	    		k=edge->adjv;

		    	g->adjlist[k].in--;  //对应的入度减一 
		    	if(g->adjlist[k].in==0)//若减完后，入度为0；入栈 
		    	{
			    	stack1[++top1]=k;
		      	}
    		}
		}
	} 
		
}
