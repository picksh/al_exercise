/*
左偏树 zoj-2334
insert,top,pop,merge操作都要求以左偏树堆顶的编号代表着一棵左偏树 
*/ 

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
#define MAXN 500007
#define MAXM 10007
#define pi 3.1415926

using namespace std;
int dis[MAXN];
int v[MAXN];
int r[MAXN],l[MAXN];
int fa[MAXN];
int tot;

int findad(int x)
{
    return fa[x]==x?x:findad(fa[x]);	
}

int init(int x)
{
	tot++;
	v[tot]=x;
	l[tot]=r[tot]=dis[tot]=0;
	fa[tot]=tot;
}

int merge(int a,int b)
{
	if(!a) return b;
	if(!b) return a;
	//if(v[a]>v[b]) swap(a,b);
	if(v[a]<v[b]) swap(a,b);
	r[a]=merge(r[a],b);
	fa[r[a]]=a;
	if(dis[l[a]]<dis[r[a]]) 
	swap(l[a],r[a]);
	dis[a]=dis[r[a]]+1;
	return a;
}

int solve(int x,int y)
{
	int a1=findad(x);
	int b1=findad(y);
	if(a1==b1) return -1;
	
	v[x]/=2;
	int temp=merge(l[x],r[x]);
	l[x]=r[x]=dis[x]=0;
	int xroot=merge(temp,x);
	
	v[y]/=2;
	temp=merge(l[y],r[y]);
	l[y]=r[y]=dis[y]=0;
	int yroot=merge(temp,y);
	int root=merge(xroot,yroot);
	return v[root];
}



int main()
{
	int n,m,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		int x;
		tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			init(x);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b); 
			printf("%d\n",solve(a,b));
		}
		memset(dis,0,sizeof(dis));
		memset(r,0,sizeof(r));
		memset(l,0,sizeof(l));
		memset(v,0,sizeof(v)); 
	}
    return 0;
}
