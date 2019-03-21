/*HDU - 4405   */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXN 107
#define MAXM 10007
#define pi 3.1415926

using namespace std;
//struct{
//	int to;
//	int po;
//}v[MAXNUM];
int vis[MAXN];
int mapl[MAXN][MAXN];
int dis[MAXN];

void init(int n,int m)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mapl[i][j]=INF;
		}
	}
	int a,b,c;
	for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			//ÁÚ½Ó¾ØÕó±£´æÍ¼ 
			mapl[a-1][b-1]=mapl[b-1][a-1]=c;
	}
	for(int i=0;i<n;i++){
		dis[i]=mapl[0][i];
	}
	
}

void dij(int n)
{
	dis[0]=0;
	vis[0]=1;
	for(int i=1;i<n;i++){
		int min=INF,temp;
		for(int j=0;j<n;j++){
			if(vis[j]==0&&dis[j]<min){
				temp=j;
				min=dis[j];
			}
		}
		vis[temp]=1;
		for(int j=1;j<n;j++){
			if(dis[j]>dis[temp]+mapl[temp][j]){
				dis[j]=dis[temp]+mapl[temp][j];
			}
		}
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
		int a,b,c;
		init(n,m);
		dij(n); 
		printf("%d\n",dis[n-1]);
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
