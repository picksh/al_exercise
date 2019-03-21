/*HDU - 4405   */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 100007
#define pi 3.1415926

using namespace std;
int x[MAXNUM];
int y[MAXNUM];
double dp[MAXNUM];
int vis[MAXNUM];

void solve(int n)
{
	for(int i=n-1;i>=0;i--){
		if(vis[i]==-1){
			for(int j=1;j<=6;j++)
				dp[i]+=dp[i+j]/6.0;
		     	dp[i]+=1;
		}else{
			dp[i]=dp[vis[i]];
		}
	}
}


int main()
{
	int m,n;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
		memset(vis,-1,sizeof(vis));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<m;i++){
			scanf("%d%d",&x[i],&y[i]);
			vis[x[i]]=y[i];
		}
		solve(n);
		double ans=dp[0];
		printf("%.4f\n",ans);
	}
	return 0;
}
