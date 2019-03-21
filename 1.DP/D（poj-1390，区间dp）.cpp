/*poj-1390*/ 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
#define ll long long
#define mode 1000000007
#define MAXN  1007
#define INF 100000000
#define EPS 0.000000001

using namespace std;
int col[MAXN];
int len[MAXN];
int dp[MAXN][MAXN][MAXN];


int getans(int x,int y,int z)
{
	if(dp[x][y][z]) return;
	if(x==y) return dp[x][y][0];
	for(int i=0;i<y;i++){
		dp[x][y][z]=max(dp[x][y-1][0]+(len[y]+z)*(len[y]+z),dp[x][i][len[y]+z]+dp[i+1][y-1][0]);
	}
	return dp[x][y][z];

}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%d",&col[1]);
		len[1]=0;
		int l=1;
		int x;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x==col[l]) len[l]++;
			else{
				col[++l]=x;
				len[l]++;
			}
		}
		getans(1,1,0);
		
	}
}

