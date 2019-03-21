#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#define INF 100000000
#define MAXNUM 25555555
#define pi 3.1415926

using namespace std;
int weight[MAXNUM];
int p[MAXNUM];
int dp[MAXNUM];

int main()
{
	int T,n,E,F;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&E,&F);
		int amount=F-E;
		for(int i=1;i<=amount;i++){
			dp[i]=INF;
		}
	//	int temp=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i],&weight[i]);
		}
	//	if(temp<amount)printf("This is impossible.\n");
	//	else{
		for(int i=0;i<n;i++){
			for(int j=weight[i];j<=amount;j++){
					dp[j]=min(dp[j-weight[i]]+p[i],dp[j]);
			}
		}
		if(dp[amount]==INF) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[amount]);
//	}
}
	return 0;
}
