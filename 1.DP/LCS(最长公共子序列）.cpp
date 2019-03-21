/*HDU-1159 LCS问题 
*/

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
char a[MAXNUM];
char b[MAXNUM];
int dp[MAXNUM][MAXNUM];

void lcs(int len1,int len2)
{
	
	/*这样子好理解一点。。*/ 
	int maxlen=max(len1,len2);
	for(int i=0;i<=maxlen;i++){
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			if(a[i]==b[j]){
				dp[i+1][j+1]=dp[i][j]+1;
			}else{
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]); 
			}
		}
	}

   /*别人的初始化*/ 
   
//    for(int i=0;i<len1;i++){
//    	for(int j=0;j<len2;j++){
//    		if(i==0||j==0){
//    			if(a[i]==b[j])dp[i][j]=1;
//    			else{
//    				if(i==0&&j==0)dp[i][j]=0;
//    				else{
//    					i==0?dp[i][j]=dp[i][j-1]:dp[i][j]=dp[i-1][j];
//					}
//				}
             /*对其他的处理*/ 
//			}else{
//				if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
//				else{
//					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//				}
//			}
//		}
//	}
}

int main()
{
	while(scanf("%s%s",a,b)!=EOF){
		int len1=strlen(a);
    	int len2=strlen(b);
		lcs(len1,len2);
		int ans=dp[len1][len2];
		printf("%d\n",ans);
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	return 0;
}
