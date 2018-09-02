
#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define N 12
#define P 11

typedef struct node
{
	int key;
	node *next;
} node;

node h1[N];
int h2[N];
int key[N]={19,14,23,1,68,20,84,27,56,11,10,79};//

void hash_link(int key);
int hash_linear(int key);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int i;
	for(i=0;i<N;i++)
	{
		h1[i].key=0;
		h1[i].next=NULL;
	}
	memset(h2,0,sizeof(h2)); 
	for(i=0;i<N;i++)
	{
		hash_link(key[i]);
		h2[hash_linear(key[i])]=key[i];
	}
	cout<<"链地址法所得的哈希散列表：\n";
	for(i=0;i<N;i++)
	{
		if(h1[i].key==0)
		{
			continue;
		}
		else
		{
			cout<<"关键字："<<h1[i].key<<"    在哈希表中的位置："<<i<<"\n";
			node *q=h1[i].next;
	    	while(q!=NULL)
	    	{
	     		cout<<"关键字："<<q->key<<"    在哈希表中的位置："<<i<<"\n";
	     		q=q->next;
	    	}
		}
	}
	cout<<"\n\n"<<"线性探测再散列法所得的哈希散列表：\n";
	for(i=0;i<N;i++)
	{
		if(h2[i]!=0)
		{
			cout<<"关键字："<<h2[i]<<"    在哈希表中的位置："<<i<<"\n";
		}	
	}
	return 0;
}

void hash_link(int key)
{
	int k=key%P ;
	if(h1[k].key==0)//初始值设置为0 
	{
		h1[k].key=key; 
	}
	else//产生冲突，采用链表 
	{
		node *q=&h1[k];
		while(q->next!=NULL)
		{
			q=q->next;
		}
		node *p=p=(node*)malloc(sizeof(node));
		p->key=key;
		p->next=NULL;
		q->next=p;	
	}
}

int hash_linear(int key)
{
	int k=key%P;
	if(h2[k]==0)//初始值设置为0 
	{
		return k; 
	}
	else//产生冲突，采用链表 
	{
		int i=key+1,j;
		while(1)
		{
			j=i%N;
			if(h2[j]==0)
			{
				return j;
			}
			i++;
		}
	}
}
