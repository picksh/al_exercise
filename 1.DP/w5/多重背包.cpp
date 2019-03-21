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
int price[MAXNUM];
int num[MAXNUM];
int dp[MAXNUM];

void completepack(int p,int c,int n)
{
	for(int i=p;i<=n;i++){
		dp[i]=max(dp[i],dp[i-p]+c);
	}
}

void zeropack(int p,int c,int n)
{
	for(int i=n;i>=p;i--){
		dp[i]=max(dp[i],dp[i-p]+c);
	}
}

int main()
{
	int T,m,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&m,&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&price[i],&weight[i],&num[i]);
		}
		for(int i=1;i<=n;i++){
			if(num[i]*price[i]>m){
				completepack(price[i],num[i],m);
			}else{
				//把第i件物品拆分 
				int k=1;
				int temp=num[i];
				while(k<temp){
					//zeropack(price[i],num[i],m);
					zeropack(k*price[i],k*num[i],m);
					temp-=k;
					k<<=1;
				}
				zeropack(temp*price[i],temp*num[i],m);//最后还要。。 
			}
		}
		printf("%d\n",dp[m]);
		memset(dp,0,sizeof(dp));//一定要memset!! 
	}
	return 0;
}
