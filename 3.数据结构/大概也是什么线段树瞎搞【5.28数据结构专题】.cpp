#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
#include<ctime>
#define MAXN 15007
#define eps 0.00000001
#define lu unsigned long long
#define ll long long
#define mode 1000003
#define INF 0x7fffffff//1000000008

using namespace std;

struct star{
	int x,y,l;
}s[MAXN];

int n,w,h;
int tree[MAXN];

void pushup(int x)
{
	tree[x]=tree[x*2]+tree[x*2+1];
}

void buildtree(int node,int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	buildtree(node*2,l,mid);
	buildtree(node*2+1,mid+1,r);
	pushup(node);
}

void update(int node,int l,int r,iint begin,int end,int value)
{
	if(l==r) tree[node]++;
	if(l<)
}

int main()
{
	scanf("%d%d%d",&n,&w,&h);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].l);
	}
	buildtree(1,1,n);
	return 0;
}
