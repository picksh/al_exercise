#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 1000000
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;

int num[MAXNUM];

struct node{
	node* ch[2];//0->left,1->right
	node* father;
	int size;
	int fix;
	int data;
};

void newnode(node* pre,int number)
{
	node* newone=new node;
	newone->ch[0]=NULL;
	newone->ch[1]=NULL;
	newone->fix=rand();
	newone->father=pre;
	newone->size=1;//以它为根的总节点数 
	if(number>pre->data) pre->ch[1]=newone;
	if(number<pre->data) pre->ch[0]=newone;
	return;
}

void pushup(node* nd)
{
	nd->size=nd->ch[0]->size+nd->ch[1]->size+1;//为什么要+1? 
} 

void rotate(tree* x,bool d)
{ //d指旋转的方向，0为左旋，1为右旋
    tree *y=x->ch[!d];
    x->ch[!d]=y->ch[d];
    y->ch[d]=x;
    pushup(x);
    pushup(y);
    x=y;
}

void insert(node* nd,int val)
{
	if(nd==NULL) 
	{
		node*newnd=new node;
		newnd->data=val;
	}
   // if(nd->data==val)return;
	else{
		bool d=val>nd->data;//这种写法。。 
		insert(nd->ch[d],val);//查找无重,有重咋办？###这里要改一下 
		nd->size++;
		if(nd->fix<nd->ch[d]->fix)rotate(nd,!d);
		}
}

int find(int val,node* nd)
{
	if(nd==NULL)return NULL;
	if(nd->data==val)return nd;
	bool d=val>nd->data;
	return find(val,nd->ch[d]);
}

void delete_(int val,node* nd)
{
	bool d=val>nd->data;
	rotate(nd,d);
	else{
		//这种写法。。 
		delete_(nd->ch[d],val);//无重,有重咋办？
		
		if(nd->fix<nd->ch[d]->fix)rotate(nd,!d);
		}	
}






int main()
{
	
}
