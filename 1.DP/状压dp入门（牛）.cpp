/*POJ-3254 Corn Fields*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<ctime>
#include<vector>
#include<cstdlib>
#define MAXN 1007
#define MAXM 18
#define EPS 0.0000000001
#define INF 100000000

using namespace std;
int dp[MAXN][1<<MAXM];
int f[MAXN];
int state[MAXN];
int k=0;

inline bool check(int i)
{
	if(i&(i<<1)) return false;
	return true;
}

inline bool check(int x,int y)
{
	if(x&y) return false;
	return true;
}


int main()
{
	int m,n,x;
	int num;
	memset(dp,0,sizeof(dp));
	memset(f,0,sizeof(f));
	memset(state,0,sizeof(state));
	int ans=0;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&num);
			if(num==0)
			f[i]+=(1<<(j-1));
		}
	} 
	for(int i=0;i<(1<<n);i++){
		if(check(i)) state[k++]=i;
		
    }
    for(int i=0;i<k;i++) cout<<state[i]<<" ";
    cout<<k<<" ";
	
	for(int i=0;i<k;i++){
		if(check(state[i],f[1])){
			dp[1][i]=1;
			cout<<"hi ";
		}
		
	}
	for(int i=2;i<=m;i++){
		for(int j=0;j<k;j++){
			if(!check(state[j],f[i])) continue;
			for(int kk=0;kk<k;kk++){
				//if(dp[i-1][kk]==-1) continue;
				if(!check(state[kk],f[i-1])) continue;
				if(!check(state[j],state[kk])) continue;
				dp[i][j]+=dp[i-1][kk];
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=0;j<k;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0;i<k;i++){
		ans+=dp[m][i];
	}
	printf("%d\n",ans);
	return 0;
}

