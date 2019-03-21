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
#define MAXN 50007
#define eps 0.00000001
#define lu unsigned long long
#define ll long long
#define mode 1000003
#define INF 0x7fffffff//1000000008

using namespace std;

int fa[MAXN];
int rankk[MAXN];
int n,m;

void init()
{
	memset(rankk,0,sizeof(rankk));
	for(int i=1;i<=n;i++) fa[i]=i;
} 

int findad(int x)
{
	return fa[x]==x?x:findad(fa[x]);
}

void update(int x,int y)
{
	int a=findad(x);
	int b=findad(y);
	if(rankk[a]<rankk[b]){
		fa[a]=b;
	}else{
		fa[b]=a;
		if(rankk[a]==rankk[b]) rankk[a]++;
	}
}

int main()
{
	int tot=0;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
	tot++;
	init();
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b); 
		update(a,b);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
	//	cout<<"i="<<i<<" fa[]="<<fa[i]<<"\n";
		if(fa[i]==i) ans++;
	}
	printf("Case %d: %d\n",tot,ans);
	}
	return 0;
 } 
