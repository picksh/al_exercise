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
int num[MAXNUM][MAXNUM];
 
int main()
{
	freopen("a.txt","r",stdin);
	int T,m,n,x,y;
	scanf("%d",&T);
	while(T--){
		memset(num,0,sizeof(num));
		int t;
		scanf("%d%d%d%d",&m,&n,&x,&y);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				//scanf("%d",&num[i][j]);
				scanf("%d",&t);
				num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+t;
			}
		}
			int ans=0;
			for(int i=x;i<=m;i++){
				for(int j=y;j<=n;j++){
					ans=max(ans,num[i][j]-num[i-x][j]-num[i][j-y]+num[i-x][j-y]);
				}
		    }
		printf("%d\n",ans);
		}
	return 0;
}
