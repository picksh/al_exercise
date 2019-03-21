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
double q,p,r,s,t,u;
int num[MAXNUM];

struct node{
	node* left;
	node* right;
	int data;
};

void build(int number,node* p)
{
	p->data=number;
	node* q=new node;
	if(number>p->data){
		p->right=q;
			build(number,)
    }
}

int find(int key,node* bt)
{
	if(bt==NULL)return NULL;
	if(bt->data>key)find(key,bt->left);
	if(bt->data<key)find(key,bt->right);
	else return bt;
}








int main()
{
	
}
