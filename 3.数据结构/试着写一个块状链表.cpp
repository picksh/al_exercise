/*在o(根号n)的时间内完成对
一个有序表的
插入、删除、查询等操作 */ 

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#define INF 100000000
#define MAXN 100007
#define eps 1e-8
#define pi 3.1415926
#define e 2.71828182
 
using namespace std;
const int mm=sqrt[N];//保证mm为sqrt(N)级别的一个数 

struct data{
	int s;
	int a[MM];
	data* nex;
};

data *root=NULL;

void insert(int x,int posi)
{
	if(root==NULL){
		root=new data;
		root->s=1;
		root->a[1]=x;
		return;
	}
	data* k=root;
	while(k->s>posi&&k->nex!=NULL){
		posi-=k->s;
		k=k->nex;
	}
	memmove(k->a+posi+1,k->a+posi,sizeof(int)*(k->s-posi+1));
	k->s++;
	k->a[posi]=x;
	if(k->s==2*mm){
		data* t=new data;
		t->nex=k->nex;
		k->nex=t;
		memcpy(t->a+1,k->a+mm+1;sizeof(int)*mm);
		t->s=k->s=mm
	}
	return;
}

void del(int posi)
{
	data* k=root;
	while(k->s>posi&&k->nex!=NULL){
		posi-=k->s;
		k=k->nex;
	}
	memmove(k->a+posi,k->a+posi+1,sizeof(int)*(k->s-posi));
	k->s--;
}

int find(int posi)
{
	data* k=root;
	while(k->s>posi&&k->nex!=NULL){
		posi-=k->s;
		k=k->nex;
	}
	return k->a[posi];
}

void destroy(data* k)
{
	if(k->nex!=NULL){
		destroy(k->nex);
	}
	delete(k);
}
int main()
{
	
	destroy(root);
	return 0;
} 
