#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#define INF 100000000
#define MAXNUM 1007
#define pi 3.1415926

using namespace std;
long long value[MAXNUM];
long long volume[MAXNUM];
long long dp[MAXNUM];

int main()
{
	int T,N,V;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&V);
		for(int i=1;i<=N;i++){
			scanf("%d",&value[i]);
		}
		for(int i=1;i<=N;i++){
			scanf("%d",&volume[i]);
		}
		for(int i=1;i<=N;i++){
			for(int j=V;j>=volume[i];j--){
					dp[j]=max(dp[j-volume[i]]+value[i],dp[j]);
			}
		}
		printf("%d\n",dp[V]);
		memset(dp,0,sizeof(dp));
	} 
	return 0;
}
