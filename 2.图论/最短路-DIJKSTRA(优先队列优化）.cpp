/*HDU - 2544 */

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
typedef pair<int,int> pil;

int head[MAXM*2];
int nextt[MAXM*2];
int vis[MAXN];
int dis[MAXN];
struct node{
	int v;
	int u;
	int w;
}e[2*MAXM];

void init(int n,int m)
{
	memset(head,-1,sizeof(head));
	memset(nextt,0,sizeof(nextt));
	memset(vis,0,sizeof(vis));
//	int cent=0;
    int a,b,c;
	for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			// 链式前向星保存图->这里用vector也可以，v[a-1].push_back(b-1),v[b-1].push_back(a-1),e[a-1].push_back(c) ....这样子 
			//这个地方全世界最坑！！一定要减一。或者你下标就从1开始。。 
			e[i].u=a-1;
			e[i].v=b-1;
			e[i].w=c;
			nextt[i]=head[e[i].u];
			head[e[i].u]=i;//或者=cent++; 这样好理解一点 
	    }
	    for(int i=0;i<m;i++){
	    	e[i+m].u=e[i].v;
	    	e[i+m].v=e[i].u;
	    	e[i+m].w=e[i].w;
	    	nextt[i+m]=head[e[i+m].u];
	    	head[e[i+m].u]=i+m;
			
		}
	dis[0]=0;
	for(int i=1;i<n;i++){
		dis[i]=INF;
	}
}

void dij(int n)
{
	
	//vis[1]=1;
	priority_queue<pil,vector<pil>,greater<pil> >q;
	q.push(make_pair(dis[0],0)); 
	while(!q.empty()){
		pil u=q.top();
		q.pop();
		int x=u.second;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i!=-1;i=nextt[i]){
			if(dis[e[i].v]>dis[x]+e[i].w){
				dis[e[i].v]=dis[x]+e[i].w;
				q.push(make_pair(dis[e[i].v],e[i].v));
			}
		}
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
		init(n,m);
		dij(n); 
		printf("%d\n",dis[n-1]);
	}
	return 0;
}
