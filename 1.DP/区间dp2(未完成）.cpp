/*HDU - 4283  */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#define INF 100000000
#define MAXNUM 1010
#define pi 3.1415926

using namespace std;
int dia[MAXNUM];
int dp[MAXNUM][MAXNUM];
int sum[MAXNUM];

void solve(int len)
{
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			dp[i][j]=INF;
		}
	}
	
	for(int k=1;k<len;k++){
		for(int i=0;i+k<len;i++){
			int j=k+i;
			for(int temp=1;temp+i<=j;temp++){
				dp[i][j]=min(dp[i][j],dp[i+1][temp+i-1]+dp[temp+i][j]+temp*(sum[j]-sum[temp+i-1])+dia[i]*(temp-1) );
				//dp[i][j]?=?min(dp[i][j],dp[i+1][i+k-1]+dp[i+k][j]+k*(sum[j]-sum[i+k-1])+a[i]*(k-1));??
			}
		}
	}
}

 
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&dia[i]);
		}
		/*处理前缀和*/
		sum[0]=dia[0];
		for(int i=1;i<n;i++){
			sum[i]=sum[i-1]+dia[i];
		}
		for(int i=0;i<n;i++){
			cout<<sum[i]<<" ";
		}
		solve(n);
		int ans=dp[0][n-1];
		printf("Case #%d: %d\n",T+1,ans);
		memset(dia,0,sizeof(dia));
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
