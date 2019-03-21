/*
左偏树 
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
#define MAXN 107
#define MAXM 10007
#define pi 3.1415926

using namespace std;
int dis[MAXN];
int v[MAXN];
int r[MAXN],l[MAXN];
int tot;

int merge(int x,int y)
{
	if(!x) return y;
	if(!y) return x;
	if(v[x]<v[y]) swap(x,y);
	r[x]=merge(r[x],y);
	if(dis[l[x]]<dis[r[x]]) swap(l[x],r[x]);
	dis[x]=dis[r[x]]+1;
	return x; 
}

int init(int x)
{
	tot++;
	v[tot]=x;
	l[tot]=r[tot]=d[tot]=0;
	return tot;
}

int insert(int x,int y)
{
	return merge(x,init(y));
}

int top(int x)
{
	return v[x];
 } 
 
int pop(int x)
{
	return merge(r[x],l[x]);
}

int main()
{
	
    return 0;
}
