//二叉排序树 
//////////////////////////////////////二叉排序树*************************************** 
#include <iostream>
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#define N 8
using namespace std;

typedef struct BTNode
{
	int key;
	struct BTNode *lchild,*rchild;
 } BTNode;

void CreateBST(BTNode *&root,int in[],int n);
void BSTinsert(BTNode *&root,int a);
void printBST(BTNode *root);
void deletenode(BTNode *&root,int a) ;
BTNode* BSTfind(BTNode *root,int k);
int left_tree_right(BTNode *&root);
/// 主函数******************************************************************** 
int main(int argc, char** argv) {
	int in_key[]={33,88,22,55,90,11,66,99};
	int i,j,k;
	BTNode *root;
	
	root=NULL;

	//创建排序二叉树 *************************************
	CreateBST(root,in_key,N);
	cout<<"输出排序结果：\n";
	printBST(root);
	
	//查找 ****************************************
	printf("请输入需要查找的数据：\n");
	k=78;
	cout<<k<<"\n";

	BTNode *p=BSTfind(root,k);
	if(p==NULL)
	{
		printf("所查找的数据%d不在二叉树中\n",k); 
	}
	else
	{
		printf("所查找的数据%d在二叉树中\n",k);
	}
	
	//删除******************************************** 
	printf("请输入需要删除的数据：\n");	
	k=90;
	cout<<k<<"\n";
 
	p=BSTfind(root,k) ;
	if(p==NULL)
	{
		cout<<"需要删除的数据不在排序二叉树中！！！\n";
	}
	else
	{
		printf("删除数据后，二叉树的排序结果：\n");	
		deletenode(root,k) ;
    	printBST(root);
	}
 	return 0;
}
///////////////////////////////////////////////创建排序二叉树******************************************** 
void CreateBST(BTNode *&root,int in[],int n)
{
//	cout<<"开始创建排序二叉树\n";
	int i;
	BTNode *p=NULL;
	for(i=0;i<n;i++)
	{
		BSTinsert(root,in[i]);
	}
}
///////////////////////////////////////////////插入算法********************************************
void BSTinsert(BTNode *&root,int a)
{
	if(root==NULL)
	{
		root=(BTNode*)malloc(sizeof(BTNode));
		root->key=a;
		root->lchild=root->rchild=NULL;
	}
	else
	{
		if(a<=root->key)
		{
			BSTinsert(root->lchild,a);
		}
		else
		{
			BSTinsert(root->rchild,a);
		}
	}
}
///////////////////////////////////////////////中序遍历打印排序二叉树********************************************
void printBST(BTNode *root)
{
	if(root==NULL)
	{
		return;
	}
	printBST(root->lchild);
	printf("%d\n",root->key);
	printBST(root->rchild);
}
///////////////////////////////////////////////排序二叉树的查找算法********************************************
BTNode* BSTfind(BTNode *root,int k)  //失败返回NULL，成功返回该节点 
{
	if(root==NULL)
	{
		return NULL;
	} 
	else
	{
		if(k==root->key)
		{
			return root;
		}
		else
		{
			if(k<root->key)
			{
				BSTfind(root->lchild,k);
			}
			else
			{
				BSTfind(root->rchild,k);
			}
		}
	}
}
///////////////////////////////////////////////排序二叉树的删除算法********************************************
void deletenode(BTNode *&root,int a)
{
	if(root->key==a)
	{
		if(root->lchild==NULL && root->rchild==NULL)
		{
			free(root);
			root=NULL; 
			return;
		}
		else
		{//  删除节点仅有一个孩子时************************** 
			if(root->lchild!=NULL && root->rchild==NULL)
			{
				BTNode *p=root->lchild;
				
				root->key=root->lchild->key;
				root->rchild=root->lchild->rchild;
				root->lchild=root->lchild->lchild;
				
				free(p);

				return;
			}
			if(root->lchild==NULL && root->rchild!=NULL)
			{
				BTNode *p=root->rchild;
				
				root->key=root->rchild->key;
				root->lchild=root->rchild->lchild;
				root->rchild=root->rchild->rchild;
				
				free(p);
			
				return;
			}
			//删除节点有两个孩子*************************************** 

			int k=left_tree_right(root->lchild);
			root->key=k;
			return;
		}
	}
	else
	{
		if(root->key<a)
		{
			deletenode(root->rchild,a);
		}
		else
		{
			deletenode(root->lchild,a);
		}		
	}
}
//////////////删除节点的左子树的最右节点 
int left_tree_right(BTNode *&root)
{
	if(root->rchild==NULL)
	{
		int k=root->key;
		if(root->lchild==NULL)
		{
			root=NULL;
		}
		else
		{
			BTNode *p=root->lchild;
			
			root->key=root->lchild->key;
			root->rchild=root->lchild->rchild;
			root->lchild=root->lchild->lchild;
			
			free(p);
		}
		return k;
	}
	else
	{
		left_tree_right(root->rchild);
	}
}

