#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#define INF 100000000
#define MAXNUM 310000
#define pi 3.1415926

using namespace std;

int u[MAXNUM],v[MAXNUM],value[MAXNUM],amount[MAXNUM],sum[MAXNUM]; 
vector<int> G[MAXNUM];

void update(int x,int y)
{
	value[x]+=y;
	int node;
	for(int i=0;i<G[x].size();i++){
		node=G[x][i];
		sum[node]+=y;
	}
}

int query(int x,int unit)
{
	int ans;
	int node;
	if(G[x].size()>unit) return sum[x];
	else{
		for(int i=0;i<G[x].size();i++){
			node=G[x][i];
			ans+=value[node];
		}
	}
	return ans;
}

int main()
{
	freopen("e.txt","r",stdin);
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		memset(amount,0,sizeof(amount));
		memset(value,0,sizeof(value));
		scanf("%d%d",&n,&m);
		int unit=sqrt(m+0.5);
		for(int i=0;i<n;i++) G[i].clear();
		for(int i=0;i<m;i++){
			scanf("%d%d",&u[i],&v[i]);
			amount[u[i]]++;
			amount[v[i]]++;
		}
		for(int i=0;i<m;i++){
			if(amount[u[i]]<unit) G[u[i]].push_back(v[i]);
			else if(amount[v[i]]>=unit) G[u[i]].push_back(v[i]);
			if(amount[v[i]]<unit) G[v[i]].push_back(u[i]);
			else if(amount[u[i]]>=unit) G[v[i]].push_back(u[i]);
		}
		int q,com,a,b;
		scanf("%d",&q);
		while(q--){
			scanf("%d",&com);
			if(com==0) 
			{
				scanf("%d%d",&a,&b);
				update(a-1,b);
			}
			else{
				scanf("%d",&a);
				printf("%d\n",query(a-1,unit));
			}	 
		}
	}
	return 0;
}
