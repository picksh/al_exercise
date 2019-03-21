#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#define INF 100000000
#define MAXNUM 10007
#define pi 3.1415926

using namespace std;
int num[MAXNUM];
int dp[MAXNUM];

int main()
{
	int k;
	while(scanf("%d",&k)!=EOF&&k!=0){
		int flag=0;
		for(int i=0;i<k;i++){
			scanf("%d",&num[i]);
			if(num[i]>=0) flag=1;
		}
		if(flag){
			int left=num[0];
			int fleft=num[0];
			int right=num[k-1];
			int fright=num[k-1];
			dp[0]=num[0];
			int ans=dp[0];
		    for(int i=1;i<k;i++){
		    	if(dp[i-1]>0){
		    		dp[i]=dp[i-1]+num[i];
				}else{
					dp[i]=num[i];
					left=num[i];
				}
	    	if(dp[i]>ans){
	    		ans=dp[i];
	    		fleft=left;
	    		fright=num[i];
			}
		    }
	    	printf("%d %d %d\n",ans,fleft,fright);	
	    }else printf("0 %d %d\n",num[0],num[k-1]);
		memset(dp,0,sizeof(dp));
	}
}
