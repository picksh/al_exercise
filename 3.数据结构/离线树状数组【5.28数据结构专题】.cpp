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
#define MAXN 100007
#define eps 0.00000001
#define lu unsigned long long
#define ll long long
#define mode 1000003
#define INF 0x7fffffff//1000000008

using namespace std;


struct node{
	int h;
	int id;
	bool operator<(const node a) {
	return h<a.h;}
}num[MAXN];

struct qu{
	int l,r,h;
	int id;
	bool operator<(const qu a) {
	return h<a.h;}
}q[MAXN];

int t,n,m;
int tree[MAXN];
int ans[MAXN];

int lowbit(int x)
{
	return x&(-x);
}

void update(int x)
{
	while(x<=n){
		tree[x]++;
		x+=lowbit(x);
	} 
}

int query(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=tree[x];
		x-=lowbit(x); 
	}
	return ans;
}


int main()
{
	scanf("%d",&t);
	int tot=0;
	while(t--){
		memset(num,0,sizeof(num));
		memset(q,0,sizeof(q));
		memset(ans,0,sizeof(ans));
		memset(tree,0,sizeof(tree));
		tot++;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i].h);
			num[i].id=i;
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].h);
			q[i].id=i;
		}
		sort(num+1,num+n+1);
		sort(q+1,q+m+1);
//		for(int i=1;i<m;i++){
//			cout<<"q["<<i<<"]="<<q[i].id<<" q.h="<<q[i].h<<"\n";
//		}
		int k=1;
		for(int i=1;i<=m;i++){
			while(k<=n&&num[k].h<=q[i].h){
				update(num[k].id);
				k++;
			}
			ans[q[i].id]=query(q[i].r+1)-query(q[i].l);
		}
		printf("Case %d:\n",tot);
		for(int i=1;i<=m;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}

